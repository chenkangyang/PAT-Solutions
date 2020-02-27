/*
 * @Description: 话费账单, 统计的有点烦躁
 * vecotr<node> data(n);
 * map<name, vector<node>>
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-06 12:51:14
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 14:17:41
 */

#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
int rate [24], n;
struct node {
    string name;
    int status, month, day, hour, minute;
};
bool cmp1 (node a, node b) {
    if (a.name != b.name) {
        return a.name > b.name;
    } else if (a.day != b.day) {
        return a.day < b.day;
    } else if (a.hour != b.hour)
    {
        return a.hour < b.hour;
    } else 
    {
        return a.minute < b.minute;
    }
}

int computeLastTime (node start, node end) {
    int start_time = start.day * 24*60 + start.hour * 60 + start.minute;
    int end_time = end.day * 24*60 + end.hour * 60 + end.minute;
    return end_time - start_time;
}

double computeBill (node start, node end) {
    // 都分别与当月第一天做差
    int day_rate = 0;
    for (int i = 0; i < 24; i++)
    {
        day_rate += rate[i];
    }
    double start_whole_day_bill = start.day * 60 * day_rate * 0.01;
    double start_one_day_bill = 0;
    for (int i = 0; i < start.hour; i++)
    {
        start_one_day_bill += 60*0.01*rate[i];
    }
    start_one_day_bill += start.minute * rate[start.hour] * 0.01;
    double start_bill = start_whole_day_bill + start_one_day_bill;

    double end_whole_day_bill = end.day * 60 * day_rate * 0.01;
    double end_one_day_bill = 0;
    for (int i = 0; i < end.hour; i++)
    {
        end_one_day_bill += 60*0.01*rate[i];
    }
    end_one_day_bill += end.minute * rate[end.hour] * 0.01;
    
    double end_bill = end_whole_day_bill + end_one_day_bill;
    return end_bill - start_bill;
}

int main () {
    for (int i = 0; i < 24; i++)
    {
        cin >> rate[i];
    }
    cin >> n;
    vector<node> data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d",&data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
        string temp;
        cin >> temp;
        data[i].status = (temp == "on-line"?  1 : 0);
    }
    sort(data.begin(), data.end(), cmp1);
    map<string, vector<node> > bill;
    for (int i = 0; i < n-1; i++)
    {
        if (data[i].name == data[i+1].name)
        {
            if (data[i].status == 1 && data[i+1].status == 0)
            {
                bill[data[i].name].push_back(data[i]);
                bill[data[i].name].push_back(data[i+1]);
            }
        }
    }
    for (auto it = bill.begin(); it != bill.end(); it++)
    {
        cout << it->first;
        vector<node> records = it->second;
        printf(" %02d\n", records[0].month);        
        double total_bill = 0;    

        for (int i = 0; i < records.size(); i+=2)
        {
            printf("%02d:%02d:%02d %02d:%02d:%02d ", records[i].day, records[i].hour, records[i].minute, records[i+1].day, records[i+1].hour, records[i+1].minute);
            double bill = computeBill(records[i], records[i+1]);
            printf("%d $%.2lf\n", computeLastTime(records[i], records[i+1]), bill);
            total_bill += bill;
        }
        printf("Total amount: $%.2lf\n", total_bill);
    }
    
    return 0;
}
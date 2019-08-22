//
// Created by 陈康扬 on 2019-03-18.
// 字符串处理

#include <iostream>
using namespace std;

int main(){
    char numChar[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    char a[101];
    cin >> a;
    int sum = 0, i = 0;
    while (a[i] != '\0') {
        sum += a[i] - '0';
        i ++;
    }

    if (sum == 0)
    {
        cout<<numChar[sum];
        return 0;
    }
    int b[11]; // 各位数字
    int j = 0;
    while (sum != 0) {
        b[j] = sum%10;
        sum = sum/10;
        j++;
    }
    for (int i = j-1; i > 0; i--){
        cout << numChar[b[i]] << " ";
    }
    cout << numChar[b[0]]<<endl;
    return 0;
}
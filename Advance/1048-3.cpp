/*
 * @Description: MAP
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-04 23:11:05
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-05 19:00:10
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main () {
    int n,m;
    cin >> n >> m;
    vector<int> coins(n);
    map<int, int> record;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        record[coins[i]] ++;
    }
    int flag = 0;
    sort(coins.begin(), coins.end());
    for (int i = 0; i < n; i++) {
        record[coins[i]]--; // 试解
        if (record[m-coins[i]]!=0) {
            flag = 1;
            printf("%d %d", coins[i], m - coins[i]);
            break;
        }
        record[coins[i]]++;
    }
    if (!flag)  printf("No Solution");
    return 0;
}


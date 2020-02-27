/*
 * @Description: 翻转链表
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-06 21:05:09
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 21:51:37
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int main () {
    int first, n, m, k, cnt = 0;
    cin >> first >> n >> k;
    int temp, data[MAXN], next[MAXN], list[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    int p = first;
    while (p != -1)
    {
        list[cnt++] = p;
        p = next[p];
    }
    for (int i = 0; i < cnt - cnt%k; i+=k)
    {
        reverse(begin(list) + i, begin(list) + i + k);
    }
    for (int i = 0; i < cnt-1; i++)
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
    printf("%05d %d -1\n", list[cnt-1], data[list[cnt-1]]);
    return 0;
}
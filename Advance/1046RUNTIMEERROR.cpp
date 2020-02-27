/*
 * @Description: 圈上两节点的最短距离, 超时了, 需要预存1号节点到第i号节点的距离, 减少查询开销
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-26 23:27:06
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-27 00:22:27
 */

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int cir[MAXN];

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n, query, s, t; // n段线, query次查询, s:起点, t:终点
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cir[i]);
        sum += cir[i];
    }
    scanf("%d", &query);
    for (int i = 0; i < query; i++)
    {
        scanf("%d %d", &s, &t);
        int length = 0, p; // length: 顺时针, 逆时针用sum-length即可下标指针p
        if (s > t) 
        {
            swap(s, t);

        } else if (s==t)
        {
            printf("0\n");
            continue;
        }
        
        // 顺时针更新
        int cnt = t-s; // 取的线段个数
        for (p = s; p <= s+cnt-1; p++)
        {
            // printf("cir[%d] ", p);
            length += cir[p];
        }
        printf("%d\n", min(length, sum-length));
    }
    return 0;
}
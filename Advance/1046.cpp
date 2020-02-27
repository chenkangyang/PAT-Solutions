/*
 * @Description: 圈上两节点的最短距离, 预存1号节点到第i号节点的距离, 减少查询开销
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-26 23:27:06
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-27 00:37:33
 */

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int cir[MAXN];
int dis[MAXN]; // dis[i]=1号节点按顺时针方向到达"i号节点顺时针方向的下一个节点"的距离

int main() {
    int n, query, s, t; // n段线, query次查询, s:起点, t:终点
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cir[i]);
        sum += cir[i];
        dis[i] = sum; // 预处理dis 数组
    }
    scanf("%d", &query);
    for (int i = 0; i < query; i++)
    {
        scanf("%d %d", &s, &t);
        if (s > t) 
        {
            swap(s, t);

        } else if (s==t)
        {
            printf("0\n");
            continue;
        }
        int temp = dis[t-1] - dis[s-1];
        printf("%d\n", min(temp, sum-temp));
    }
    return 0;
}
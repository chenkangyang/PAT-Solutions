/*
 * @Description: 单源最短路径
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-22 21:15:42
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-22 22:09:32
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
const int MAXV = 500;
// 邻接矩阵, 最短路径, 最短路径个数, 点权, 点权重
int G[MAXV][MAXV], d[MAXV], num[MAXV], w[MAXV], weight[MAXV];
bool vis[MAXV] = {false};
int n, m, c1, c2; // 节点数, 边数, 起点, 终点

void find_path(int s)
{
    // 初始化
    fill(d, d + MAXV, INF);   // 使得路径最小
    fill(w, w + MAXV, 0);     // 使得点权最大
    fill(num, num + MAXV, 0); // 最短路径的条数
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < n; i++) // 遍历每个点
    {
        int u = -1;
        int MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && d[j] < MIN)
            {
                u = j;
                MIN = d[u];
            }
        }
        // 得到中介点u
        vis[u] = true;
        if (u == -1)
            return;
        // 优化从u到v
        for (int v = 0; v < n; v++)
        {
            // v 未被访问, uv连通, 新增边权后能更短
            if (!vis[v] && G[u][v] != INF && d[u] + G[u][v] < d[v])
            {
                d[v] = d[u] + G[u][v];
                w[v] = w[u] + weight[v];
                num[v] = num[u];
            }
            else if (d[u] + G[u][v] == d[v]) // 统计距离相同的路径数目
            {
                if (w[u] + weight[v] > w[v]) {
                    w[v] = w[u] + weight[v];
                }
                num[v] += num[u];
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    int u, v, path_w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &path_w);
        G[u][v] = path_w;
        G[v][u] = G[u][v]; // 无向边!!!!! 别忘了
    }
    find_path(c1);                                           // 找c1到其余所有点的最短路径
    int min_path_length = INF, min_path_num = 0, max_weight; // 最短路径数目, 点权总和最大的

    printf("%d %d\n", num[c2], w[c2]);
    return 0;
}
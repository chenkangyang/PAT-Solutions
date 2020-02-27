/*
 * @Description: 单源最短路径
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-22 21:15:42
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-05 20:39:02
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 100000000;

int n, m, c1, c2, weight[MAXN], G[MAXN][MAXN], d[MAXN], vis[MAXN];
vector<int> pre[MAXN]; // 最短路径上的前驱节点
vector<int> optPath;
vector<int> tempPath;

int optValue = -1; // 最大的总点权
int optPathNums = 0;

void Djisktra(int s) { //
    // 初始化
    fill(d, d + MAXN, INF);
    fill(vis, vis + MAXN, 0);
    d[s] = 0;
    // 找到距离起点最近的中间点u
    for (int i = 0; i < n; i++)
    {
        int min  = INF;
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        vis[u] = 1;
        if (u == -1) return;
        for (int v = 0; v < n; v++)
        {
            if(vis[v] == 0 && G[u][v] != INF &&  d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            } else if (d[u] + G[u][v] == d[v]) {
                pre[v].push_back(u);
            }
        }
    }
}

void DFS(int v) { // 输入终点, 更新路径
    // printf("%d\n", v);
    if (v == c1)
    {
        optPathNums++;
        tempPath.push_back(v);
        int value = 0; // 使路径上的总点权最大
        for (int i = 0; i < tempPath.size(); i++)
        {
            int index = tempPath[i];
            // printf("%d ", index);
            value += weight[index];
        }
        if (value > optValue)
        {
            optValue = value;
            optPath = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) // 遍历分支
    {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    fill(G[0], G[0]+MAXN*MAXN, INF);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    int u, v, path_w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &path_w);
        G[u][v] = path_w;
        G[v][u] = G[u][v];
    }
    Djisktra(c1);
    DFS(c2);
    printf("%d %d", optPathNums, optValue);
    return 0;
}
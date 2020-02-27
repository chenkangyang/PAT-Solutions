/*
 * @Description: Dijkstra + DFS
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-23 20:10:18
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 18:28:31
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 510;
const int INF = 1000000000;

int G[MAXV][MAXV], d[MAXV], V[MAXV][MAXV], vis[MAXV] = {false}; // G: 边长度, d: 最短路径长度, V: 边开销
vector<int> pre[MAXV]; // 可能的前驱节点
int n, m, c1, c2;

void Dijkstra(int s) {
    fill(d, d+MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        int min = INF;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && d[j] < min)
            {
                u = j;
                min = d[u];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && d[u] + G[u][v] < d[v])
            {
                d[v] = d[u] + G[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            } else if (d[u] + G[u][v] == d[v])
            {
                pre[v].push_back(u);
            }
        }
    }
}

int minCost = INF;
vector<int> path; // 最优路径
vector<int> tempPath; // 临时路径

// DFS前驱节点, 找到最短路径
void DFS(int v) {
    if (v == c1) // 遍历到起点, 更新开销, 开始回溯
    {
        tempPath.push_back(v);
        int cost = 0;
        for (int i = tempPath.size()-1; i > 0; i--)
        {
            int cur = tempPath[i], next = tempPath[i-1];
            cost += V[cur][next];
        }
        if (cost < minCost) 
        {
            minCost = cost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++)
    {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    fill(G[0], G[0] + MAXV * MAXV, INF);
    fill(V[0], V[0] + MAXV * MAXV, INF);
    for (int i = 0; i < m; i++) // 节点从0编号
    {
        int u, v, l, c;
        scanf("%d%d%d%d", &u, &v, &l, &c);
        G[u][v] = G[v][u] = l;
        V[u][v] = V[v][u] = c;
    }
    Dijkstra(c1);
    DFS(c2);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        printf("%d ", path[i]);
    }
    printf("%d ", d[c2]);
    printf("%d", minCost);
    return 0;
    
}
/*
 * @Description: Djiskra + DFS, 带回的时候是不调整的，去的路径上调整
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-29 19:39:37
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 20:17:10
 */


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 510; // 最大节点数
const int INF = 100000000;

int C_MAX, N, S_p, M; // 节点最大容量，节点数目，有问题的点，路径数目
int G[MAXN][MAXN], W[MAXN], d[MAXN], vis[MAXN]; // 边权，点权, 最短路径, 是否访问过
vector<int> pre[MAXN], path, tempPath; // 可能的前驱节点, 最优路径，暂存路径

int min_output = INF, min_back = INF; // 输出数量，收回数量

void Dijkstra(int s) { // 起点
    // 初始化
    fill(d, d+MAXN, INF);
    fill(vis, vis+MAXN, 0);
    d[s] = 0;
    for (int i = 0; i <= N; i++) // 遍历邻结点
    {
        // 找最小的d[u]
        int u = -1, min = INF;
        for (int j = 0; j <= N; j++)
        {
            if (vis[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        // 已找到最小的v
        vis[u] = 1;
        for (int v = 0; v <= N; v++)
        {
            if (vis[v] == 0 && G[u][v] != INF)
            {
                if (d[u] + G[u][v] < d[v])
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
}

void DFS(int S_p) { // 对pre进行DFS
    int half = C_MAX/2;
    int s = S_p;
    // 边界
    if (s == 0)
    {
        int need = 0, cache = 0; // 需求数，收回数
        for (int i = tempPath.size() - 1; i >= 0 ; i--)
        {
            int id = tempPath[i];
            // printf("id: %d W:%d\n", id, W[id]);
            if (W[id] > half) // 多的存入缓存区域
            {
                cache += (W[id]-half);
            }
            else 
            {
                // 先看cache能否满足
                if (cache > (half - W[id]))
                {
                    cache -= (half - W[id]);
                }
                else {
                    need += (half - W[id]) - cache;
                    cache = 0;
                }
            }
            // printf("need:%d, back:%d\n", need, cache);
        }
        if (need < min_output) {
            min_output = need;
            min_back = cache;
            path = tempPath;
        } else if (need == min_output && cache < min_output)
        {
            min_back = cache;
            path = tempPath;
        }
        return;
    }

    // 递归
    tempPath.push_back(s);
    for (int i = 0; i < pre[s].size(); i++)
    {
        DFS(pre[s][i]);
    }
    tempPath.pop_back();
}

int main () {
    scanf("%d%d%d%d", &C_MAX, &N, &S_p, &M);
    fill(G[0], G[0]+MAXN*MAXN, INF);
    for (int i = 1; i <= N; i++) // 输入点权
    {
        scanf("%d", &W[i]);
    }
    for (int i = 0; i < M; i++) // 输入边权
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = G[v][u] = w;
    }
    Dijkstra(0);
    // printf("d[4]:%d\n", d[4]);
    DFS(S_p);
    printf("%d 0", min_output);
    for(int i = path.size() - 1; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", min_back);
    return 0;
}
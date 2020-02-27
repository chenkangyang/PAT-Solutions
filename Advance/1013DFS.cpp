/*
 * @Description: 查询K次: 在无向图中删除某个节点后需要增加多少条边才能使图连通
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-01 20:04:50
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-01 20:52:41
 */

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 1010;
vector<int> G[MAXN];
bool vis[MAXN] = {false};


int currentPoint; // 当前需要删除的节点号

// 遍历顶点v所在的联通块
void dfs(int v) {
    if (v == currentPoint) return; // 不必真的删除节点, 不让这个节点被访问到就行了
    vis[v] = true;
    for (unsigned int i = 0; i < G[v].size(); i++)
    {
        if (vis[G[v][i]] == false)
        {
            dfs(G[v][i]);
        }
    }
}

int main () {
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int q = 0; q < k; q++)
    {
        scanf("%d", &currentPoint);
        // 每次查询之前初始化
        memset(vis, false, sizeof(vis));
        int block = 0; // 联通块的个数
        for (int i = 1; i <= n; i++)
        {
            // 当前节点未访问过, 且不同于查询节点, 则DFS其连通域, block++
            if (i != currentPoint && vis[i] == false)
            {
                dfs(i);
                block ++;
            }
        }
        // 添加的边数 = 连通块的数目-1
        printf("%d\n", block-1);
    }
    return 0;
}
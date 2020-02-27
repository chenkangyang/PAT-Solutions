/*
 * @Description: 查询K次: 在无向图中删除某个节点后需要增加多少条边才能使图连通
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-01 20:04:50
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-01 20:50:50
 */

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 1010;
vector<int> G[MAXN];
int father[MAXN];
bool vis[MAXN];

int findFather(int x) {
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    
    // 路径压缩
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union (int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
    {
        father[faA] = faB;
    }
}

void init() { // 每次查询前都要初始化
    for (int i = 1; i < MAXN; i++)
    {
        father[i] = i;
        vis[i] = false;
    }
}

int main () {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int currentPoint;

    for (int q = 0; q < k; q++)
    {
        scanf("%d", &currentPoint);
        init();
        // 遍历所有边, 若两端点中有等于查询点的(continue), 否则, 合并
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < G[i].size(); j++)
            {
                int u = i, v = G[i][j];
                if (u == currentPoint || v == currentPoint) continue;
                Union(u,v);                                
            }
        }
        int block = 0; // 连通数 = 集合数量
        for (int i = 1; i <= n; i++)
        {
            if (i == currentPoint) continue;
            int fa_i = findFather(i);
            if (vis[fa_i] == false) {
                block ++;
                vis[fa_i] = true;
            }
        }
        printf("%d\n", block - 1);
        
    }
    
    return 0;
}
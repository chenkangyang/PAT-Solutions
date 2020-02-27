/*
 * @Description: 连通, 边数为N-1的图一定是一棵树, 判断哪些节点作为根时能够使得树的深度最深
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-01 21:00:59
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 21:27:51
 */
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
vector<int> G[MAXN], temp;
int maxheight = 0;
bool vis[MAXN] = {false};
set<int> s; // 正向以及反向搜索的最深节点并集
/* 如果是单联通，就两次深度优先搜索，
 * 先从一个结点dfs后保留最高高度拥有的结点们，
 * 然后从这些结点中的其中任意一个开始dfs得到最高高度的结点们，
 * 这两个结点集合的并集就是所求
*/

// DFS: 经过节点置为1, 更新能到达最大深度的节点们: temp
void dfs(int v, int height) {
    
    if (height > maxheight) {
        temp.clear();
        temp.push_back(v);
        maxheight = height;
    } else if (height == maxheight) {
        temp.push_back(v);
    }
    vis[v] = true;
    for (unsigned int i = 0; i < G[v].size(); i++)
    {
        if (vis[G[v][i]] == false)
        {
            dfs(G[v][i], height + 1);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n -1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int block = 0, s1; // s1: 具有最大深度的节点中的任意一个
    for (int i = 1; i <= n; i++)
    {
        // 以各节点作为树根时, 的最大深度
        if(vis[i] == false) {
            dfs(i, 1);
            if (i == 1) {
                if (temp.size() != 0) s1 = temp[0]; // 不妨令起点为temp[0]
                for (unsigned int j = 0; j < temp.size(); j++) {
                    s.insert(temp[j]); // 添加进正反dfs的最深节点的并集
                }
            }
            block ++; // 对图中的每个节点不重复的dfs一次, 次数为连通块的数目
        }
    }
    if(block > 1) printf("Error: %d components\n", block);
    else {
        temp.clear();
        maxheight = 0;
        fill(vis, vis + MAXN, false);
        dfs(s1, 1);
        for (unsigned int i = 0; i < temp.size(); i++) {
            s.insert(temp[i]);
        }
        // 输出结果
        for (auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}
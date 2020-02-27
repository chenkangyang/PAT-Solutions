/*
 * @Description: 输出树(不是二叉树)每层叶子节点的个数, BFS, 用邻接表存储
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-31 20:50:25
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-31 23:13:40
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 110;
vector<int> G[MAXN];
int layer_num[MAXN] = {0};
int h[MAXN] = {0}; // 各节点所处的层号, 从1开始
int max_h = 0; // 最大深度

void BFS(int index) {
    queue<int> q;
    q.push(index);
    while (!q.empty())
    {
        // 队首出栈
        int now = q.front();
        q.pop();
        max_h = max(h[now], max_h); // 更新最大深度
        if (G[now].size()) { // 有孩子存在
            layer_num[h[now]]++;
        }
        // 孩子入栈, 更新孩子深度
        for (int i = 0; i < G[now].size(); i++)
        {
            h[G[now][i]] = h[now] + 1; // 
            q.push(G[now][i]);
        }
    }
}

int main () {
    int n, m, parent, child, k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &parent, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            G[parent].push_back(child);
        }
    }
    BFS(1);
    for (int i = 0; i <= max_h; i++)
    {
        printf("%d", layer_num[i]);
        if (i != max_h) printf(" ");
    }
    
    return 0;
}
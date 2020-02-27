/*
 * @Description: 输出树(不是二叉树)每层叶子节点的个数, DFS, 用邻接表存储
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-31 20:50:25
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-31 22:51:42
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 110;

vector<int> G[MAXN];
int layer_num[MAXN] = {0}; // 存放每层中的叶子节点个数
int max_h = 1; // 树的深度


void DFS(int index, int h) {
    max_h = max(h, max_h);
    if (G[index].size () == 0)
    {
        layer_num[h] ++;
        return;
    }
    // 递归所有点
    for (int i = 0; i < G[index].size(); i++)
    {
        DFS(G[index][i], h+1);
    }
}

int main () {
    int n, m, parent, child, k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) // 输入每个非叶子节点的孩子的编号
    {
        scanf("%d %d", &parent, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            G[parent].push_back(child);
        }
    }
    DFS(1,1);
    
    for (int i = 1; i <= max_h; i++)
    {
        printf("%d", layer_num[i]);
        if (i != max_h) printf(" ");
    }
    return 0;
}
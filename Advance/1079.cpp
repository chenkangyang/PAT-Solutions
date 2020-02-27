/*
 * @Description: 统计每个叶节点的高度
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-06 18:06:48
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 18:27:36
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 100010;
const int INF = 100000000;

vector<int> tree[MAXN];
int n, leaf[MAXN], leafHeight[MAXN];
double p, r;

void DFS(int index, int height) {
    if (leaf[index] != INF)
    {
        leafHeight[index] = height;
        return;
    }
    for (int i = 0; i < tree[index].size(); i++)
    {
        DFS(tree[index][i], height + 1);
    }
}
int main () {
    scanf("%d %lf %lf", &n, &p, &r);
    int k, child, leaf_weight;
    fill(leaf, leaf + n, INF);
    fill(leafHeight, leafHeight + n, INF);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k != 0)
        {
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &child);
                tree[i].push_back(child);
            }
        } else
        {
            scanf("%d", &leaf[i]);
        }
    }
    DFS(0, 0);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (leaf[i] != INF)
        {
            sum += p * leaf[i] *pow(1+0.01*r, leafHeight[i]);
        }
    }
    printf("%.1lf", sum);
    return 0;
}


/*
 * @Description: 打印路径之和等于给定的数, 输出时按权值排序, 在读入孩子之后按权值从大到小排序
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-06 15:02:00
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 15:57:02
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 101;
vector<int> tree[MAXN];
vector<int> path[MAXN];
vector<int> tempPath;


int n, m, target, w[MAXN], cnt = 0;

bool cmp1 (int a, int b) {
    return w[a] > w[b];
}
void DFS(int index, int sum) {
    // printf("DFS: index:%d, sum%d\n",index, sum);
    if (sum > target) return;
    
    if (sum == target && tree[index].size() == 0)
    {
        tempPath.push_back(index);
        path[cnt++] = tempPath;
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(index);
    for (int i = 0; i < tree[index].size(); i++)
    {
        DFS(tree[index][i], sum + w[tree[index][i]]);
    }
    tempPath.pop_back();
}

int main () {
    scanf("%d %d %d", &n, &m, &target);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int ID, K, child;
        scanf("%d %d", &ID, &K);
        for (int j = 0; j < K; j++)
        {
            scanf("%d", &child);
            tree[ID].push_back(child);
        }
        sort(tree[ID].begin(), tree[ID].end(), cmp1); // 读入时就按权值排序
    }
    DFS(0, w[0]);
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < path[i].size(); j++)
        {
            // weight_path[i][j] = w[path[i][j]];
            // printf("%d",  weight_path[i][j]);
            printf("%d",  w[path[i][j]]);
            if (j != path[i].size() - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
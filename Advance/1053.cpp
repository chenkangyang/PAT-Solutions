/*
 * @Description: 寻找与给定的和相同的路径
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-19 22:35:32
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-21 22:51:59
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 110;
struct nore {
    int weight;
    vector<int> child; // 存放所有孩子的编号
}Node[MAXN];

bool cmp (int a, int b) {
    return Node[a].weight > Node[b].weight; // 按节点权重递减将所有的编号排序
}

int n, m, S; // 节点个数, 非叶节点个数, 给定的权重之和
int path[MAXN]; // 路径上的节点编号

// DFS（当前访问的节点编号，当前路径上的节点个数（递归层数），当前路径上的权重总和）
void DFS(int index, int numNode, int sum) { 
    if (sum > S)    return;
    
    if (sum == S)
    {
        if (!Node[index].child.empty()) return; // 存在孩子节点, 返回
        for (int i = 0; i < numNode; i++) // 到达叶子节点, 输出
        {
            printf("%d", Node[path[i]].weight);
            if (i < numNode - 1) printf(" ");
            else printf("\n");
        }
        return; // 别忘了回溯!
    }
    // 枚举子节点
    for (int i = 0; i < Node[index].child.size(); i++)
    {
        int child = Node[index].child[i];
        path[numNode] = child;
        DFS(child, numNode + 1, sum + Node[child].weight);
    }
}

int main () {
    scanf("%d%d%d", &n, &m, &S);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Node[i].weight);
    }
    int id, k, child; // 节点编号, 孩子数, 孩子编号
    // 遍历每个非叶子节点, 建立树
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }
    path[0] = 0; // 路径的第一个节点设置为0
    DFS(0, 1, Node[0].weight);
    return 0;
}
/*
 * @Description: 输出完全BST树的层序遍历结果
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-06 16:13:52
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 16:46:04
 */

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
int CBT[MAXN], input[MAXN];
int n, idx=0; // 节点数, 当前节点数

void inOrder(int root) {
    if (root > n)   return; // 终止条件
    inOrder(root*2); // 左
    CBT[root] = input[idx++]; // 插入
    inOrder(root*2 + 1); // 右
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    sort(input, input + n); // 递增
    inOrder(1);
    for (int i = 1; i <= n; i++)
    {
        printf("%d", CBT[i]);
        if (i != n)
        {
            printf(" ");
        }
    }
    return 0;
}
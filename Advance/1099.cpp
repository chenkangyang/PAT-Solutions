/*
 * @Description: BST建立后, 再层序遍历
 * 用结构体数组建立数, 左右孩子存索引而不是存指针 (相当于静态链表了)
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-06 20:25:09
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 20:52:31
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 101;
int n, w[MAXN], num = 0;
struct node {
    int index, left_index, right_index, data;
}tree[MAXN];

// 中序插入
void inOrder_insert (int root) {
    if (root == -1) return;
    inOrder_insert(tree[root].left_index);
    tree[root].data = w[num++];
    inOrder_insert(tree[root].right_index);
}

void bfs(int root) {
    queue<int> q;
    q.push(root);
    num = 0;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        printf("%d", tree[top].data);
        num ++;
        if (num < n) printf(" ");
        if (tree[top].left_index != -1) q.push(tree[top].left_index);
        if (tree[top].right_index != -1) q.push(tree[top].right_index);
    }
}

int main () {
    scanf("%d", &n);
    int left_index, right_index;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &tree[i].left_index, &tree[i].right_index);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    sort(w, w+n);
    inOrder_insert(0);
    bfs(0);
    return 0;
}
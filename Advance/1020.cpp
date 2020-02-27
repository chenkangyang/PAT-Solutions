/*
 * @Description: 根据后序和中序序列建立树, 并层次输出
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-18 22:48:06
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 20:08:01
 */
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 50;
int in[MAXN], post[MAXN], n; // 中序, 后序, 层序, 节点数

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* create (int in_L, int in_R, int post_L, int post_R) { // 递归
    if (post_L > post_R) return NULL; // 递归终止条件
    
    node *root = new node;
    root->data = post[post_R];
    int k; // 记录中序序列中的根节点的下标
    for (k = in_L; k <= in_R; k++)
    {
        if (in[k] == root->data) {
            break;
        }
    }

     // 由中序列左子树结点个数, 可在后序序列中划分出左右子树
    int numLeft = k - in_L;
    root->lchild = create(in_L, k -1, post_L, post_L + numLeft - 1);
    root->rchild = create(k+1, in_R, post_L + numLeft, post_R-1);
    return root;
}

int num = 0; // 已输出节点个数, 用于控制输出空格
void BFS(node *root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node *now = q.front();
        q.pop();
        num ++;
        printf("%d", now->data);
        if (num < n)
        {
            printf(" ");
        }
        if (now->lchild != NULL) q.push(now->lchild);
        if (now->rchild != NULL) q.push(now->rchild);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }
    node *root = create(0, n - 1, 0, n - 1); // 下标范围
    BFS(root);
    return 0;
}
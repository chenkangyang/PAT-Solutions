/*
 * @Description: 根据后序和中序序列建立树, 并层次输出
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-18 22:48:06
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-21 22:20:40
 */
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 50;
struct node {
    int data;
    node* lchild;
    node* rchild;
};

int pre[maxn], in[maxn], post[maxn];
int n;

// 当前二叉树后序区间为[postL, postR], 中序区间为[inL, inR]
// create函数返回构建出的二叉树的根节点
node* create(int postL, int postR, int inL, int inR) {
    // 在中序中找和后序中最后一个节点相同的
    if (postL > postR) return NULL;
    node *root = new node;
    root->data = post[postR];
    // printf("root[%d]: %d\n", postR, root->data);
    int k;
    for (k = inL; k <= inR; k++)
    {
        // printf("in[%d]:%d, post[%d]:%d\n", k, in[k], postR, post[postR]);
        if (in[k] == post[postR]) {
            break;
        }
    }
    // printf("break, k:%d\n", k);
    int numLeft = k - inL; // 左子树的节点个数
    // printf("numLeft:%d\n", numLeft);
    root->lchild = create(postL, postL + numLeft - 1, inL, k-1); // 递归!!!!
    root->rchild = create(postL + numLeft, postR-1, k+1, inR); // 递归!!!!
    return root;
}

int num = 0; // 已输出节点的个数
void BFS(node* root) {
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty())
    {
        node* now = Q.front(); // 取出队首元素
        Q.pop();
        printf("%d", now->data);
        num ++;
        if (num < n)
        {
            printf(" ");
        }
        if (now->lchild != NULL) Q.push(now->lchild);
        if (now->rchild != NULL) Q.push(now->rchild);
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
    node *root = create(0, n-1, 0, n-1);
    BFS(root);
    return 0;
}
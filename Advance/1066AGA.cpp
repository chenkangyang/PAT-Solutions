/*
 * @Description: 输出AVL树的根节点
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-20 21:17:00
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-20 21:44:59
 */
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn =20;

struct node {
    int v, height; // value, 子数高度
    node* lchild, *rchild;
};

int getHeight(node* root) {
    if (root == NULL) return 0;
    else return root->height;
}
node* newNode(int v) {
    node* Node = new node;
    Node->v = v;
    Node->lchild = Node->rchild = NULL;
    Node->height = 1;
    return Node;
}

void updateHeight(node* root) { // 更新树高
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) +1;
}

int getBalance(node* root) {
    if (root == NULL) return 0;
    else return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(node* &root) {
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root); // 别忘了!!!
    updateHeight(temp);
    root = temp;
}

void R(node* &root) {
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root); // 别忘了!!!
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int v) { // 传引用
    if (root == NULL)
    {
        root = newNode(v);
        return; // 回溯
    }
    if (v < root->v) // 向左子树插入, 并做旋转调整
    {
        insert(root->lchild, v);
        updateHeight(root);
        if (getBalance(root) == 2)
        {
            if (getBalance(root->lchild) == 1) // LL型
            {
                R(root);
            } else if (getBalance(root->lchild) == -1) // LR 型
            {
                L(root->lchild);
                R(root);
            }
        }
    } else
    {
        insert(root->rchild, v);
        updateHeight(root);
        if (getBalance(root) == -2)
        {
            if (getBalance(root->rchild) == -1) // RR型
            {
                L(root);
            } else if (getBalance(root->rchild) == 1) // RL型
            {
                R(root->rchild);
                L(root);
            }
        }
    }
}
int main() {
    int n, arr[maxn];
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        insert(root, arr[i]);
    }
    printf("%d", root->v);
    return 0;
}
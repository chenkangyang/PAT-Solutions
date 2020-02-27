/*
 * @Description: 判断是否是完全AVL树, 输入插入序列, 输出层序遍历结果, 判断是否是完全AVL数
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 13:59:53
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 15:20:08
 */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 100;

struct node {
    int v, h;
    node * l, *r;
}a[MAXN];

int geth(node* a) {
    if (a == NULL) return 0;
    else return a->h;
}
int getBalance(node* a) {
    return geth(a->l) - geth(a->r);
}
void updateHeight(node* a) {
    a->h = max(geth(a->l), geth(a->r)) + 1;
}

node* newNode(int v) {
    node* a = new node;
    a->v = v;
    a->l = a->r = NULL;
    a->h = 1;
    return a;
}

void L (node* &root) {
    node* temp = root->r;
    root->r = temp->l;
    temp->l = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void R (node* &root) {
    node* temp = root->l;
    root->l = temp->r;
    temp->r = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node*& root, int v) {
    if (root == NULL)   {
        root = newNode(v);
        return;
    }
    if (v > root->v)
    {
        insert(root->r, v);
        updateHeight(root);
        if (getBalance(root) == -2)
        {
            if (getBalance(root->r) == -1)
            {
                L(root);
            } else if (getBalance(root->r) == 1)
            {
                R(root->r);
                L(root);
            }
        }
    } 
    else {
        insert(root->l, v);
        updateHeight(root);
        if (getBalance(root) == 2)
        {
            if (getBalance(root->l) == 1)
            {
                R(root);
            } else if (getBalance(root->l) == -1)
            {
                L(root->l);
                R(root);
            }
        }
    }
}

vector<int> res;
int isComplete = 1, after = 0;
void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* now = q.front();
        q.pop();
        res.push_back(now->v);
        if (now->l != NULL) {
            // 上一节点无左或右孩子 (AVL balance不超过1, 层序时只要发现节点无左右孩子, 即可判定为完全二叉树)
            if (after == 1) isComplete = 0;
            q.push(now->l);
        }
        else {
            after = 1;
        }
        if (now->r != NULL) {
            if (after == 1) isComplete = 0;
            q.push(now->r);
        } else {
            after = 1;
        }
    }
}

int main () {
    int n, v;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v);
        insert(root, v);
    }
    bfs(root);
    for (int i = 0; i < res.size(); i++)
    {
        if (i!=0)
        {
            printf(" %d", res[i]);
        } else
        {
            printf("%d", res[i]);
        }
    }
    if (isComplete)
    {
        cout << "\nYES" << endl;
    } else
    {
        cout << "\nNO" << endl;
    }
    return 0;
}
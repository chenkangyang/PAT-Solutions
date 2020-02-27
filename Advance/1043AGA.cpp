/*
 * @Description: 给一组序列, 问是否是BST的先序或者镜像BST的先序序列, 正确则输出后序序列
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-20 20:20:43
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-04 23:08:31
 */
#include <cstdio>
#include <vector>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

void insert(node* &root, int data) {
    if (root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    else if (data < root->data)
    {
        insert(root->left, data);
    } else
    {
        insert(root->right, data);
    }
}

void preOrder(node* root, vector<int> &v) {
    if (root == NULL)   return;
    v.push_back(root->data);
    preOrder(root->left, v);
    preOrder(root->right, v);
}

void preOrderM(node* root, vector<int> &v) {
    if (root == NULL)   return;
    v.push_back(root->data);
    preOrderM(root->right, v);
    preOrderM(root->left, v);
}

void postOrder(node* root, vector<int> &v) {
    if (root == NULL)   return;
    postOrder(root->left, v);
    postOrder(root->right, v);
    v.push_back(root->data);
}

void postOrderM(node* root, vector<int> &v) {
    if (root == NULL)   return;
    postOrderM(root->right, v);
    postOrderM(root->left, v);
    v.push_back(root->data);
}

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d", v[i]);
        if (i < v.size() - 1)
        {
            printf(" ");
        }
    }
}

vector<int> pre, preM, post, postM, origin;

int main () {
    int n, data;
    node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderM(root, preM);
    postOrder(root, post);
    postOrderM(root, postM);
    if (pre == origin)
    {
        printf("YES\n");
        print(post);
    } else if (preM == origin) {
        printf("YES\n");
        print(postM);
    } else
    {
        printf("NO\n");
    }
    return 0;
}
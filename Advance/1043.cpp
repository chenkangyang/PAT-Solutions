/*
 * @Description: 给一组序列, 问是否是BST的先序或者镜像BST的先序序列, 正确则输出后序序列
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-20 20:20:43
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-04 22:49:08
 */
#include <cstdio>
#include <vector>
using namespace std; 
// 用vector存储初始序列, 先序序列, 镜像树序列可以方便相互比较

struct node {
    int data;
    node *left, *right;
};

void insert(node* &root, int data) { // 传指针的引用, 因为要对指针中的内容进行修改
    if(root == NULL) {
        root = new node;
        root->data = data;
        root->right = root->left = NULL;
        return; // 回溯
    }
    // if (data == root->data) return; 插入的节点若已经存在, 还是需要继续插入的, 找一个根节点的位置去插, 因此不能有这一句
    else if (data < root->data)  insert(root->left, data);
    else insert(root->right, data);
}

void preOrder(node* root, vector<int> &vi) { // 线序遍历结果存在vi
    if (root == NULL) return; // 回溯
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

void preOrderM(node* root, vector<int> &vi) {
    if (root == NULL) return; // 回溯
    vi.push_back(root->data);
    preOrderM(root->right, vi);
    preOrderM(root->left, vi);
}

void postOrder(node* root,vector<int> &vi) {
    if (root == NULL) return; // 回溯
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

void postOrderM(node* root,vector<int> &vi) {
    if (root == NULL) return; // 回溯
    postOrderM(root->right, vi);
    postOrderM(root->left, vi);
    vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;

int main() {
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
    if (origin == pre) // 初始序列等于先序序列
    {
        printf("YES\n");
        for (int i = 0; i < post.size(); i++)
        {
            printf("%d", post[i]);
            if (i < post.size() - 1) printf(" ");
        }
    } else if (origin == preM) {
        printf("YES\n");
        for (int i = 0; i < postM.size(); i++)
        {
            printf("%d", postM[i]);
            if (i < postM.size() - 1) printf(" ");
        }
    } else {
        printf("NO\n");
    }
    return 0;
}
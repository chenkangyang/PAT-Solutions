/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-06 18:37:57
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 20:00:50
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
using namespace  std;

const int MAXN = 31;
stack<int> st;
vector<int> pre, in, post;

struct node {
    int data;
    node* left, *right;
}tree[MAXN];

node* create(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return NULL;
    }
    
    node *root = new node;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++)
    {
        if (in[k] == root->data)
            break;
    }
    int numLeft = k - inL;
    root->left = create(preL+1, preL+numLeft, inL, k-1);
    root->right = create(preL+numLeft+1, preR, k+1, inR);
    return root;
}

void postOrder(node* root) {
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->data);
}


int main () {
    int n;
    scanf("%d", &n);
    char querry[20];
    int data;
    for (int i = 0; i < 2*n; i++)
    {
        cin >> querry;
        if (strcmp(querry, "Push") == 0)
        {
            cin >> data;
            st.push(data);
            pre.push_back(data);
        } else if (strcmp(querry, "Pop") == 0)
        {
            data = st.top();
            st.pop();
            in.push_back(data);
        }
    }
    node *root = create(0, n-1, 0, n-1);   
    postOrder(root);
    for (int i = 0; i < post.size(); i++)
    {
        printf("%d", post[i]);
        if (i != n-1)
        {
            printf(" ");
        }
    }
    return 0;
}


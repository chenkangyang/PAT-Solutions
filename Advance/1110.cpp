/*
 * @Description: 判断是否是完全二叉树
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 12:44:37
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 16:22:03
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100;
int n;
struct node {
	int l, r;
}tree[MAXN];
int vis[MAXN] = { 0 };
bool notRoot[MAXN] = { false };
int max_index = -1, ans;  // 若max_index == n, YES

void dfs(int root, int index) { // 节点值, 下标
	if (root == -1) return;
	if (index > max_index)
	{
		max_index = index; // 更新最大节点的下标
		ans = root; // 最后一个节点的值
	}
	dfs(tree[root].l, index * 2);
	dfs(tree[root].r, index * 2 + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string l, r;
		cin >> l >> r;
		tree[i].l = (l == "-" ? -1 : stoi(l));
		tree[i].r = (r == "-" ? -1 : stoi(r));
		if (l != "-") notRoot[stoi(l)] = true;
		if (r != "-") notRoot[stoi(r)] = true;
	}
	int root = 0; // 找根
	while (notRoot[root] != false) root++;
	dfs(root, 1);
	if (max_index == n)
		printf("YES %d", ans);
	else
		printf("NO %d", root);
	system("pause");
	return 0;
}
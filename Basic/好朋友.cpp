/*
 * @Description: 求子集个数
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-20 21:52:25
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-20 22:33:46
 */
#include <cstdio>
const int maxn = 100;
const int maxm = 100;

int father[maxn];
bool isRoot[maxn]; // 某个节点是否作为对应集合的根节点

int findFather(int x) {
    while (x != father[x]) { // 如果不是根节点继续循环, 递推到最后即:自己找到自己233
        x = father[x]; // 获得子集的根节点
    }
    int a = x;
    while (a != father[a]) // 路径压缩
    {
        int z = a;
        a  = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
    {
        father[faA] = faB;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int index;
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
        isRoot[i] = false;
    }
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        Union(a, b);
    }
    int cnt;
    for (int i = 1; i <= n; i++)
    {
        // printf("%d's father is %d\n", i, findFather(father[i]));
        if (findFather(i) == i)
        {
            isRoot[father[i]] = true; cnt++;
        }
    }
    printf("%d", cnt);
    
    return 0;
}
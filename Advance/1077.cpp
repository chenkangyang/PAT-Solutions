/*
 * @Description: Union Set, 找出所有Set的子集数量(不相交)
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-20 21:44:36
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-21 22:19:04
 */

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int father[maxn] = {0};
int isRoot[maxn] = {0}; // 需要记录每个集合的元素个数
int course[maxn] = {0}; // course[i] 代表任意(因为只需找father就行了)喜欢i活动的人的编号

void init(int n) {
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
        isRoot[i] = 0;
    }
}
int findFather(int x) {
    int a = x; // 原先要查找的节点
    while (x != father[x]) // 沿着路径寻找根节点
    {
        x = father[x];
    }
    // 路径压缩
    while (a != father[a]) // 此时x是根节点, 重新遍历路径, 将路径上的所有节点都指向根节点
    {
        int z = a; // a 要被 father[a] 覆盖, 先保存a的值, 以修改father[a]
        a  = father[a]; // a 回溯父亲节点
        father[z] = x; // 将原先a的父亲节点改为根节点x
    }
    return x;
}

void Union (int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
        father[faA] = faB;
}

bool cmp(int a, int b) {
    return a>b;
}

int main() {
    int n, k, h;
    scanf("%d", &n); // n个用户
    init(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d:", &k); // 活动个数
        for (int j = 0; j < k; j++)
        {
            scanf("%d:", &h); // 喜欢的活动编号h
            if (course[h] == 0) // 如果活动h 第一次有人喜欢
            {
                course[h] = i;
            }
            Union(i, findFather(course[h]));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // printf("%d's father is %d\n", i, findFather(i));
        isRoot[findFather(i)]++; // 向根节点累加
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (isRoot[i] != 0)
        {
            cnt++;
        }
    }
    if (cnt == 0)
    {
        printf("0\n0");
    }
    else {
        printf("%d\n", cnt);
        sort(isRoot + 1, isRoot + n + 1, cmp);
        for (int i = 1; i <= cnt; i++)
        {
            printf("%d", isRoot[i]);
            if (i < cnt) printf(" ");
        }
    }
    return 0;
}
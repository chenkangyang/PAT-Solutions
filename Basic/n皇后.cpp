#include <cstdio>
#include <cstdlib>

// 求n*n个棋牌上放置n个皇后, 两两不在同一行同一列同一对角线的方案数目

// 每列皇后所在行构成了一个排列, 对这个排列判断是否合法, 显然不在同一列同一行, 只需判断是否在同一对角线
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
int count = 0;

void g(int index) {
    if (index == n+1)
    {
        bool flag = true;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++)
            {
                if (abs(i-j) == abs(P[i] - P[j])) {
                    flag = false; // 不合法
                }
            }
        }
        if (flag) count ++;
        return;   
    }
   for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            P[index] = x;
            hashTable[x] = true;
            g(index + 1);
            hashTable[x] = false;
        }
    }
}

int main () {
    n = 8;
    g(1);
    printf("%d\n", count); // n = 8 时, Count = 92
    return 0;
}
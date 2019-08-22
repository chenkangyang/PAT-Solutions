// 求全排列
#include <cstdio>

const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};


void g(int index) {
    // printf("递归调用%d\n", index);
    if (index == n+1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }

    for (int x = 1; x <= n; x++)
    {
        // printf("x=%d\n", x);
        if (hashTable[x] == false)
        {
            // printf("%d处未处理\n", x);
            P[index] = x;
            hashTable[x] = true;
            g(index + 1);
            hashTable[x] = false;
            // printf("hashTable[%d]=false\n", x);
        }
    }
    // 函数的末尾有隐式的return ; 因此会返回至上一层调用点
}


int main () {
    n = 3;
    g(1);
    return 0;
}
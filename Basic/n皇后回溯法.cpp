#include <cstdio>
#include <cstdlib>

// 未到达递归边界前, 导致不需要往任何一个子问题递归就可以直接返回上一层 ---- 回溯法

const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
int count = 0;

void g(int index) {
    if (index == n+1)
    {
        count ++;
        return;   
    }
   for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            bool flag = true; // flag为true表示当前皇后不会和之前的皇后重冲突
            for (int pre = 1; pre < index; pre++) // 检测之前的皇后中的冲突
            {
                if (abs(index - pre) == abs(x - P[pre])) {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                P[index] = x;
                hashTable[x] = true;
                g(index + 1);
                hashTable[x] = false;
            }
        }
    }
}

int main () {
    n = 8;
    g(1);
    printf("%d\n", count); // n = 8 时, Count = 92
    return 0;
}
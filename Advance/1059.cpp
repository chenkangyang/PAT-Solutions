/*
 * @Description: 质因子分解, 首先用过筛法打表
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-11 22:58:14
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-21 22:53:00
 */
#include <cstdio>

struct factor
{
    long int x, cnt;
} fac[20];

const int maxn = 100001; // 求10^5个个数中的所有素数
int prime[maxn], cnt = 0;
bool p[maxn] = {0}; // 判断该数字是否被筛掉过

// 将0-n个素数打表
void Find_prime(long int n)
{
    for (int i = 2; i < maxn; i++)
    {
        if (p[i] == false)
        {
            prime[cnt++] = i;
            if (cnt >= n)
                break;
            for (int j = i + i; j < maxn; j += i)
                p[i] = true;
        }
    }
}

int main()
{
    long int n;
    scanf("%ld", &n);
    printf("%ld=", n);
    if (n == 1) printf("1");
    Find_prime(n);
    int num = 0;
    for (int i = 0; i * i < n; i++)
    {
        if (n % prime[i] == 0) // 若p是n的因子
        {
            fac[num].x = prime[i]; // 记录该因子并初始化其个数
            fac[num].cnt = 0;
            while (n % prime[i] == 0) // 计算当前质因子的个数
            {
                fac[num].cnt++;
                n /= prime[i];
            }
            num++;
        }
    }
    if (n != 1) // 如果无法被根号n以内的数字除尽
    {
        fac[num].x = n; // 一定有一个大于根号n的质因子
        fac[num++].cnt = 1;
    }
    
    for (int i = 0; i < num; i++)
    {
        printf("%ld", fac[i].x);
        if (fac[i].cnt > 1)
        {
            printf("^%ld", fac[i].cnt);
        }
        if (i != num - 1)
            printf("*");
    }
    return 0;
}
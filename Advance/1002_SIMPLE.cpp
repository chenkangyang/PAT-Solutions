/*
 * @Description: 多项式加法的简化版本
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-28 23:43:08
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-29 00:08:12
 */

#include <cstdio>
const int MAXN = 1111;
double p[MAXN] = {}; // 每一幂次的系数, index = 幂次
int main() {
    int k, n, count = 0;
    double a;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %lf", &n, &a);
        p[n] += a;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %lf", &n, &a);
        p[n] += a;
    }
    for (int i = 0; i < MAXN; i++)
    {
        if (p[i]!=0)
        {
            count ++;
        }
    }
    printf("%d", count);
    for (int i = MAXN - 1; i >= 0; i--)
    {
        if (p[i] != 0)
        {
            printf(" %d %.1lf", i, p[i]);
        }
    }
    return 0;    
}
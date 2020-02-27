/*
 * @Description: 多项式乘法
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-28 23:04:45
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-03 22:23:05
 */

#include <cstdio>

const int MAXK = 11;
const int MAXN = 1010;

struct term {
    int exp;
    double k;
}a[MAXK];

double ans_p[2001]; // index = 幂次

int main() {
    int k1, k2;
    scanf("%d", &k1); // 非零项目的个数
    for (int i = 0; i < k1; i++)
    {
        scanf("%d %lf", &a[i].exp, &a[i].k); // 低位存储高次项
    }
    scanf("%d", &k2); // 非零项目的个数
    int cnt = 0;
    for (int i = 0; i < k2; i++)
    {
        int exp;
        double k;
        scanf("%d %lf", &exp, &k);
        for (int j = 0; j < k1; j++)
        {
            ans_p[exp+a[j].exp] += (a[j].k * k);
        }
    }
    for (int i = 0; i < 2001; i++)
    {
        if (ans_p[i]!=0.0)
        {
            cnt++;
        }
    }
    
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--)
    {
        if (ans_p[i] != 0.0) { // 输出非零项
            printf(" %d %.1lf", i, ans_p[i]);
        }
    }
    
    return 0;
}

/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5
*/
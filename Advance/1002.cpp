/*
 * @Description: 多项式加法
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-28 23:04:45
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-29 00:06:02
 */

#include <cstdio>

const int MAXK = 11;
const int MAXN = 1010;

struct term {
    int exp;
    double k;
}a[MAXK], b[MAXK];

int add(term a[], term b[], term c[], int a_num, int b_num) {
    int cnt = 0;
    int p1 = 0, p2 = 0; // 两个指针从低位(高次项) 遍历a,b
    while (p1 < a_num || p2 < b_num) 
    {
        // printf("a[%d].exp:%d, b[%d].exp:%d\n", p1, a[p1].exp, p2, b[p2].exp);
        if (a[p1].exp == b[p2].exp)
        {
            c[cnt].exp = a[p1].exp;
            c[cnt++].k = a[p1].k + b[p2].k;
            p1++;
            p2++;
        } else if (a[p1].exp > b[p2].exp)
        {
            c[cnt].exp = a[p1].exp;
            c[cnt++].k = a[p1].k;
            p1++;
        } else
        {
            c[cnt].exp = b[p2].exp;
            c[cnt++].k = b[p2].k;
            p2++;
        }
    }
    return cnt;
}

int main() {
    int k1, k2;
    scanf("%d", &k1); // 非零项目的个数
    for (int i = 0; i < k1; i++)
    {
        scanf("%d %lf", &a[i].exp, &a[i].k); // 低位存储高次项
    }
    scanf("%d", &k2); // 非零项目的个数
    for (int i = 0; i < k2; i++)
    {
        scanf("%d %lf", &b[i].exp, &b[i].k);
    }
    term c[MAXK];
    int c_num = add(a, b, c, k1, k2);
    printf("%d ", c_num);
    for (int i = 0; i < c_num; i++)
    {
        printf("%d %.1lf", c[i].exp, c[i].k);
        if (i < c_num - 1)
        {
            printf(" ");
        }
        
    }
    
    return 0;
}

// 2 1 2.4 0 3.2
// 2 2 1.5 1 0.5
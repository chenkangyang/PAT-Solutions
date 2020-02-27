/*
 * @Description: 数学问题，递推找规律即可
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 16:23:17
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 16:58:27
 */

#include <cstdio>

long int count_1 (long int n) { // 计算某个数中1的个数
    long int cnt=0;
    while (n!=0)
    {
        if (n % 10 == 1)
        {
            cnt++;
        }
        n=n/10;
    }
    return cnt;
}

int main () {
    long int n, ans = 1;
    scanf("%ld", &n);
    for (long int i = 0; i <= n; i+=10)
    {
        if (i != 0)
            ans += count_1(i)*10 +1;
        // printf("count_1(%ld):%ld ,ans:%ld\n", i, count_1(i), ans);
    }
    
    for (long int i = (n/10+1)*10 - 1; i > n; i--)
    {
        ans -= count_1(i);
        // printf("count_1(%ld):%ld ,ans:%ld\n", i, count_1(i), ans);
    }
    printf("%ld", ans);
    return 0;
}
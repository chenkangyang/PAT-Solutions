/*
 * @Description: 素数 + 进制转换
 * 1. 转换十进制数到D进制
 * 2. 在D进制下反转后，到十进制
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-03 22:23:46
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-03 22:42:29
 */

#include <cstdio>
#include <cmath>

bool isprime (int n) {
    if (n <= 1) return false;
    int sqr = (int) sqrt (n * 1.0);
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, radix;
    while(scanf("%d", &n) != EOF) {
        if(n < 0) break;
        scanf("%d", &radix);
        if(isprime(n) == false) {
            printf("No\n");
            continue;
        }
        // 转换为D进制并翻转
        int len = 0, arr[100]; // 数组低位存储十进制低位
        do{
            arr[len++] = n % radix;
            n = n / radix;
        }while(n != 0);
        // 不必真的翻转，只需要在转换为十进制数的时候从后往前转换即可
        for(int i = 0; i < len; i++) {
            n = n * radix + arr[i];
        }
        printf("%s", isprime(n) ? "Yes\n" : "No\n");
    }
    return 0;
}
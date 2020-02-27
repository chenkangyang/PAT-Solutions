/*
 * @Description: 模拟 大数相加, 两个2^64次方的数相加，会溢出longlong的范围， 
 * 考虑到两个数可能是负数。因此大整数麻烦
 * 题目中数的范围为[-2^63, 2^63] longlong的范围为[-2^63, 2^63-1], 可以调用climits打印
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-27 20:15:50
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-27 21:11:49
 */

#include <cstdio>
#include <climits>
using namespace std;

int main () {
    // 打印溢出之后的数据范围
    // long long llmax = LONG_LONG_MAX;
    // long long llmin = LONG_LONG_MIN;
    // printf("%lld\n", llmax+1);
    // printf("%lld\n", llmax+llmax);
    // printf("%lld\n", llmin-llmax);
    // printf("%lld\n", llmin-1);

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if(a > 0 && b > 0 && sum < 0) {
            printf("Case #%d: true\n", i + 1);
        } else if(a < 0 && b < 0 && sum >= 0){
            printf("Case #%d: false\n", i + 1);
        } else if(sum > c) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}
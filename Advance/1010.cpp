/*
 * @Description: 任意进制数比较, 并输出进制
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-21 20:34:54
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-24 20:58:38
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 11;


int cal (char c) {
    if (c >= '0' && c <= '9') return (c - '0');
    else    return (c-'a'+10);
}

long long convert_to_decimal (char a[], long long radix) { // 将base进制的数转化为10进制
    long long sum = 0;
    int len = strlen(a);
    for (int i = len - 1; i >= 0; i--) // i 从高位开始指示每一位
    {
        long long c_a = cal(a[len-i-1]);
        sum += cal(a[len-i-1]) * pow(radix, i);
    }
    return sum;
}

long long find_radix(char b[], long long a) { // 查找b在什么进制时和a相同
    // 需要查找的进制数的最小值 = 字符串b中最大值+1, 最大值为a+1
    long long min_radix = 0, max_radix;
    int len  = strlen(b);
    for (int i = 0; i < len; i++)
    {
        if (min_radix < cal(b[i]))  min_radix  = cal(b[i]);
    }
    min_radix += 1; // 110 对应min_radix 就是2
    max_radix = max(min_radix, a);
    // printf("min:%lld, max:%lld\n", min_radix, max_radix);
    while (min_radix <= max_radix)
    {
        long long mid_radix = min_radix + (max_radix - min_radix) / 2;
        long long b_decimal = convert_to_decimal(b, mid_radix);
        // 转换结果过大, 说明当前进制进制大于mid_radix, 想求进制影子在左区间 甚至大到溢出了longlong
        if (b_decimal > a || b_decimal < 0)
        {
            max_radix = mid_radix-1; // 在左区间找
        } else if (b_decimal == a) {
            return mid_radix;
        }
        else
        {
            min_radix = mid_radix + 1;
        }
    }
    return -1;
}

int main() {
    char N1[maxn], N2[maxn];
    long long radix, result_radix; // radix 也可能是long型
    int tag;
    scanf("%s%s%d%lld", N1, N2, &tag, &radix);
    result_radix = tag == 1? find_radix(N2, convert_to_decimal(N1, radix)): find_radix(N1, convert_to_decimal(N2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }
    return 0;
}
/*
 * @Description: 回文, 先用小数试一下, 不行转成大数运算, 以及弄明白为什么要用大数运算
 * 1. 判断数是否回文
 * 2. 数字逆序
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-03 22:43:28
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-04 19:49:05
 */

#include <iostream>
#include <string>
using namespace std;

bool check (string s) {
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

int reverse (int a) {
    int b = 0;
    while (a != 0)
    {
        b = a%10 + b*10;
        a = a / 10;
    }
    return b;
}


int main () {
    int n, k;
    cin >> n >> k;
    int step = 0;
    int sum = 0;
    while (step != k)
    {
        sum = n + reverse(n);
        n = sum;
        string s = to_string(n);
        step ++;
        if (check(s)) // 是回文，跳出
            break;        
    }
    printf("%d\n%d\n", sum, step);
    return 0;
}
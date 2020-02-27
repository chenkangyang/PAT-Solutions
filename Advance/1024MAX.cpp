/*
 * @Description: 回文, 大整数加法
 * 1. 判断数是否回文
 * 2. 数字逆序
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-03 22:43:28
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-05 15:01:06
 */

#include <iostream>
#include <cstring>
using namespace std;

struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign add (bign a, bign b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry)
    {
        c.d[c.len++] = carry;
    }
    return c;
}

bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

bign reverse(bign a) {
    bign b;
    b.len = a.len;
    for (int i = 0; i < a.len; i++)
    {
        b.d[i] = a.d[a.len - i - 1];
    }
    return b;
}

bool check (bign a) {
    for (int i = 0; i < a.len / 2; i++)
    {
        if (a.d[i] != a.d[a.len - 1 - i])
            return false;
    }
    return true;    
}

void print(bign a) {
    for (int i = a.len - 1; i >= 0; i--)
        printf("%d", a.d[i]);
}

int main () {
    char str[1000];
    int k, step = 0;
    scanf("%s %d", str, &k);
    bign a = change(str);
    bign c;
    while (step != k)
    {
        if (check(a)) break;
        c = add(a, reverse(a));
        a = c;
        step++;
    }
    print(a);
    printf("\n%d\n", step);
    return 0;
}
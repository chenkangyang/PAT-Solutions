/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-14 21:37:22
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-14 22:04:36
 */

// bign a 与 int b 相乘

#include <cstdio>
#include <cstring>

struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};


bign convert (char str[]) // 将整数转换为bign
{
    bign a;  
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = str[a.len - i - 1] - '0';  // 逆序读入
    }
    return a;
}

bign multi(bign a, int b) { // 大数的每一位依次乘以int, 错位相加(除当前位, 其余位都为进位)
    bign c;
    int carry = 0; // carry是进位
    for (int i = 0; i < a.len; i++) 
    {
        int temp = a.d[i] * b + carry;
        // printf("a.d[i] + b * carry = %d + %d * %d = %d\n", a.d[i], b, carry,  temp);
        c.d[c.len ++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0) // 和加法不一样, 乘法的进位不止一位, 仅此用while
    {
        c.d[c.len++] = carry%10;
        carry /= 10;
    }
    return c;
}

void print (bign a) {
    for (int i = 0; i < a.len; i++)
    {
        printf("%d", a.d[i]);
    }
}

int main() {
    char str1[1000];
    int b;
    scanf("%s%d", str1, &b);
    bign a = convert(str1);
    bign c = multi(a, b);
    print(c);
    return 0;
}
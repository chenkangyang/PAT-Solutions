/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-14 21:37:22
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-14 22:15:05
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

bign divide(bign a, int b, int& r) { // 大数的每一位依次除以以int, 错位相加(除当前位, 其余位都为进位)
    bign c;
    c.len = a.len; // 被除数的每一位和商的每一位意义对应, 因此先另len相等
    for (int i = a.len - 1; i >= 0; i--) 
    {
        if (a.d[i] < b)  // 不够除
        {
            r = r * 10 + a.d[i]; // 上一位余留的余数与当前位 组成新的被除数
            if (r < b) c.d[i] = 0; // 不够除, 这一位为0
            else { // 够除
                c.d[i] = r / b;
                r = r % b;
            }            
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) 
    {
        c.len --;
    }
    return c;
}

void print (bign a) {
    for (int i = a.len - 1; i >= 0; i--)
    {
        printf("%d", a.d[i]);
    }
}

int main() {
    char str1[1000];
    int b, r = 0;
    scanf("%s%d", str1, &b);
    bign a = convert(str1);
    bign c = divide(a, b, r);
    print(c);
    printf("\nr=%d", r);
    return 0;
}
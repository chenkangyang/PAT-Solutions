/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-14 21:37:22
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-14 21:48:24
 */
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

bign add(bign a, bign b) {
    bign c;
    int carry = 0; // carry是进位
    for (int i = 0; i < a.len || i < b.len; i++) 
    {
        int temp = a.d[i] + b.d[i] + carry;
        carry = temp / 10;
        c.d[i] = temp % 10;
        c.len ++;
    }
    if (carry != 0) // 最高位仍有进位, c的最高位为进位
    {
        c.d[c.len++] = carry;
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
    char str1[1000], str2[1000];
    scanf("%s%s", str1, str2);
    bign a = convert(str1);
    bign b = convert(str2);
    bign c = add(a, b);
    print(c);
    return 0;
}
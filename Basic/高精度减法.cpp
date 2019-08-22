/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-14 21:37:22
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-14 21:53:14
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

bign sub(bign a, bign b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++) 
    {
        if (a.d[i] < b.d[i])
        {
            a.d[i+1]--; // 向高位借位
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >=1 && c.d[c.len-1] == 0) // 去除最高位的0, 同时至少保留一位最低位
    {
        c.len --;
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
    bign c = sub(a, b);
    print(c);
    return 0;
}
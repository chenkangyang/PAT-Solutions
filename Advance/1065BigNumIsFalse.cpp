/*
 * @Description: 大数相加, 两个2^64次方的数相加，会溢出longlong的范围， 
 * 考虑到两个数可能是负数。因此大整数麻烦
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-27 20:15:50
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-27 20:53:34
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct BigNum {
    int d[1000];
    int len;
    BigNum() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

BigNum change (char str[]) {
    int len = strlen(str);
    // str 的低位对应数字的高位
    BigNum a;
    for (int i = 0; i < len; i++)
    {
        a.d[i] = str[len-i-1] - '0';
    }
    a.len = len;
    return a;
}

BigNum add(BigNum a, BigNum b) {
    int carry=0;
    int len = max(a.len, b.len);
    BigNum c;
    for (int i = 0; i < len; i++)
    {
        int temp = a.d[i] + b.d[i] + carry;
        carry = (temp) / 10;
        c.d[c.len++] = (temp) % 10;
    }
    // 全部计算完之后考虑最高位的进位
    if (carry != 0)
    {
        c.d[c.len++] = carry;
    }
    return c;
}

bool compare (BigNum a, BigNum b) { // a > b: true
    if (a.len > b.len)
    {
        return true;
    } else if (a.len == b.len) {
        for (int i = a.len-1; i >=0; i--)
        {
            if (a.d[i] > b.d[i])
            {
                return true;
            }
        }
    } else
    {
        return false;
    }
    return false; // 对应比较完每一个位置后仍没有返回，则两数相等
}

void print(BigNum a) {
    for (int i = a.len - 1; i >=0; i--)
    {
        printf("%d", a.d[i]);
    }
    printf("\n");
}

int main () {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        char sa[1000], sb[1000], sc[1000];
        scanf("%s%s%s", sa, sb, sc);
        BigNum a = change(sa);
        BigNum b = change(sb);
        BigNum c = change(sc);
        BigNum temp = add(a, b);
        print(b);
        if (compare(temp, c))
        {
            printf("Case #%d: true\n", i+1);
        } else
        {
            printf("Case #%d: false\n", i+1);
        }
    }
    return 0;
}
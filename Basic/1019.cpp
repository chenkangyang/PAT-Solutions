/*
    * @Description: 
    * @Version: 1.0
    * @Autor: Alex
    * @Date: 2019-08-10 17:04:22
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-11 21:58:09
*/

#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

void to_array(int a, int b[])
{
    int cnt = 0;
    while (a) // a为个位数时才能得到0
    {
        b[cnt++] = a % 10;
        a = a / 10;
    }
}

int to_number(int b[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum * 10 + b[i];
    }
    return sum;
}

int main()
{
    int a, MIN, MAX;
    scanf("%d", &a);
    int b[5];
    while (1)
    {
        to_array(a, b);
        sort(b, b + 4);
        MIN = to_number(b, 4);
        sort(b, b + 4, cmp);
        MAX = to_number(b, 4);
        a = MAX - MIN;
        printf("%04d - %04d = %04d\n", MAX, MIN, a);
        if (a == 6174 || a == 0)
            break;
    }
    return 0;
}
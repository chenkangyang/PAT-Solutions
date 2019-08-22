/*
 * @Description:
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-10 13:54:30
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-10 14:21:16
 */
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100010;
const int mod = 1000000007;
int leftNumP[maxn] = {0};
char str[maxn];

int main()
{
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (i > 0)
        {
            leftNumP[i] = leftNumP[i - 1];
        }
        if (str[i] == 'P')
        {
            leftNumP[i]++;
        }
    }
    int ans = 0, rightNumT = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (i > 0 & str[i] == 'T')
        {
            rightNumT++;
        }
        else if (str[i] == 'A')
        {
            ans = (ans + rightNumT * leftNumP[i]) % mod;
        }
    }
    printf("%d", ans);
    return 0;
}
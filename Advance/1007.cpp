/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-23 21:23:31
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-23 23:27:43
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int A[maxn], dp[maxn];

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    dp[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i-1] + A[i], A[i]);
    }
    int max = -1, first = -1, end = -1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < dp[i])
        {
            max = dp[i];
            end = i;
        }
    }
    for (int i = end; i >= 0; i--)
    {
        sum+=A[i];
        if (sum == max)
        {
            first = i;
            break;
        }
    }
    if (max < 0)
    {
        printf("0 %d %d", A[0], A[n-1]);
    }
    else
    {
        printf("%d %d %d", max, A[first], A[end]);
    }
    
    return 0;
}
/*
 * @Description: 最长回文子串
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-24 20:38:39
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-24 22:06:03
 */

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int MAXN = 1010;
int dp[MAXN][MAXN];

int main() {
    int ans = 1, len;
    string S;
    getline(cin, S);
    len = S.length();
    // 初始化dp
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len)
        {
            if(S[i] == S[i+1])
            {
                dp[i][i+1] = 1;
                ans = 2;
            }
        }
    }
    
    for (int L = 3; L <= len; L++)
    {
        for (int i = 0; i + L -1 < len; i++)
        {
            int j = i + L - 1;
            if (S[i] == S[j] && dp[i+1][j-1] == 1)
            {
                dp[i][j] = 1;
                ans = L;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
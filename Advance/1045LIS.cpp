/*
 * @Description: 最长不下降子序列
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-24 19:50:13
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-24 20:28:39
 */

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 210;
const int MAXM = 210; // 最大喜欢的颜色数
const int MAXL = 10010; // 色条最大长度
int fav[MAXM];
int all[MAXL];
int dp[MAXL];
int HashTable[MAXM]; // key:原本顺序, value: 递增顺序

int main () {
    int n, m, l;
    scanf("%d", &n); // 颜色编号为：1-N
    scanf("%d", &m);
    fill(HashTable, HashTable + MAXM, -1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &fav[i]);
        HashTable[fav[i]] = i+1; // 映射, 不在喜欢的颜色中的为-1
    }
    scanf("%d", &l);
    int cnt = 0; //剔除喜欢的颜色之后剩余的元素个数
    for (int i = 0; i < l; i++)
    {
        int index;
        scanf("%d", &index);
        if (HashTable[index] == -1)
        {
            continue;
        } else
        {
            all[cnt++] = HashTable[index];
        }
    }
    int ans = -1; // 记录最大的dp[i]
    for (int i = 0; i < cnt; i++)
    {
        dp[i] = 1; // 先假设每个元素自成一个子序列
        for (int j = 0; j < i; j++)
        {
            if (all[i] >= all[j] && (dp[j]+1 > dp[i])) // 递增且前方长度+1: 比当前位置长, 更新当前长度
            {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}
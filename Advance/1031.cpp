/*
 * @Description: 图像输出, 找规律!!!
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-30 22:51:29
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-30 23:21:52
 */

#include <cstdio>
#include <cstring>

int main () {
    char S[81];
    scanf("%s", S);
    int N = strlen(S);
    int n1 = (N+2)/3;
    int n2 =  N + 2 - 2*n1;
    char ans[50][50];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            ans[i][j] = ' ';
        }
    }
    int pos = 0;
    // 输出完整的第一列 (n1个元素)
    for (int i = 0; i < n1; i++)
    {
        ans[i][0] = S[pos++];
    }
    // 输出最后一行 (n2-1个元素)
    for (int j = 1; j < n2; j++)
    {
        ans[n1-1][j] = S[pos++];
    }
    // 输出最左边一列共n3-1个元素
    for (int i = n1-2; i >=0 ; i--)
    {
        ans[i][n2-1] = S[pos++];
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
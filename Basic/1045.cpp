/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-10 14:25:09
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-10 16:12:00
 */
// 如果硬编码会运行超时了

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int num[maxn] = {0};
int left[maxn] = {0};
int right[maxn] = {0};
/* 
int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < n; i++)
    {
        // 每一位右边大于他的元素个数
        int temp = num[i];
        for (int j = i+1; j < n; j++) // 遍历右边元素
        {
            if (num[j] > temp) // 大于当前元素
            {
                right[i]++; // 大于右边的元素个数++
            }
        }
        for (int j = i; j >= 0; j--)
        {
            if (num[j] < temp)
            {
                left[i]++; // 小于右边的元素个数++
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (left[i] + right[i] == n-1)
        {
            printf("%d", num[i]);
            if (i != n-1)
            {
                printf(" ");
            }
        }
    }
    return 0;
}
*/

// 对原序列排序后, 逐个比较, 若当前元素没有变化并且他左边的所有值最大值都比他小, 就一定是主元

int main()
{
    int n;
    scanf("%d", &n);
    int newnum[n], max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        newnum[i] = num[i];
    }
    sort(newnum, newnum + n);
    int ans[n], cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (num[i] == newnum[i] && num[i] > max)
        {
            ans[cnt++] = num[i];
        }
        if (num[i] > max)
            max = num[i];
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d", ans[i]);
        if (i != cnt - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
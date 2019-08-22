/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-10 16:45:10
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-10 17:03:12
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int A[maxn], n;

// 随机寻找主元
int randPartition(int A[], int left, int right)
{
    int p = round(1.0*rand()/RAND_MAX*(right-left)+left);
    swap(A[p], A[left]);
    int temp = A[left];
    while (left < right)
    {
        while (left < right && A[right] <= temp)
            right--;
        A[left] = A[right];
        while (left < right && A[left] > temp)
            left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void randSelect(int A[], int left, int right, int K)
{
    if (left == right)
        return;
    int p = randPartition(A, left, right);
    int M = p - left + 1;
    if (K == M)
        return;
    if (K < M)
    {
        randSelect(A, left, p - 1, K);
    }
    else
    {
        randSelect(A, p + 1, right, K - M);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int sum = 0, sum1 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    randSelect(A, 0, n - 1, n / 2); // 寻找第n/2大的数, 并进行切分
    for (int i = 0; i < n / 2; i++)
    {
        sum1 += A[i]; // 累计较小的子集合中元素之和
    }
    printf("%d\n", (sum - sum1) - sum1); // 求两个子集合的元素和之差
    return 0;
}
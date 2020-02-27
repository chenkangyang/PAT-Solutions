/*
 * @Description: 因式分解, DFS+剪枝
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 10:08:44
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 12:24:26
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// 先把i从0开始所有的i的p次方的值存储在v[i]中，然后dfs
int n, k, p, maxFacSum=-1;
vector<int> v, ans, tempAns;

void init() {
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}

void dfs(int index, int tempK, int facSum, int sum) { // 当前搜索因子, 因式个数, 因式之和, 总和
    if (tempK == k)
    {
        if (sum == n && facSum > maxFacSum) { // 更新解
            // printf("index:%d, k:%d, sum:%d\n", index, tempK, sum);
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    while (index >= 1)
    {
        if (sum + v[index] <= n)
        {
            tempAns[tempK] = index;
            dfs(index, tempK + 1, facSum+index, sum+v[index]); // 因子可以相同, 银子不需要index-1
        }
        if (index == 1) return;
        index --;
    }
}

int main () {
    scanf("%d%d%d",&n,&k,&p);
    tempAns.resize(k);
    init();
    dfs(v.size()-1, 0, 0, 0); // 从大到小遍历, 才能使得遍历序列的是从大到小排序的
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < k; i++)
    {
        printf("%d^%d", ans[i], p);
        if (i != k-1) {
            printf(" + ");
        }
    }
    return 0;
}
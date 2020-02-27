/*
 * @Description: 背包问题
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-27 21:39:02
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-29 00:17:25
 */

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 10010;
const int MAXV = 110;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N=0, V=0; // 物品个数，总容量
    scanf("%d%d", &N, &V);
    int w[N], dp[MAXV];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &w[i]);
    }
    sort(w, w + N, cmp); // 从大到小排序
    for (int v = 0; v < MAXV; v++)
    {
        dp[v] = 0;
    }
    // 记录选择
    int choice[MAXN][MAXV]; 
    // 跳着填入的, 因此查找路径的时候也是跳着找, 
    // 若为1, 则横跨物品质量, 纵跨到下一物品, 若为0, 则只纵跨不横跨
    for (int i = 0; i < N; i++)
    {
        for (int v = V; v >= w[i] ; v--)
        {
            if (dp[v] <= dp[v-w[i]]+w[i])
            {
                dp[v] = dp[v-w[i]] + w[i];
                choice[i][v] = 1; // 放第i件物品
                // printf("v:%d, w[%d]:%d\n", v, i, w[i]);
            }
            else {
                choice[i][v] = 0;
            }
        }
    }

    if (dp[V] != V) printf("No Solution");
    else
    {
        vector<int> arr;
        int v = V, index = N;
        while(v > 0) {
            if(choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}


/* input:
8 9
5 9 8 7 2 3 4 1
*/
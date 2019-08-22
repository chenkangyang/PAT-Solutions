/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-19 21:17:49
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-19 21:29:42
 */

// 背包问题深度优先搜索
// n件物品放入总容量为V的背包, 使总价值最大. 每件物品重量和价值都可以不同

#include <cstdio>
const int maxn = 30;
int n, V, maxValue = 0; // 物品件数, 背包容量, 最大价值
int w[maxn], v[maxn]; // 各物品weight, value

void DFS(int index, int sumW, int sumV) { // 当前处理的物品编号index, 总重量sumW, 总价值sumV
    if (index == n) // 已经完成对n件物品的选择 (死胡同), 更新当前对打价值, 回溯
    {
        if (sumW <= V && sumV > maxValue)
        {
            maxValue = sumV; // 不超过背包容量时, 更新最大价值
        }
        return;
    }
    // 只有以下两种岔道: 
    DFS(index + 1, sumW, sumV); // 不选第index件物品
    DFS(index + 1, sumW + w[index], sumV + v[index]); // 选第index件物品
}

int main () {
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    DFS(0, 0, 0);
    printf("%d\n", maxValue);
    return 0;
}

/*
input:
5 8
3 5 1 2 2
4 5 2 1 3
output
10
*/

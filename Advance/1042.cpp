/*
 * @Description: 按指定移动位置,洗牌模拟
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-26 22:04:16
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-26 23:26:59
 */
#include <cstdio>
#include <cstring>

const int MAXK = 20;
const int N = 54;
int Deck[N+1]; // 序列
int temp[N+1]; // 每一轮洗牌的中间结果
int order[N+1]; // 移动到的位置
char mp[5] = {'S', 'H', 'C', 'D', 'J'};

int main() {
    int k; // 洗牌次数
    scanf("%d", &k);
    memset(order, 0, sizeof(order));
    for (int i = 1; i <= N; i++)
    {
        Deck[i] = i;
        scanf("%d", &order[i]);
    }
    for (int cnt = 0; cnt < k; cnt++) // 洗k次
    {
        for (int i = 1; i <= N; i++)
        {
            temp[order[i]] = Deck[i];
        }
        for (int i = 1; i <= N; i++)
        {
            Deck[i] = temp[i];
        }
    }
    // 打印
    for (int i = 1; i <= N; i++)
    {
        if (i!= 1) printf(" ");
        Deck[i]--;
        printf("%c%d", mp[Deck[i]/13], Deck[i] % 13 +1);
    }
    return 0;
}
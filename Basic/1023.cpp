#include <cstdio>

int main() {
    int count[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &count[i]);
    }
    // 先从1-9 中选择最小的输出一次, 最小的数字 个数-1; 在从小到大输出所有数字, 输出次数为其剩余个数
    for (int i = 1; i < 10; i++)
    {
        if (count[i] > 0)
        {
            printf("%d", i);
            count[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        while (count[i]--)
        {
            printf("%d", i);
        }
    }
    return 0;
}
/*
 * @Description: 找两个静态链表中相同位置的元素
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-14 22:28:25
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-02 19:27:00
 */
#include <cstdio>

const int MAXN = 100010;

struct node {
    char data;
    int next;
    bool flag;
}list[MAXN];

int main() {
    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    for (int i = 0; i < MAXN; i++)
    {
        list[i].flag = false;
    }
    for (int i = 0; i < n; i++)
    {
        int index, next;
        char data;   
        scanf("%d %c %d", &index, &data, &next); // 一定要有空格！
        list[index].data = data;
        list[index].next = next;
    }
    for (int i = s1; i != -1; i = list[i].next)
    {
        // printf("first: %05d %c %05d\n", i, list[i].data, list[i].next);
        list[i].flag = true;
    }
    int i;
    for (i = s2; i != -1; i = list[i].next)
    {
        // printf("second: %05d %c %05d\n", i, list[i].data, list[i].next);
        if (list[i].flag == true)
        {
            printf("%05d", i);
            break;
        }
    }
    if (i == -1)
    {
        printf("-1");
    }
    return 0;
}
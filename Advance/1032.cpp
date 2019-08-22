/*
 * @Description: 找两个静态链表中相同位置的元素
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-14 22:28:25
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-21 22:46:10
 */
#include <cstdio>

const int maxn = 100000;

struct NODE {
    char data;
    int next;
    bool flag; // 有没有在前一个链表中被统计过
}nodelst[maxn];

int main() {
    for (int i = 0; i < maxn; i++)
    {
        nodelst[i].flag = false;
    }
    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);

    int address, next;
    char data;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &address, &data, &next);
        nodelst[address].data = data;
        nodelst[address].next = next;
    }
    int p;
    for (p = s1; p != -1; p = nodelst[p].next) // 遍历第一条链表
    {
        // printf("first: %05d %c %05d\n", p, nodelst[p].data, nodelst[p].next);
        nodelst[p].flag = true;
    }
    for (p = s2; p != -1; p = nodelst[p].next) // 遍历第二条链表, 输出第一个flag为false的p
    {
        // printf("second: p:%05d, next: %d, flag:%d\n", p, nodelst[p].next, nodelst[p].flag);
        if (nodelst[p].flag) {
            printf("%05d", p);
            break;
        }
    }

    if (p == -1)
    {
        printf("-1");
    }
    return 0;
}
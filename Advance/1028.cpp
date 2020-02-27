/*
 * @Description: 就是个排序而已
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-01 21:55:50
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-03 21:22:38
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100001;

struct Node {
    int id, grade;
    char name[10];
}list[maxn];
int n, c;

int cmp1(Node a, Node b) {
    if (c == 1) {
        return a.id < b.id;
    } else if (c == 2) {
        if (strcmp(a.name, b.name) == 0) return a.id < b.id;
        return strcmp(a.name, b.name) <= 0;
    } else if (c == 3) {
        if(a.grade == b.grade) return a.id < b.id;
        return a.grade <= b.grade;
    }
}

int main () {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d%s%d", &list[i].id, list[i].name, &list[i].grade);
    }
    sort(list, list + n, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", list[i].id, list[i].name, list[i].grade);
    }
    return 0;
}

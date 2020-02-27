/*
 * @Description: Hash散列法
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-04 23:11:05
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-05 19:00:45
 */

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1010;
int hashTable[MAXN]; // 每个数字出现的个数, i + m-i = m;
int main () {
    int n,m,data;
    scanf("%d %d", &n , &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        hashTable[data] ++;
    }
    for (int i = 0; i < n; i++) {
        if (hashTable[i] && hashTable[m-i]) {
            if (i == m - i && hashTable[i] <= 1)
                continue;
            printf("%d %d\n", i, m - i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}


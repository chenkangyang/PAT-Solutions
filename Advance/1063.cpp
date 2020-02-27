/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 20:32:45
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 20:44:01
 */

#include <cstdio> 
#include <set>
using namespace std;
const int N = 51;
set<int> st[N];

void compare(int x, int y) {
    double totalNum = st[y].size(), sameNum = 0;
    for (set<int>::iterator it = st[x].begin(); it != st[x].end(); it++) // 遍历x
    {
        if (st[y].find(*it) != st[y].end())   // 在y中能找到x中的该元素
            sameNum ++;
        else totalNum ++;    // 在y中不能找到x中的该元素
    }
    double rate = sameNum*100/totalNum;
    printf("%.1lf%%\n", rate);
}

int main () {
    int n,k,q,v,st1,st2;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &v);
            st[i].insert(v);
        }
    }
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &st1, &st2);
        compare(st1, st2);
    }
    return 0;
}
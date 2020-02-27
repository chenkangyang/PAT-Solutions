/*
 * @Description: 快速排序
 * 给N个数，第一行输出可能是主元的个数，第二行输出这些元素
 * 对原序列sort排序，逐个比较，当当前元素没有变化并且它左边的所有值的最大值都比它小的时候就可以认为它一定是主元
 * （很容易证明正确性的，毕竟无论如何当前这个数要满足左边都比他大右边都比他小，那它的排名【当前数在序列中处在第几个】一定不会变）
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 09:14:41
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 09:53:56
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int v[MAXN];

int main () {
    int n, left_max = -1, cnt = 0;
    scanf("%d", &n);
    vector<int> origin(n), changed(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &origin[i]);
        changed[i] = origin[i];
    }
    sort(changed.begin(), changed.end());
    for (int i = 0; i < n; i++)
    {
        if(origin[i] == changed[i] && origin[i] > left_max)
            v[cnt++] = changed[i];
        if (origin[i] > left_max)
        {
            left_max = origin[i];
        }
    }

    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    
    return 0;
}
/*
 * @Description: hash
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 21:39:19
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 23:01:03
 */

#include <cstdio>
#include <vector>
using namespace std;

int main () {
    int n,m,k,nv,a,b,num;
    scanf("%d%d",&n,&m);
    vector<int> v[n];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &nv);
        vector<int> hash(m, 0);
        int flag = 0;
        for (int j = 0; j < nv; j++)
        {
            scanf("%d", &num);
            for (int t = 0; t < v[num].size(); t++)
            {
                hash[v[num][t]] = 1;
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (hash[j] == 0) {
                printf("No\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("Yes\n");
    }
    return 0;
}
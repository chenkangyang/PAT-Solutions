/*
 * @Description: DFS, 找使得树高最xiao的那条路
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-05 20:58:14
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-05 21:46:07
 */

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000000;
vector<int> v[MAXN];
int n, minHeight = INF, num = 0;
double p, r;

void DFS(int index, int height) {
    // printf("index: %d, height:%d\n", index, height);
    if (v[index].size() == 0)
    {
        if (height < minHeight) {
            minHeight = height;
            num = 1;
        } else if (height == minHeight)
        {
            num ++;
        }
        return;
    }
    
    for (int i = 0; i < v[index].size(); i++)
    {
        DFS(v[index][i], height + 1);
    }
}

int main () {
    scanf("%d %lf %lf", &n, &p, &r);
    int k, next;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k != 0)
        {
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &next);
                v[i].push_back(next);
            }
        }
    }
    DFS(0,0);
    p = p * pow(1+r*0.01, minHeight);
    printf("%.4f %d", p, num);
    return 0;
}
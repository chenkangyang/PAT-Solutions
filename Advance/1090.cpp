/*
 * @Description: 找最长路径
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-05 21:47:35
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 15:01:23
 */

#include <cstdio> 
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100010;
int n, start, cnt = 0,  maxHeight = -1;
double p, r;
vector<int> child[MAXN];

void DFS(int index, int height) {
    if (child[index].size() == 0)
    {
        if (height > maxHeight)
        {
            maxHeight = height;
            cnt = 1; // 更新最大高度后, 重置最大高度的路径为1
        } else if (height == maxHeight) {
            cnt ++;
        }
        return;
    }
    for (int i = 0; i < child[index].size(); i++)
    {
        DFS(child[index][i], height+1);
    }
}

int main () {
    scanf("%d %lf %lf", &n, &p, &r);
    int father;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &father);
        if (father == -1)
        {
            start = i;
        } else
        {
            child[father].push_back(i);
        }
    }
    DFS(start, 0);
    double price = p * pow(1+0.01*r, maxHeight);
    printf("%.2lf %d", price, cnt);
    return 0;
}
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 20:11:51
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 20:26:44
 */

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 40010;
const int MAXC = 2510;
vector<int> course[MAXC];
char name[MAXN][5];

bool cmp1 (int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main () {
    int n,k,c,c_id;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", name[i], &c);
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &c_id);
            course[c_id].push_back(i); // 学生i加入课程
        }
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp1);
        for (int j = 0; j < course[i].size(); j++)
        {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}
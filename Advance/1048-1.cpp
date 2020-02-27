/*
 * @Description: 模拟: 找2个数之和(V1+V2, V1 <= V2)为给定的值, 多个解时, 输出V1最小的那个 (时间限制150ms, 暴力可能会超时)
 * 选择二分查找AC
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-04 23:11:05
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-05 16:35:28
 */

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 10010;
const int maxm = 1010;
vector<int> v;
int n, m;

int find_v2 () {
    for (int v1 = 0; v1 < v.size(); v1++)
    {
        int l = v1 + 1, r = v.size() - 1;
        while (l <= r)
        {
            int mid = l + (r-l)/2;
            if (v[v1] + v[mid] == m)
            {
                printf("%d %d", v[v1], v[mid]);
                return mid;
            } else if (v[v1] + v[mid] < m)
            {
                l = mid + 1;
            } else
            {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main () {
    int data;
    scanf("%d %d", &n , &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        v.push_back(data);
    }
    sort(v.begin(), v.end());
    int v2 = find_v2();
    if (v2 == -1) printf("No Solution");
    return 0;
}


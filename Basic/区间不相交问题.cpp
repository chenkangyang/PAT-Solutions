#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10;
struct Inteval {
    int x, y;
}I[maxn];

bool cmp(Inteval a, Inteval b)
{
    if (a.x != b.x)
    {
        return a.x > b.x;
    }
    else
    {
        return a.y < b.y;
    }
    
    
}
int main () 
{
    int n;
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &I[i].x, &I[i].y);
        }
        sort(I, I +n, cmp);
        int ans = 1, lastX = I[0].x; // ans 不相交区间的个数, lastX记录上一个被选中的区间的左端点
        for (int i = 1; i < n; i++)
        {
            if (I[i].y <= lastX) // 当前区间的右端点在更大区间的左端点左边时候
            {
                ans ++;
                lastX = I[i].x;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
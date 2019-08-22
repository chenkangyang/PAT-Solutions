#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10;
int l[maxn];

int solve (int maxL, int K) {
    int left = 0, right = maxL, mid;
    while (left < right)
    {
        mid = (right - left)/2;
        int num = 0; // 切割后的真实木棒数量
        for(int i=0;i<3;i++)
        {
            num += l[i]/mid;
        }
        if (num < K) { // 还没到达所需要的木棒数, 在右区间划分
            left = mid;
        } else {
            right = mid;
        }
    }
    return mid;
}

int main () 
{
    int n, K, k;
    scanf("%d", &n); // 木棒数量
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }
    scanf("%d", &K); // 需要切割的木棒数量
    int* maxL = max_element(l, l+n);
    printf("%d", solve(*maxL, K)); // 求最接近K的最大长度
    return 0;
}
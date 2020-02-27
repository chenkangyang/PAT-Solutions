/*
 * @Description: 输出stack中的中位数, 使用树状数组，hash数组记录每一个元素出现的次数
 * 第K大就是在求最小的i，使得hash[1]+...+hash[i]>=K 成立, 
 * 即找最大的i使得 getSum(i) >= K; 
 * X位置时元素总出现个数: c[x] = hash[x-lowbit(x)+1] + ... + hash[x]
 * 求前x个元素的个数: getSum(x) = hash[1] + ... + hash[x] = getSum(x-lowbit(x)) + c[x]
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-25 22:46:03
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-05 19:25:00
 */

#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
#define lowbit(x) ((x)&(-x))

const int MAXN = 100010;
stack<int> st;
int n;
int c[MAXN]; // 树状数组, 表示lowbit范围内的元素个数和


int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i-= lowbit(i)) // 没有c[0], 从c[1]开始
    {
        sum += c[i];
    }
    return sum;
}

void update(int x, int v) { // x位置填上v
    for (int i = x; i < MAXN; i+=lowbit(i))
    {
        c[i] += v;
    }
}

int PeekMedian() {
    int len = st.size();
    int K = len%2? (len+1)/2 : len/2; // 找第中间大的数, 一半的数有K个
    int l = 1, r = MAXN, mid;
    while (l < r)
    {
        mid = l + (r-l)/2;
        if (getSum(mid) >= K) // 所求位置的元素个数过多, 则所求位置应该在mid或者mid左边
        {
            r = mid;
        } else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    scanf("%d", &n);
    char cmd[20];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "Pop") == 0)
        {
            if (st.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                int num = st.top();
                update(num, -1);
                st.pop();
                printf("%d\n", num);
            }
        } else if(strcmp(cmd, "Push") == 0)
        {
            int num = 0;
            scanf("%d", &num);
            update(num, 1);
            st.push(num);
        } else if (strcmp(cmd, "PeekMedian") == 0)
        {
            if (st.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                printf("%d\n", PeekMedian());
            }
        }
    }
    
    
    return 0;
}

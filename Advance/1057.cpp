/*
 * @Description: 输出stack中的中位数, 将范围10^5分块, 将所有的数hash到对应位置，转化为找第K（中位数）大的数
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-25 22:46:03
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-26 00:05:05
 */

#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
const int MAXN = 100010;
stack<int> st;
int block[317]; // 共317块，每块中含有316个元素
int table[MAXN]; // 各元素存在的个数
int n;

int PeekMedian() {
    int sum = 0;
    int len = st.size();
    int K = st.size()%2? (st.size()+1)/2 : st.size()/2;
    int i; // 块号
    for (i = 0; i < 317; i++) // 遍历块
    {
        if (sum + block[i] < K)
        {
            sum += block[i];
        }
        else
        {
            break;
        }
    }
    // printf("sum:%d, i=%d, K=%d\n", sum,i,K);
    for (int j = 316 * i; j < 316 * i + 316; j++) // 遍历块内的316个元素
    {
        // printf("j:%d\n", j);
        sum = sum + table[j];
        if (sum >= K)
        {
            return j;
        }
    }

    return sum;
}

int main() {
    scanf("%d", &n);
    char cmd[20];
    memset(table, 0, sizeof(table));
    memset(block, 0, sizeof(block));
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
                table[num]--;
                block[num/316]--;
                st.pop();
                printf("%d\n", num);
            }
        } else if(strcmp(cmd, "Push") == 0)
        {
            int num = 0;
            scanf("%d", &num);
            table[num]++;
            block[num/316] ++;
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

/*
 * @Description: 输出最早进入和最晚离开的ID, ID_number Sign_in_time Sign_out_time
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-23 23:30:36
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-23 23:53:55
 */

#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

const int maxn = 100;
const int maxl = 16;
struct stduent {
    char ID[maxl];
    int in_time, out_time;
}S[maxn];

int main () {
    int n, min = INT_MAX, max = INT_MIN;
    char in[maxl], out[maxl];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", S[i].ID);
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d", &h1, &m1, &s1);
        S[i].in_time = 3600*h1+60*m1+s1;
        scanf("%d:%d:%d", &h2, &m2, &s2);
        S[i].out_time = 3600*h2+60*m2+s2;
        if (min > S[i].in_time) {
            min = S[i].in_time;
            strcpy(in, S[i].ID);
        }
        if (max < S[i].out_time) {
            max = S[i].out_time;
            strcpy(out, S[i].ID);
        }
    }
    printf("%s %s\n", in, out);
    return 0;
}


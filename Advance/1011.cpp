/*
 * @Description: 输出每行最大值和下标
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-30 22:01:51
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-30 22:29:35
 */

#include <cstdio>
#include <algorithm>
using namespace std;

char S[3] = {'W', 'T', 'L'};
double M[3] = {0};
int Index[3] = {0};
int main () {
    for (int i = 0; i < 3; i++)
    {
        double l[3];
        scanf("%lf %lf %lf", &l[0], &l[1], &l[2]);
        int index = -1;
        double max = -1;
        for (int j = 0; j < 3; j++)
        {
            if (l[j] > max)
            {
                max = l[j];
                index = j;
            }
        }
        M[i] = max;
        Index[i] = index;
    }
    
    double ans = (M[0]*M[1]*M[2] * 0.65 - 1)*2;
    printf("%c %c %c %.2f",S[Index[0]],S[Index[1]],S[Index[2]], ans);
    return 0;
}
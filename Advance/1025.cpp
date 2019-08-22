#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct S
{
    char id[15];      // 准考证号
    int score;        // 分数
    int location_num; // 考场号
    int local_rank;   // 考场内排名
} s[30001];

bool cmp(S a, S b)
{
    if (a.score != b.score)
    {
        return a.score > b.score;
    }
    else
    {
        return strcmp(a.id, b.id) < 0;
    }
}

int main()
{
    int n, k, num = 0, loc_num = 1;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%s %d", s[num].id, &s[num].score);
            s[num].location_num = loc_num;
            num++;
        }
        sort(s + num - k, s + num, cmp);
        s[num - k].local_rank = 1;
        int step = 1;
        for (int i = num - k + 1; i < num; i++)
        {
            if (s[i].score == s[i - 1].score)
            {
                s[i].local_rank = s[i - 1].local_rank;
                step++;
            }
            else
            {
                s[i].local_rank = s[i - 1].local_rank + step;
                step = 1;
            }
        }
        loc_num++;
    }
    sort(s, s + num, cmp);
    int final_rank = 0, step = 1;
    printf("%d\n", num);
    for (int i = 0; i < num; i++)
    {
        if (i > 0 && s[i].score == s[i - 1].score)
        {
            step++;
        }
        else
        {
            final_rank += step;
            step = 1;
        }
        printf("%s %d %d %d\n", s[i].id, final_rank, s[i].location_num, s[i].local_rank);
    }
    return 0;
}
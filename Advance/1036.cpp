/*
 * @Description: 分类别输出最大和最小
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-30 22:26:56
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-30 22:49:54
 */

#include <cstdio>
#include <cstring>

struct Stu {
    char name[30];
    char gender;
    char ID[30];
    int grade;
};

int main () {
    int cnt;
    scanf("%d", &cnt);
    Stu temp, F, M;
    F.grade = -1;
    M.grade = 101;
    int m = 0, f = 0;
    for (int i = 0; i < cnt; i++)
    {
        scanf("%s %c %s %d", temp.name, &temp.gender, temp.ID, &temp.grade);
        if (temp.gender == 'M') {
            m ++;
            if (temp.grade < M.grade)
            {
                strcpy(M.name, temp.name);
                M.grade = temp.grade;
                M.gender = 'M';
                strcpy(M.ID, temp.ID);
            }
        }
        else {
            f ++;
            if (temp.grade > F.grade)
            {
                strcpy(F.name, temp.name);
                F.grade = temp.grade;
                F.gender = 'F';
                strcpy(F.ID, temp.ID);
            }
        }
    }
    if (f)
    {
        printf("%s %s\n", F.name, F.ID);
    } else if (!f)
    {
        printf("Absent\n");
    }
    if (m)
    {
        printf("%s %s\n", M.name, M.ID);
    } else if (!m)
    {
        printf("Absent\n");
    }
    if (!m || !f)
    {
        printf("NA\n");
    } else
    {
        printf("%d\n", F.grade - M.grade);
    }
    return 0;
}
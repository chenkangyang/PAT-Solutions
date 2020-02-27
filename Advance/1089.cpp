/*
 * @Description: 判断归并排序还是
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-06 22:35:37
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 23:42:07
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 105;
int n;
int origin[MAXN], temp[MAXN], current[MAXN];

bool isSame(int a[], int b[]) {
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i]) 
        {
            return false;
        }
    }
    return true;
}

void showArray(int a[]) {
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n-1) printf(" ");
    }
    printf("\n");
}

bool insertSort() {
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (i != 1 && isSame(temp, current)) // 不能是初始序列
        {
            flag = true;
        }
        sort(temp, temp+i+1);
        if (flag == true)
        {
            return true;
        }
    }
    return false;
}

void MergeSort() {
    int k = 1, flag = true; // k:每段长度
    while(flag) {
        if(k != 1 && isSame(temp, current)) { // 相同的话, 再归并一次, 退出
            flag = false;
        }
        k = k * 2;
        for (int i = 0; i < n / k; i++) // 排序每段
            sort(temp + i * k, temp + (i + 1) * k);
        sort(temp + n / k * k, temp + n); // 排序剩余
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &origin[i]);
        temp[i] = origin[i];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &current[i]);
    }
    if (insertSort())
    {
        printf("Insertion Sort\n");
        showArray(temp);
    } else
    {
        printf("Merge Sort\n");
        for (int i = 0; i < n; i++)
        {
            temp[i] = origin[i];
        }
        MergeSort();
        showArray(temp);
    }
    return 0;
}
/*
 * @Description: 给一个堆排序或者插入排序的中间结果, 问是那种排序, 并输出下一次迭代的结果
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-21 23:01:47
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-22 07:31:37
 */

#include <cstdio>

const int maxn = 101;
int n;
// 由于heap中的下标有2*i的操作, i!=0, 因此heap从index=1开始存
int origin[maxn], part[maxn], next[maxn], heap[maxn];

bool cmp(int a[], int b[]) { // 比较a数组和b数组是否相同
    bool flag = true;
    int i = 0;
    while (flag && i < n) // flag = true 或比对完成后, 退出循环
    {
        if (a[i] != b[i]){
            flag = false;
        }
        i++;
    }
    return flag;
}

void insertSort(int a[]) {
    // 在前面有序序列中找一个位置, 插入无序序列中第一个元素
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        int temp = a[i]; // 待插入元素
        int j = i; // 从i位置开始向前找插入位置j
        while (j > 0 && temp < a[j-1]) // 待插入元素更小
        {
            // 将j的前一个元素挪到当前元素处, 空出j的位置
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp; // 填充空位
        if (cmp(a, part) && flag)
        {
            printf("Insertion Sort\n");
            flag = false;
        }
        else if (!flag) {
            for (int i = 0; i < n; i++)
            {
                printf("%d", a[i]);
                if (i != n-1)   printf(" ");
            }
            break; // 停止排序
        }
    }
}

void downAdjust(int low, int high) {
    int i = low, j = i*2;
    while (j <= high) // 存在左孩子, 即非叶子节点
    {
        if (j+1 <= high && heap[j] < heap[j+1]) // j赋值给左右孩子中大的那个
        {
            j = j+1;
        }
        if (heap[j] > heap[i]) // 若根节点最小, 交换孩子中最大的到根节点
        {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
            j = i*2;
        } else
        {
            break;
        }
    }
}

void create_heap() { // 将数组改造成堆
    for (int i = n/2; i >= 1 ; i--) // 对前n/2个非叶子节点向下调整建堆
    {
        downAdjust(i, n);
    }
}

void heap_sort() {
    bool flag = true;
    create_heap();
    for (int i = n; i > 1; i--)
    {
        int temp = heap[i];
        heap[i] = heap[1];
        heap[1] = temp;
        downAdjust(1, i -1);
        
        if (cmp(heap+1, part) && flag)
        {
            printf("Heap Sort\n");
            flag = false;
        }
        else if (!flag) {
            for (int i = 1; i <= n; i++)
            {
                printf("%d", heap[i]);
                if (i != n)   printf(" ");
            }
            break; // 停止排序
        }
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &origin[i]);
        heap[i+1] = origin[i];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &part[i]);
    }
    insertSort(origin);
    heap_sort();
    return 0;
}
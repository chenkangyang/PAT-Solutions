/*
 * @Description: 链表排序
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-18 21:31:51
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-06 21:03:46
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct  Node
{
    int address;
    int key;
    int next;
    bool flag; // 该节点是否有效
}node[maxn];


bool cmp(Node a, Node b) {
    // 至少一个节点无效，把它向后移动, 有效节点falg=1, 
    // 大于无效节点, 按flag从大到校排序, 有效节点移动到数组最左端
    if(a.flag == false || b.flag == false) { 
        return a.flag > b.flag;
    } else
    {
        return a.key < b.key;
    }
}
int main() {
    int n, begin;
    scanf("%d%d", &n, &begin);
    // falg 初始化为 false
    for (int i = 0; i < maxn; i++)
    {
        node[i].flag = false;
    }
    // printf("n:%d, begin:%d\n", n, begin);

    // 读入数据
    int address;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &address);
        scanf("%d%d",&node[address].key, &node[address].next);
        node[address].address = address;
    }
    // 遍历link list，更新有效节点标记
    int cnt = 0;
    for(int p = begin; p != -1; p = node[p].next) {
        // printf("address:%d, key:%d, next:%d\n",node[p].address, node[p].key, node[p].next);
        node[p].flag = true;
        cnt++;
    }
    
    if (cnt == 0) // 没有节点时候输出
    {
        printf("0 -1");
    }
    else
    {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", cnt, node[0].address);
        for (int i = 0; i < cnt; i++)
        {
            printf("%05d %d",node[i].address, node[i].key);
            if (i == cnt - 1)
            {
                printf(" -1\n");
            }
            else
            {
                printf(" %05d\n", node[i+1].address);
            }
        }
    }
    return 0;
}
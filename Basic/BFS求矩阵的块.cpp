/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-19 21:32:33
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-19 21:51:26
 */

// m*n 的矩阵, 若矩阵中有若干个1是相邻(上下左右)的(不必两两相邻), 那么称这些1 构成了一个快. 求给定矩阵中块的个数
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100;

struct node {
    int x, y;
} Node;

int n, m; // 矩阵大小为 n*m
int matrix[maxn][maxn]; // 01矩阵
bool inq[maxn][maxn] = {false}; //记录位置(x,y)是否在BFS中已入过队
int X[4] = {0, 0, 1, -1}; //增量数组
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y) { // 判断坐标(x,y)是否需要访问
    if (x >= n || x < 0 || y >= m || y < 0) return false;
    if (matrix[x][y] == 0 || inq[x][y] == true) return false;
    return true;        
}

void BFS(int x, int y) {
    queue<node> Q; // 定义队列
    Node.x = x, Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while (!Q.empty()) 
    {
        node top = Q.front(); // 取出队首元素
        Q.pop();
        for (int i = 0; i < 4; i++) // 循环上下左右4个相邻位置
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)) {
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            scanf("%d", &matrix[x][y]);
        }
    }
    int ans = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            // 如果元素为1, 且未入过队
            if (matrix[x][y] == 1 && inq[x][y] == false)
            {
                ans ++; // 块数加一
                BFS(x, y); // 访问整个块, 将该块所有的 "1" 都标记为true
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
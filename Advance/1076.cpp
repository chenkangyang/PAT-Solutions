/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-08-22 07:33:52
 * @LastEditors: Alex
 * @LastEditTime: 2019-08-22 09:37:51
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int MAXV = 1010; // 最大顶点数
struct Node {
    int id, layer;
};

vector<Node> Adj[MAXV]; // 邻接表
bool inq[MAXV] = {false}; // 顶点是否已被假如过队列

int BFS(int s, int L) { // 返回转发数量
    int numForward = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        int u = now.id;
        for (unsigned int i = 0; i < Adj[u].size(); i++)
        {
            Node next = Adj[u][i];
            // printf("now:%d, next:%d\n", u, next.id);
            next.layer = now.layer + 1;
            if (inq[next.id] == false && next.layer <= L) // 没访问过且层数不超过L, 则访问, 更新转发数
            {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}

int main() {
    Node user;
    int n, L, numFollow, idFollow;
    scanf("%d%d", &n, &L); // 结点个数, 层数上限
    for (int i = 1; i <= n; i++)
    {
        user.id = i;
        scanf("%d", &numFollow); // i号用户关注的人数
        for (int j = 0; j < numFollow; j++)
        {
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user); // 关注者 -> i号用户
        }
    }
    int numQuery, s;
    scanf("%d", &numQuery);
    for (int i = 0; i < numQuery; i++)
    {
        scanf("%d", &s);
        memset(inq, false, sizeof(inq)); // 需要头文件 string.h
        int numForward = BFS(s, L);
        printf("%d\n", numForward);
    } 
    return 0;

}
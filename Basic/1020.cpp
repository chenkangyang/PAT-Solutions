#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake
{
    double store; // 库存量
    double sell; // 总售价
    double price; // 单价
}cake[1010];

bool cmp(mooncake a, mooncake b) {
    return a.price > b.price;
}

int main () {
    int n, d;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].store);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell/cake[i].store; // 单价
    }
    sort(cake, cake + n, cmp);
    double ans;
    for (int i = 0; i < n; i++)
    {
        if (cake[i].store <= d) {
            ans += cake[i].sell;
            d -= cake[i].store;
        } else
        {
            ans += d*cake[i].price;
            d = 0;
        }
    }
    printf("%.2f", ans);
    return 0;
}
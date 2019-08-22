// 素数
#include <iostream>
using namespace std;

// 素数对猜想：存在无穷多对相邻且差为2的素数
// 素数1，3，5，7，9
bool isprim (int a) {
    for (int i = 0; i*i < a; i++) {
        if (a%i == 0)
            return false;
        else
            return true; 
    }
}

int main ()
{
    int N, cnt=0;
    cin >> N;
    for (int i = 5; i < N; i++)
    {
        if (isprim(i-2) && isprim(i))
            cnt ++;
    }
    cout << cnt;
    return 0;
}
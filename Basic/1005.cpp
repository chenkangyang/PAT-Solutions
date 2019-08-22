// Hash散列
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 给定一系列待验证的数字, 找出关键数字(模拟递推过程, 遇到的数字标记为1, 剩下不被覆盖(不需要重复验证)的数为关键数字), 并按从大到小的顺序输出它们。

int arr[10000];

bool cmp(int a, int b) {return a > b;}

int main () {
    int count, n, flag=0;
    cin >> count;
    vector<int> v(count);
    for (int i = 0; i < count; i++) {
        cin >> n;
        v[i] = n;
        while (n!=1) {
            if (n % 2 ==0)
            {
                n=n/2;
                if (arr[n] == 1) break;
                arr[n] = 1;
            } else if (n % 2 == 1) {
                n = (3 * n + 1) / 2;
                if (arr[n] == 1) break;
                arr[n] = 1;
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        if(!arr[v[i]]) {
            if (flag == 1)
                cout << " ";
            cout << v[i];
            flag = 1;
        }
    }
    return 0;
}
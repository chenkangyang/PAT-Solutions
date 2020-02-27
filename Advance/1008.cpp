/*
 * @Description: 模拟
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-03 22:13:05
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-03 22:20:58
 */

#include <iostream>
using namespace std;

int main () {
    int a, now = 0, sum = 0;
    cin >> a;
    while(cin >> a) {
        if (a > now)
            sum = sum + 6 * (a -now);
        else {
            sum = sum - 4 * (now - a);
        }
        now = a;
        sum += 5;
    }
    cout << sum;
    return 0;
}
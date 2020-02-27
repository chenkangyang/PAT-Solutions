/*
 * @Description: PAT的个数为A左侧P的个数*A右侧T的个数
 * 先计算所有的T的个数, 然后从前往后遍历, A左边T的个数 = 总个数-左边T的个数
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 09:54:33
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 10:04:33
 */
#include <iostream>
#include <string>
using namespace  std;

int main () {
    string s;
    cin >> s;
    int cntp = 0, cntt = 0, ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'T')
            cntt++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'T') cntt--;
        if (s[i] == 'P') cntp++;
        if (s[i] == 'A') ans = (ans + (cntt*cntp)%1000000007)%1000000007;
    }
    cout << ans;
    
    return 0;
}
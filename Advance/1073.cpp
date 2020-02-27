/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2020-02-28 01:33:59
 * @LastEditors: Alex
 * @LastEditTime: 2020-02-28 02:19:51
 */

#include <iostream>
using namespace std;
int main () {
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != 'E') i++;
    string bf = s.substr(1, i-1); // E之前除去符号位的串
    int exp = stoi(s.substr(i+1)); // 指数
    if (s[0] == '-') cout << "-";
    if (exp < 0) {
        cout << "0.";
        int left_zero = abs(exp)-1;
        while (left_zero --) cout << '0';
        for (int j = 0; j < bf.length(); j++)
            if (bf[j] != '.') cout << bf[j];
    } else {
        if (bf[0] != 0) cout << bf[0];
        int left = bf.length() - 2;
        if (left <= exp) { // +1.2E+3
            for (int j = 2; j < bf.length(); j++) cout << bf[j];
            int lleft = exp-left;
            while (lleft--) cout << '0';
        }
        else // +1.2345E+2
        {
            int cnt = 0;
            for (int j = 2; j < bf.length(); j++, cnt++)
            {
                if (cnt == exp) cout << '.';
                cout << bf[j];
            } 
        }
    }
}
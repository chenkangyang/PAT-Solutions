//
// Created by 陈康扬 on 2019-03-30.
//

#include <iostream>
#include <map>
using namespace std;

/*
 * 2. P,T前后字符A长度相同
 * 3. 可以在P和T中间加A并且在T后面加A，要求必须是，中间加上一个A，末尾就得加上几倍的(P前面A的那个字符串)。
 * 换句话说就是，中间的A的个数如果是3，那么末尾的A的个数就得是开头A的个数的3倍。
 * ==》P前字符串A的长度*PT间字符串A的长度 = T后字符串A的长度
 * ie. APATA->APAATAA->APAAATAAA
 * overall: 只能有一个P和T，中间和末尾可以随便插入A。但是必须满足：开头A的个数*中间A的个数=结尾A的个数，而且P和T之间不能没有A
*/


int main() {
    int n, p = 0, t = 0; // p位置， t位置
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        map<char, int> m;
        for (int j = 0; j < s.size(); j++) {
            m[s[j]]++;
            if (s[j] == 'P') p = j;
            if (s[j] == 'T') t = j;
        }
        if (m['P'] == 1 && m['A'] != 0 && m['T'] == 1 && m.size() == 3 && t-p != 1 && p * (t-p-1) == s.length()-t-1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
};
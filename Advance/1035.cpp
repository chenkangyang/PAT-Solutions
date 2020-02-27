/*
 * @Description: 模拟
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-04 21:46:02
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-04 22:04:34
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string name, s;
        cin >> name >> s;
        int flag = 0;
        for (int j = 0; j < s.length(); j++)
        {
            switch (s[j])
            {
                case '1' : s[j] = '@'; flag = 1; break;
                case '0' : s[j] = '%'; flag = 1; break;
                case 'l' : s[j] = 'L'; flag = 1; break;
                case 'O' : s[j] = 'o'; flag = 1; break;
            }
        }
        if (flag)
        {
            string temp = name + " " + s;
            v.push_back(temp);
        }
    }
    int m = v.size();
    
    if (m != 0)
    {
        printf("%d\n", m);
        for (int i = 0; i < m; i++)
        {
            cout << v[i] << endl;
        }
    }
    else if (n == 1)
    {
        printf("There is 1 account and no account is modified");
    } else {
        printf("There are %d accounts and no account is modified", n);
    }
    return 0;
}
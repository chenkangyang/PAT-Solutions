/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 21:05:12
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 21:18:57
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

bool check(char c) {
    if (c>='0' && c <= '9') return true;
    if (c>='A' && c <= 'Z') return true;
    if (c>='a' && c <= 'z') return true;
    return false;
}

int main () {
    map <string, int> count;
    string str;
    getline(cin, str);
    int i = 0;
    while (i < str.length()) 
    {
        string word; // 单词
        while (i < str.length() && check(str[i])==true) // 是有效字符
        {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 32; //大写转小写
            }
            word += str[i];
            i++;
        }
        if (word != "") { // 单词非空, 次数加1
            if(count.find(word) == count.end()) count[word] = 1;
            else count[word]++;
        }
        while (i < str.length() && check(str[i])== false) // 跳过非单词字符
        {
            i++;
        }
    }
    string ans;
    int MAX = 0;
    for (map<string, int>::iterator it = count.begin(); it != count.end(); it++)
    {
        if (it->second > MAX) {
            MAX = it->second;
            ans = it->first;
        }
    }
    cout <<ans<<" "<<MAX<<endl;
    return 0;
}
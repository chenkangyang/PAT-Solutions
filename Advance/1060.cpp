/*
 * @Description: 转为科学计数法之后比较
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-07 20:44:27
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-07 20:57:04
 */

#include <iostream>
#include <string>
using namespace std;

int n; // 有效位数

string deal (string s, int &e) { // 指数e初始为0
    int k =0; // s的下标
    while (s.length() > 0 && s[0] == '0') // 去除所有的前缀0
    {
        s.erase(s.begin());
    } 
    if (s[0] == '.') { // 小于1的数字
        s.erase(s.begin());
        while (s.length() > 0 && s[0]=='0')
        {
            s.erase(s.begin());
            e--;
        }
    } else { // 大于1的数
        while (k < s.length() && s[k] != '.')
        {
            k++;
            e++; // 只要不遇到小数, 指数+1
        }
        if (k < s.length()) { // while 结束后, k < s.length(): 遇到了小数点
            s.erase(s.begin() + k); // 将小数点删除
        }
    }
    if (s.length() == 0) {
        e = 0;
    }
    int num = 0;
    k = 0;
    string res;
    while (num < n)  // 1.精度未达到
    {
        if (k < s.length()) res+=s[k++]; // 2.1 只要有数字,就追加到res后
        else res += '0'; // 2.2 否则末尾添加0
        num++;
    }
    return res;
}
int main () {
    string s1, s2, s3, s4; // s3, s4为s1, s2转化的结果
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0; // s1与s2的指数
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if (s3 == s4 && e1 == e2) {
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    } else {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
    }
    return 0;
}
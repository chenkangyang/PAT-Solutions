/*
 * @Description: 字符串处理
 * @Version: 1.0
 * @Autor: Alex
 * @Date: 2019-09-03 21:22:43
 * @LastEditors: Alex
 * @LastEditTime: 2019-09-03 22:13:17
 */

#include <iostream>
#include <string>
using namespace std;

string num2String[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main () {
    string input, output;
    getline(cin, input);
    int sum = 0;
    for (string::iterator it = input.begin(); it != input.end(); it++)
    {
        sum += *it - '0';
    }
    output = to_string(sum);
    cout << num2String[output[0]-'0'];
    for (int i = 1; i < output.length(); i++)
        cout << " " << num2String[output[i] - '0'];

    return 0;
}
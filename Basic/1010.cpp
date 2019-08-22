// 一元多项式求导
#include <iostream>
using namespace std;

// 分析：1.flag用来判断是否已经有过输出～
// 2.当b!=0时，因为给出的是所有非零项系数，所以必定会有输出，先判断flag是否为1，如果为1表示已经有过输出，那么在前面要先输出一个空格
// 3.输出 a * b 和 b – 1，然后将flag标记为1表示已经有过输出
// 4.最后判断当没有输出并且b==0的时候，输出“0 0” 

int main()
{
    int a, b, flag = 0;
    while (cin >> a >> b)
    {
        if (b!=0) {
            if (flag)
            {
                cout << " ";
            }
            cout << a*b << " " << b-1;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "0 0";
    }
    return 0;
}
// 模拟
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 数组元素循环右移问题
// 数组长度为n，要想把数组循环右移m位，只需要先将整个数组a倒置  ，再将数组前m位倒置，最后将数组后n-m位倒置即可完成循环右移m位.
// reverse函数可以实现将一个数组或者vector中元素倒置，这个函数在algorithm头文件中
// 如果m大于n，那么循环右移m位相当于循环右移m%n位，因为那些n倍数位的移动是多余的，所以在使用m之前，先将m = m%n

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    M = M%N;
    if (M != 0) {
        reverse(begin(arr), begin(arr) + N);
        reverse(begin(arr), begin(arr) + M);
        reverse(begin(arr) + M, begin(arr) +N);
    }
    for (int i = 0; i < N-1; i++)
        cout << arr[i] << " ";
    cout << arr[N];
    return 0;
}
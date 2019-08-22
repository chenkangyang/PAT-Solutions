// 查找元素
#include <iostream>
using namespace std;

int main() {
    int n, max = -1, min = 101, score;
    cin >> n;
    string maxname, minname, maxnum, minnum, name, num;
    for (int i = 0; i < n; i++) {
        cin >> name >> num >> score;
        if (score > max) {
            max = score;
            maxname = name;
            maxnum = num;
        }
        if (score < min)
        {
            min = score;
            minname = name;
            minnum = num;
        }
    }
    cout << maxname << " " << maxnum << endl << minname << " " << minnum;
    return 0;
}
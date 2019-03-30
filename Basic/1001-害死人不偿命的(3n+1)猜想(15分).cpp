//
// Created by 陈康扬 on 2019-03-18.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    int count = 0;
    cin>>n;
    while (n!=1) {
        if (n % 2 ==0)
        {
            n=n/2;
        } else if (n % 2 == 1) {
            n = (3 * n + 1) / 2;
        }
        count ++;
    }
    cout<<count;
    return 0;
}
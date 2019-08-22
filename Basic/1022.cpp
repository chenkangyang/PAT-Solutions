#include <cstdio>

int main() {
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    int sum = a + b;
    int z[31], num = 0;
    do {
        z[num++] = sum % d;
        sum /= d;
    }while (sum != 0);
    while (num --)
    {
        printf("%d", z[num]);
    }
    return 0;
}
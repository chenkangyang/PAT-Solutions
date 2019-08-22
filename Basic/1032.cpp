#include <cstdio>

const int maxn = 100000;

int school[maxn] = {0}; 

int main () {
    int n, ID, score;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ID, &score);
        school[ID] += score;
    }
    int max = -1, k = -1;
    for (int i = 1; i <= n; i++) {
        if (max < school[i]) {
            max = school[i];
            k = i;
        }
    }
    printf("%d %d", k, max);
}
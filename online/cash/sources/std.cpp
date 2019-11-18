#include <cstdio>

int main() {
    constexpr int cash[] = {100, 50, 20, 10, 5, 1};
    int n;
    scanf("%d", &n);
    for (int v : cash) {
        printf("%d ", n / v);
        n %= v;
    }
    return 0;
}
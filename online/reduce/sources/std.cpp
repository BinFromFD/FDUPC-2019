#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

int main() {
    long long a, b;
    scanf("%lld/%lld", &a, &b);
    long long r = __gcd(a, b);
    printf("%lld/%lld\n", a / r, b / r);
    return 0;
}
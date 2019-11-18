#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

#define NMAX 100000

static int n, m;
static char S[NMAX + 10], T[NMAX + 10];

int main() {
    scanf("%s%s", S + 1, T + 1);
    n = strlen(S + 1);
    m = strlen(T + 1);
    int mx = -1, mxp;
    for (int i = 1; i <= n; i++) {
        int j = i, k = 0;
        for ( ; j <= n && S[j] == T[k % m + 1]; j++, k++) ;
        int len = j - i;
        if (len > mx) {
            mx = len;
            mxp = i;
        }
    }
    printf("%d\n", mxp);

    return 0;
}
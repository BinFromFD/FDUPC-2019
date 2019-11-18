#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

#define NMAX 100000

static int n, m;
static char S[NMAX + 10], T[NMAX + 10];
static int bor[NMAX + 10];
static int lcp[NMAX + 10];

void exkmp() {
    for (int i = 2, j = 0; i <= m; i++) {
        for ( ; j && T[j + 1] != T[i]; j = bor[j]) ;
        if (T[j + 1] == T[i]) j++;
        bor[i] = j;
    }
    memset(lcp + 1, 0, sizeof(int) * n);
    for (int i = 1, j = 0; i <= n; i++) {
        for ( ; j && T[j + 1] != S[i]; j = bor[j])
            lcp[i - j] = j;
        if (T[j + 1] == S[i]) j++;
        if (i == n) {
            for ( ; j; j = bor[j])
                lcp[i - j + 1] = j;
        }
    }
}

int main() {
    scanf("%s%s", S + 1, T + 1);
    n = strlen(S + 1);
    m = strlen(T + 1);
    exkmp();
    for (int i = n; i >= 1; i--)
        if (lcp[i] == m) lcp[i] += lcp[i + m];
    int mx = -1, mxp;
    for (int i = 1; i <= n; i++) if (lcp[i] > mx) {
        mx = lcp[i];
        mxp = i;
    }
    printf("%d\n", mxp);

    return 0;
}
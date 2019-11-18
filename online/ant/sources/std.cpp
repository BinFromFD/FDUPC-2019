#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
char s[maxn + 1];

int main() {
  while (~scanf ("%s", s)) {
    int l = strlen(s), n = 0;
    if (l < 3) {
      double ans = 1;
      for (int i = 0; i < l; i++) n = n * 10 + s[i] - '0';
      while (n--) ans = (1 - ans) / 3;
      printf ("%.16lf\n", ans);
    }
    else printf ("%.16lf\n", 1.0 / 4);
  }
  return 0;
}

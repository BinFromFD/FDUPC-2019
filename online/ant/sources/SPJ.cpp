#include <cmath>
#include <cstdio>
#include <cctype>

#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

#define ACCEPTED 0
#define WRONG_ANSWER 1
#define ERROR -1

#define ASSERT(x) if (!(x)) exit(WRONG_ANSWER);

#define EPS 1e-7

typedef long double ld;

ld eval(int n) {
    if (n > 500) return 0.25;
    ld ans = 1;
    while (n--) ans = (1 - ans) / 3;
    return ans;
}

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]), fout(argv[2]);

    int n;
    fin >> n;
    ld std = eval(n);

    string tmp;
    fout >> tmp;
    ASSERT(tmp.size() < 50);
    for (char c : tmp) ASSERT(c == '.' || isdigit(c));
    int dot_cnt = 0;
    for (char c : tmp) dot_cnt += c == '.';
    ASSERT(dot_cnt <= 1);

    ld usr = strtold(tmp.c_str(), NULL);
    printf("std=%.8Lf, usr=%.8Lf\n", std, usr);
    ASSERT(fabs(std - usr) < EPS);

    return ACCEPTED;
}
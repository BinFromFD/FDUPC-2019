#include "../../testlib.h"
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
#define LIM 10000000LL

LL n;
LD ans;

int main()
{
	ascanf("%lld", &n);
	Eoln();
	Eof();
	CheckRange(n, 0, 1000000000000000000LL);
	n = min(n, LIM);
	LD tmp = LD(3) / 4;
	for (int i = 1; i <= n; i ++)
		tmp = -tmp / 3;
	ans = LD(1) / 4 + tmp;
	printf("%.6Lf\n", ans);
	int _7th_digit = int(llround(floor(ans * 10000000)) % 10);
	if (_7th_digit == 4 || _7th_digit == 5)
		fprintf(stderr, "Warning, 7-th digit = %d\n", _7th_digit);
	return 0;
}

#include "../../testlib.h"
#include <cstdio>
#include <algorithm>
using namespace std;

static const constexpr int Cash[] = {100, 50, 20, 10, 5, 1}, cnt = sizeof(Cash) / sizeof(int);
int n, Cnt[cnt];

int main()
{
	ascanf("%d", &n);
	Eof();
	CheckRange(n, 1, 50000);
	for (int i = 0; i < cnt; i ++)
		for (; n >= Cash[i]; n -= Cash[i], Cnt[i] ++) ;
	for (int i = 0; i < cnt; i ++)
		printf("%d ", Cnt[i]);
	puts("");
	return 0;
}

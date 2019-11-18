#include "../../testlib.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int lens, lent;
char s[N], t[N];

namespace Std1
{
	int mx, id = 1, Next[N], Match[N], L[N];
	bool Ok[N];
	void Solve()
	{
		reverse(s, s + lens);
		reverse(t, t + lent);
		for (int i = 0; i < lens; i ++)
			CheckRange(s[i], 'a', 'z');
		for (int i = 0; i < lent; i ++)
			CheckRange(t[i], 'a', 'z');
		for (int j = 0, k = Next[0] = -1; j < lent; Next[++ j] = ++ k)
			for (; ~k && t[j] != t[k]; k = Next[k]) ;
		for (int i = 0, j = 0, cur = 0; i < lens; )
		{
			for (; ~j && s[i] != t[j]; j = Next[j]) ;
			Match[++ i] = ++ j;
			if (j == lent)
				j = Next[j], Ok[i] = 1;
		}
		for (int i = lens - lent; i >= 0; i --)
			L[i] = Ok[i + lent] ? (L[i + lent] + lent) : 0;
		for (int i = lens - 1; i >= 0; i --)
			if (L[i] + Match[i] > mx)
				mx = L[i] + Match[i], id = lens - i - L[i] + 1;
		printf("%d\n", id);
	}
}

namespace Std2
{
	int mx = 0, id = 1, Next[N];
	void Solve()
	{
		for (int prel = lent; lent < lens; t[lent] = t[lent - prel], lent ++) ;
		for (int j = 0, k = Next[0] = -1; j < lent; Next[++ j] = ++ k)
			for (; ~k && t[j] != t[k]; k = Next[k]) ;
		for (int i = 0, j = 0, cur = 0; i < lens; )
		{
			for (; ~j && s[i] != t[j]; j = Next[j]) ;
			i ++, j ++;
			if (j > mx)
				mx = j, id = i - j + 1;
		}
		printf("%d\n", id);
	}
}

int main()
{
	ascanf("%s", s);
	Eoln();
	ascanf("%s", t);
	//Eoln();
	Eof();
	lens = strlen(s), lent = strlen(t);
	CheckRange(lens, 1, 100001);
	CheckRange(lent, 1, 100000);
	//Std1::Solve();
	Std2::Solve();
	return 0;
}

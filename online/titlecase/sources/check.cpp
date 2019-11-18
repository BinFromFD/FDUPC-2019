#include "../../testlib.h"
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100000 + 5

int n, cnt;
char s[N];

bool IsAlpha(char ch)
{
	if ('A' <= ch && ch <= 'Z')
		return true;
	if ('a' <= ch && ch <= 'z')
		return true;
	return false;
}

char ToLower(char ch)
{
	ASSERT(IsAlpha(ch), "Invalid character " + string({ch}));
	return ('A' <= ch && ch <= 'Z') ? ch - 'A' + 'a' : ch;
}

char ToUpper(char ch)
{
	ASSERT(IsAlpha(ch), "Invalid character " + string({ch}));
	return ('A' <= ch && ch <= 'Z') ? ch : ch - 'a' + 'A';
}

int main()
{
	ASSERT(fgets(s, N, stdin) != NULL, "invalid input format");
	Eof();
	n = strlen(s);
	if (s[n - 1] != '\n')
	{
		fprintf(stderr, "No End Line Character\n");
		s[n ++] = '\n';
	}
	for (int l = 0, r; l < n; l = r + 1, cnt ++)
	{
		ASSERT(IsAlpha(s[l]), "invalid input data");
		for (r = l; IsAlpha(s[r]); r ++) ;
		ASSERT(s[r] == (r == n - 1 ? '\n' : ' '), "invalid split character : s[" + to_string(r) + "] = " + to_string(int(s[r])));
		ASSERT(r - l <= 20, to_string(cnt + 1) + "-th word is too long, length = " + to_string(r - l));
		for (int i = l; i < r; i ++)
			s[i] = (i == l) ? ToUpper(s[i]) : ToLower(s[i]);
	}
	ASSERT(cnt <= 100, "too many words, cnt = " + to_string(cnt));
	printf("%s", s);
	return 0;
}

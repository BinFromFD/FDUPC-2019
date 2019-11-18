#include "../../testlib.h"
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000 + 5
#define LIM 100000000000000000LL

char s[N];
string str;
LL a, b;

bool read(LL *x, string::const_iterator st, string::const_iterator ed)
{
	if (st == ed)
		return false;
	*x = 0;
	for (string::const_iterator it = st; it != ed; it ++)
	{
		CheckRange(*it, '0', '9');
		if ((*x) >= LIM)
			return false;
		(*x) = (*x) * 10 + (*it) - '0';
	}
	return true;
}

int main()
{
	ascanf("%s", s);
	//Eoln();
	Eof();
	str = string(s);
	size_t pos = str.find('/');
	ASSERT(pos != string::npos, "'/' not found");
	ASSERT(read(&a, str.cbegin(), str.cbegin() + pos), "invalid a");
	ASSERT(read(&b, str.cbegin() + pos + 1, str.cend()), "invalid b");
	LL d = __gcd(a, b);
	printf("%lld/%lld\n", a / d, b / d);
	return 0;
}

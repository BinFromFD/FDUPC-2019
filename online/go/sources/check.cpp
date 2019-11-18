#include "../../testlib.h"
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<bool, int> Pbi;
#define N 99
#define mp make_pair

static const constexpr int Fx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int ans;
char Map[N][N];
bool Vis[N][N];

Pbi dfs(int x, int y)
{
	Vis[x][y] = 1;
	Pbi res = mp(false, 1);
	for (int k = 0; k < 4; k ++)
	{
		int tx = x + Fx[k][0], ty = y + Fx[k][1];
		if (1 <= tx && tx <= 19 && 1 <= ty && ty <= 19)
		{
			if (Map[tx][ty] == '+' && !Vis[tx][ty])
			{
				Pbi tmp = dfs(tx, ty);
				res.first |= tmp.first;
				res.second += tmp.second;
			}
			else if (Map[tx][ty] == '.')
				res.first = true;
		}
	}
	return res;
}

int Calc()
{
	for (int i = 1; i <= 19; i ++)
		for (int j = 1; j <= 19; j ++)
			Vis[i][j] = 0;
	int ret = 0;
	for (int i = 1; i <= 19; i ++)
		for (int j = 1; j <= 19; j ++)
			if (Map[i][j] == '+' && !Vis[i][j])
			{
				Pbi p = dfs(i, j);
				if (p.first == false)
					ret += p.second;
			}
	return ret;
}

void Check()
{
	int cnt = 0;
	for (int i = 1; i <= 19; i ++)
		for (int j = 1; j <= 19; j ++)
		{
			ASSERT(Map[i][j] == '.' || Map[i][j] == '+' || Map[i][j] == 'o', "invalid character : s[" + to_string(i) + "][" + to_string(j) + "] = " + Map[i][j]);
			cnt += (Map[i][j] == '.');
		}
	if (cnt < 2)
		fprintf(stderr, "Warning : blank cell count = %d\n", cnt);
	cnt = Calc();
	ASSERT(cnt == 0, "pre-died black chess count = " + to_string(cnt));
}

int main()
{
	for (int i = 1; i <= 19; i ++)
	{
		ascanf("%s", Map[i] + 1);
		ASSERT(strlen(Map[i] + 1) == 19, "invalid map length");
		Eoln();
	}
	Eof();
	Check();
	for (int i = 1; i <= 19; i ++)
		for (int j = 1; j <= 19; j ++)
			for (int _i = 1; _i <= 19; _i ++)
				for (int _j = 1; _j <= 19; _j ++)
					if ((i != _i || j != _j) && Map[i][j] == '.' && Map[_i][_j] == '.')
					{
						Map[i][j] = Map[_i][_j] = 'o';
						ans = max(ans, Calc());
						Map[i][j] = Map[_i][_j] = '.';
					}
	printf("%d\n", ans);
	return 0;
}

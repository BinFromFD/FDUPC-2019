#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

#define NMAX 20
#define W 'o'
#define B '+'
#define E '.'

static char mat[32][32];
static bool vis[32][32];

void dfs(int x, int y, char c) {
    if (vis[x][y] || (mat[x][y] != c && mat[x][y] != E))
        return;
    vis[x][y] = true;

    constexpr int dx[] = {1, -1, 0, 0};
    constexpr int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        dfs(tx, ty, c);
    }
}

int main() {
    for (int i = 1; i <= 19; i++)
        scanf("%s", mat[i] + 1);
    for (int i = 0; i <= 20; i++)
        mat[0][i] = mat[20][i] = mat[i][0] = mat[i][20] = W;

    int ans = 0;
    for (int x1 = 1; x1 <= 19; x1++)
    for (int y1 = 1; y1 <= 19; y1++) if (mat[x1][y1] == E)
    for (int x2 = 1; x2 <= 19; x2++)
    for (int y2 = 1; y2 <= 19; y2++) if ((x1 != x2 || y1 != y2) && mat[x2][y2] == E) {
        memset(vis, 0, sizeof(vis));
        mat[x1][y1] = mat[x2][y2] = W;

        for (int x = 1; x <= 19; x++)
        for (int y = 1; y <= 19; y++)
        if (mat[x][y] == E && !vis[x][y])
            dfs(x, y, B);

        int cnt = 0;
        for (int x = 1; x <= 19; x++)
        for (int y = 1; y <= 19; y++)
            cnt += mat[x][y] == B && !vis[x][y];
        ans = max(ans, cnt);

        mat[x1][y1] = mat[x2][y2] = E;
    }
    printf("%d\n", ans);

    return 0;
}
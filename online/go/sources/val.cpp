#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

#define ASSERT(x, i, j) if (!(x)) { \
    fprintf(stderr, "%d, %d\n", i, j); \
    return 2; \
}

#define NMAX 20
#define W 'o'
#define B '+'
#define E '.'

static char mat[NMAX + 10][NMAX + 10];
static bool vis[NMAX + 10][NMAX + 10];

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
    memset(vis, 0, sizeof(vis));
    for (int x = 1; x <= 19; x++)
    for (int y = 1; y <= 19; y++)
    if (mat[x][y] == E && !vis[x][y])
        dfs(x, y, B);
    for (int x = 1; x <= 19; x++)
    for (int y = 1; y <= 19; y++)
        if (mat[x][y] == B) {
            ASSERT(vis[x][y], x, y);
        }

    for (int i = 0; i <= 20; i++)
        mat[0][i] = mat[20][i] = mat[i][0] = mat[i][20] = B;
    memset(vis, 0, sizeof(vis));
    for (int x = 1; x <= 19; x++)
    for (int y = 1; y <= 19; y++)
    if (mat[x][y] == E && !vis[x][y])
        dfs(x, y, W);
    for (int x = 1; x <= 19; x++)
    for (int y = 1; y <= 19; y++)
        if (mat[x][y] == W) {
            ASSERT(vis[x][y], x, y);
        }

    return 1;
}
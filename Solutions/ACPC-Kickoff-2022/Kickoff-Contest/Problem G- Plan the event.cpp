
//
// By AmmarDab3an
//

#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define int ll
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int n, m;
char grid[111][111];
vpii mvArr = {{-1, 0},
              {-1, 1},
              {1, 0},
              {1, 1}};

inline bool in(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

inline bool good(int i, int j) {

    if (grid[i][j] == '*' || grid[i][j] == '?')
        return false;

    for (auto p: mvArr) {
        int ni = i + p.first, nj = j + p.second;
        if (in(ni, nj) and grid[ni][nj] == '#')
            return false;
    }
    return true;
}

inline void fill(int i, int j) {

    grid[i][j] = '#';

    for (auto p: mvArr) {
        int ni = i + p.first, nj = j + p.second;
        if (in(ni, nj) and (grid[ni][nj] == '.'))
            grid[ni][nj] = '?';
    }
}

signed main() {

    freopen("event.in", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {

        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++)
            scanf("%s", grid[i]);


        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (good(i, j)) {
                    fill(i, j);
                    ans++;
                }
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '?')
                    grid[i][j] = '.';

        printf("%d\n", ans);
        for (int i = 0; i < n; i++)
            puts(grid[i]);
    }
}

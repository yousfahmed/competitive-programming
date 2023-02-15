/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101755/problem/H
*/
#include <bits/stdc++.h>

using namespace std;


const pair<int, int> adj[] = {
        {-1, 0},
        {0,  +1},
        {+1, 0},
        {0,  -1}
};
int n, m;

bool in(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

vector<vector<bool>> valid;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    queue<pair<int, int>> q;
    int d, sx, ex, sy, ey;
    char ch;
    cin >> n >> m >> d;
    valid = vector<vector<bool>>(n, vector<bool>(m, 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ch;
            if (ch == 'S') sx = i, sy = j;
            else if (ch == 'F') ex = i, ey = j;
            else if (ch == 'M') {
                valid[i][j] = false;
                q.emplace(i, j);
            }
        }
    }

    int sz, i, j, x, y;
    while (d--) { // set invalid cells
        sz = q.size(), i, j, x, y;
        while (sz--) {
            tie(i, j) = q.front();
            q.pop();
            for (auto &_: adj) {
                x = i + _.first, y = j + _.second;
                if (in(x, y) and valid[x][y]) {
                    valid[x][y] = false;
                    q.emplace(x, y);
                }
            }
        }
    }

    if (valid[sx][sy]) {
        while (q.size()) q.pop();
        q.emplace(sx, sy);
        int ret = 0;
        while (q.size()) {
            sz = q.size();
            ret++;
            while (sz--) {
                tie(i, j) = q.front();
                q.pop();
                for (auto &_: adj) {
                    x = i + _.first, y = j + _.second;
                    if (in(x, y) and valid[x][y]) {
                        if (x == ex and y == ey)return cout << ret, 0;
                        valid[x][y] = false;
                        q.emplace(x, y);
                    }
                }
            }
        }
    }
    cout << -1;
}

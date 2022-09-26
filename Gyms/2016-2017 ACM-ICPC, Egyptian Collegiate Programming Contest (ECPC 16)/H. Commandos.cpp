/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101147/problem/H
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long

int mem[11][11][11];
int arr[11][11][11];
int vis[11][11][11], vs;
int vis2[11][11][11];

int dp(int i, int j, int k) {
    if (i < 0 or j >= 10 or k >= 10)return 0;
    int &ret = mem[i][j][k];
    if (vis[i][j][k] == vs)return ret;
    vis[i][j][k] = vs;
    ret = max(
            {
                    dp(i - 1, j, k),
                    dp(i, j + 1, k),
                    dp(i, j, k + 1)
            }
    );
    if (vis2[i][j][k] == vs)
        ret += arr[i][j][k];
    return ret;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, z, d;
        cin >> x >> y >> z >> d;
        --x, --y, --z;
        assert(vis2[x][y][z] != vs);
        arr[x][y][z] = d;
        vis2[x][y][z] = vs;
    }
    cout << dp(9, 0, 0) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("commandos.in", "r", stdin);
#endif
    int TC;
    cin >> TC;
    while (TC--) {
        vs++;
        solve();
    }
}

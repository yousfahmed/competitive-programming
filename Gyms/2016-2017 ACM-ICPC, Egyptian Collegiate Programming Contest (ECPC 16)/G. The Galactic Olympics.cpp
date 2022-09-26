/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101147/problem/G
*/
#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int add(int a, int b) {
    return (a + b) % mod;
}

const int N = 1e3 + 7;

int mem[N][N];
int vis[N][N], vs;
int n, k;

int dp(int i, int j) {
    if (i == n) return (j == 0);
    if (j < 0)return 0;
    int &ret = mem[i][j];
    if (vis[i][j] == vs)return ret;
    vis[i][j] = vs;
    ret = mul(dp(i + 1, j), k - j);
    ret = add(
            ret,
            mul(dp(i + 1, j - 1), j)
    );
    return ret;
}

void solve() {
    cin >> n >> k;
    if (n < k) {
        cout << "0\n";
    }else {
        cout << dp(0, k) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("galactic.in", "r", stdin);
#endif
    int TC;
    cin >> TC;
    while (TC--) {
        vs++;
        solve();
    }
}

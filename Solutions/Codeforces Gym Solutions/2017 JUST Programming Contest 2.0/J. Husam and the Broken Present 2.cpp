/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/J
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define sz(x) ((int)((x).size()))

bool common(vector<int> &pat, vector<int> &s) {
    int n = pat.size(), m = s.size();
    for (int i = 0; i + n - 1 < m; ++i) {
        bool f = true;
        for (int j = 0; j < n; ++j)
            if (pat[j] != s[i + j]) {
                f = false;
                break;
            }
        if (f)return true;
    }
    return false;
}

int cost(vector<int> &f, vector<int> &t) {
    auto okay = [&](int sz) -> bool {
        int i = sz(f) - 1, j = sz - 1;
        while (j >= 0) {
            if (f[i] != t[j])
                return false;
            i--, j--;
        }
        return true;
    };
    for (int i = min(sz(f), sz(t)); i >= 0; --i)
        if (okay(i))return i;
    assert(false);
    return 0;
}

int n;
vector<vector<int>> arr, adj;


int mem[18][(1 << 18) + 7];

int dp(int i, int msk, int cnt = 0) {
    if (__builtin_popcount(msk) == n + 1)
        return 0;
    int &ret = mem[i][msk];
    if (~ret) return ret;
    ret = 1e9;
    for (int v = 0; v < n; ++v) {
        if (msk & (1 << v))continue;
        ret = min(
                ret,
                adj[i][v] + dp(v, msk | (1 << v), cnt + 1) + ((int) arr[v].size())
        );
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(mem, -1, sizeof mem);
    cin >> n;
    arr = vector<vector<int>>(n);
    for (int i = 0, sz; i < n; ++i) {
        cin >> sz;
        arr[i].resize(sz);
        for (int &j: arr[i]) cin >> j;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)continue;
            if (common(arr[i], arr[j])) {
                arr[i] = arr.back();
                arr.pop_back();
                n--, i--;
                break;
            }
        }
    }
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) { /// cal Cost
        for (int j = 0; j < n; ++j) {
            if (i == j)continue;
            adj[i][j] = -cost(arr[i], arr[j]);
        }
    }
    cout << dp(n, (1 << n));
}

/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/103821/problem/K
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
const int  mod = 1000000007;

int add(int x, int y) {
    x += y;
    while (x >= mod) x -= mod;
    while (x < 0) x += mod;
    return x;
}

int mul(int x, int y) {
    return x % mod * y % mod;
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> e(m + 7);
    vector<pair<int, int>> arr(n);
    for (int i = 0, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u] += (m - v + 1);
        arr[i] = {u, v};
    }
    const int MX = 1e18;
    for (int i = m - 1; i; --i)
        e[i] += e[i + 1];
    
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = add(ret,
                  mul(
                          arr[i].first,
                          e[arr[i].second + 1]
                  )
        );
    }
    cout << ret << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC;
    cin >> TC;
    while (TC--)
        solve();
}

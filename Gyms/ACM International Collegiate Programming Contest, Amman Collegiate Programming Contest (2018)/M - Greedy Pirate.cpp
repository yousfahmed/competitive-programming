/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101810/problem/M
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 7;

int sumUp[N], sumDown[N];
int dp[30][N], depth[N];
int tot;
vector<pair<pair<int, int>, int >> adj[N];


void init(int n) {
    tot = 0;
    for (int i = 1; i <= n; ++i) {
        sumUp[i] = sumDown[i] = depth[i] = 0;
        adj[i].clear();
        for (auto &j: dp)
            j[i] = 0;
    }
}

void dfs(int u, int p, int up, int d, int h) {
    sumUp[u] = up, sumDown[u] = d;
    int v, c1, c2;
    for (auto &i: adj[u]) {
        tie(v, c1) = i.first;
        c2 = i.second;
        if (v == p)continue;
        depth[v] = h + 1;
        dp[0][v] = u;
        for (int msk = 1; (1 << msk) <= depth[v]; ++msk)
            dp[msk][v] = dp[msk - 1][dp[msk - 1][v]];
        dfs(v, u, up + c2, d + c1, h + 1);
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (dp[i][v] != -1 and depth[dp[i][v]] >= depth[u])
            v = dp[i][v];
    if (u == v)return u;
    for (int i = 19; i >= 0; i--)
        if (dp[i][v] != dp[i][u])
            v = dp[i][v], u = dp[i][u];
    return dp[0][v];
}


int solve(int u, int v) {
    if (u == v) return tot;
    int lca = LCA(u, v);
    if (lca == u) {
        return tot - sumUp[v] + sumUp[u];
    }
    if (lca == v) {
        return tot - sumDown[u] + sumDown[v];
    }
    return tot - sumDown[u] + sumDown[lca]
           - sumUp[v] + sumUp[lca];
}


void solve() {
    int n;
    cin >> n;
    init(n);
    int u, v, c1, c2;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> c1 >> c2;
        tot += c1 + c2;
        adj[u].push_back({{v, c1}, c2});
        adj[v].push_back({{u, c2}, c1});
    }
    dfs(1, 0, 0, 0, 0);
    int q;
    cin >> q;
    while (q--) {
        cin >> u >> v;
        cout << solve(u, v) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
        solve();
}


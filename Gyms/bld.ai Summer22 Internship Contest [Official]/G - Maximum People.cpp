/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7, LG = 19;
int level[N];
int dp[20][N];
int table[20][N];
int LOG[N];
int sz[N], pr[N];
vector<vector<pair<int, int> > > adj;
int n;

void DFS(int u, int par, int h) {
    dp[0][u] = par;
    level[u] = h;
    for (auto &i: adj[u]) {
        if (i.first == par) continue;
        table[0][i.first] = i.second;
        DFS(i.first, u, h + 1);
    }
}


int query(int a, int b) {
    if (level[b] < level[a]) swap(a, b);
    int ans = 1e9;
    int diff = level[b] - level[a];
    while (diff > 0) {
        int msk = LOG[diff];
        ans = min(ans, table[msk][b]);
        b = dp[msk][b];
        diff -= (1 << msk);
    }
    while (a != b) {
        int i = LOG[level[a]];
        while (i > 0 and dp[i][a] == dp[i][b])i--;
        ans = min({
                          ans,
                          table[i][a],
                          table[i][b]
                  });
        a = dp[i][a];
        b = dp[i][b];
    }
    return ans;
}

void Precompute() {

    for (int i = 2; i <= n; ++i)
        LOG[i] = LOG[i / 2] + 1;

    DFS(1, 0, 0);

    for (int i = 1; i < LG; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
            table[i][j] = min(
                    table[i - 1][j],
                    table[i - 1][dp[i - 1][j]]
            );
        }
    }
}

struct Edge {
    int u, v, w;

    bool operator<(const Edge &x) const {
        return w > x.w;
    }
};

void init() {
    for (int i = 0; i <= n; ++i) {
        pr[i] = i;
        sz[i] = 1;
    }
}

inline int findPar(int u) {
    if (pr[u] == u)return u;
    return pr[u] = findPar(pr[u]);
}

inline bool join(int u, int v) {
    u = findPar(u), v = findPar(v);
    if (u == v)return false;
    if (sz[u] < sz[v])swap(u, v);
    pr[v] = u;
    sz[u] += sz[v];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, q;
    cin >> n >> m;
    Edge edges[m];
    for (auto &i: edges)cin >> i.u >> i.v >> i.w;
    sort(edges, edges + m);
    init(); /// for DSU
    adj.resize(n + 1);
    for (auto &i: edges) { /// max spanning tree
        if (join(i.u, i.v)) {
            adj[i.u].push_back(make_pair(i.v, i.w));
            adj[i.v].push_back(make_pair(i.u, i.w));
        }
    }
    cin >> q;
    Precompute(); /// get Anc and the minEdge
    for (int i = 0, u, x; i < q; i++) {
        cin >> u >> x;
        cout << query(u, x) << '\n';
    }
    return 0;
}

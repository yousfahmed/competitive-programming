#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;
vector<int> adj[N];
int up[25][N], in[N], out[N];
int timer;
int n;

void dfs(int v, int p) {
    in[v] = timer++;
    up[0][v] = p;
    for (int i = 1; i <= 22; ++i)
        up[i][v] = up[i - 1][up[i - 1][v]];
    for (int u: adj[v])
        if (u != p)
            dfs(u, v);
    out[v] = timer++;
}

bool is_ancestor(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int LCA(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = 22; i >= 0; --i)
        if (!is_ancestor(up[i][u], v))
            u = up[i][u];
    return up[u][0];
}

struct BIT {
private:
    int bit[(N << 1) + 7];

    void _add(int i, int v) {
        for (++i; i <= timer; i += i & -i)
            bit[i] += v;
    }

    int query(int i) {
        int ret = 0;
        for (++i; i; i -= (i & -i))
            ret += bit[i];
        return ret;
    }

public:

    void add(int u, int val) {
        _add(in[u], val);
        _add(out[u] + 1, -val);
    }

    int query(int u, int v) {
        int lca = LCA(u, v);
        return query(in[u]) + query(in[v])
               - query(in[lca]) - (lca ? query(up[0][lca]) : 0);
    }
} b;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
//    freopen("output.out", "w", stdout);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(0, 0);
    int u, v, t;
    while (cin >> t) {
        cin >> u >> v;
        if (t == 1) {
            b.add(u, v);
        } else {
            cout << b.query(u, v) << '\n';
        }
    }
    return 0;
}

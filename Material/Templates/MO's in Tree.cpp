#include <bits/stdc++.h>

using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
const int N = 2e5 + 7;
int tree[N << 2], in[N], out[N];
int dp[30][N], depth[N], arr[N];
vector<int> adj[N];
int timer = 0;

void DFS(int u, int p, int h = 0) {
    in[u] = timer;
    for (int &v: adj[u])
        if (p != v) {
            depth[v] = h + 1;
            dp[0][v] = u;
            for (int msk = 1; (1 << msk) <= depth[v]; ++msk)
                dp[msk][v] = dp[msk - 1][dp[msk - 1][v]];
            tree[timer++] = u;
            DFS(v, u, h + 1);
            tree[timer++] = u;
        }
    if (adj[u].size() == 1) {
        tree[timer++] = u;
        tree[timer++] = u;
    }
    out[u] = timer;
}

int SQ;

struct Query {
    int l, r, i, b;

    Query() {}

    Query(int l, int r, int i) : i(i), l(l), r(r), b(l / SQ) {}

    bool operator<(const Query &x) const {
        return b != x.b ? b < x.b : r < x.r;
    }
};

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (depth[dp[i][v]] >= depth[u])
            v = dp[i][v];
    if (u == v)return u;
    for (int i = 19; i >= 0; i--)
        if (dp[i][v] != dp[i][u])
            v = dp[i][v], u = dp[i][u];
    return dp[0][v];
}

int ans;
int freq[N];

void add(int i) { /// Assume the query is the number of distinict elements in sub tree u
    ++freq[arr[tree[i]]];
    if (freq[arr[tree[i]]] & 1) ++ans;
    else --ans;
}

void remove(int i) {
    --freq[arr[tree[i]]];
    if (freq[arr[tree[i]]] & 1) ++ans;
    else --ans;
}


vector<int> MOS(vector<Query> &queries, int Q) {
    sort(queries.begin(), queries.end());
    vector<int> ret(Q);
    int l = 1, r = 0;
    for (auto &q: queries) {
        while (l < q.l) remove(l++);
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (r > q.r) remove(r--);
        if (ret[q.i]) --ret[q.i];
        ret[q.i] += ans;
    }
    return ret;
}


int main() {
    NeedForSpeed
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    SQ = ceil(sqrt(n));
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    DFS(0, 0); /// DFS order -get flatting tree-
    int q;
    cin >> q;
    vector<Query> queries;
    queries.reserve(q << 1);
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        --u, --v;
        int lca = LCA(u, v);
        if (lca == u) {
            queries.push_back(Query(in[u], in[v], i));
        } else if (lca == v) {
            queries.push_back(Query(in[v], in[u], i));
        } else {
            queries.push_back(Query(in[lca], in[u], i));
            queries.push_back(Query(in[lca], in[v], i));
        }
    }
    auto ret = MOS(queries, q);
    for (int &i: ret)cout << i << ' ';
    cout << '\n';
}

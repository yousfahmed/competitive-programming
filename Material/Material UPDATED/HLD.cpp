#include "bits/stdc++.h"

using namespace std;

struct SegmentTree { /// not important now but it's just a segment tree
    void init(int n) {}

    void update(int i, int val) {}

    void update(int l, int r, int val) {}

    int query(int l, int r) {}
} seg;

const int N = 2e5 + 5;

int n, q, v[N];
vector<int> adj[N];

int sz[N], p[N], dep[N];
int in[N], tp[N];


void dfs_sz(int u, int par) {
    sz[u] = 1, p[u] = par;
    for (int &to: adj[u])
        if (to != par) {
            dep[to] = dep[u] + 1;
            dfs_sz(to, u);
            sz[u] += sz[to];
        }
}

void dfs_hld(int u, int par, int top) {
    static int timer = 1;
    in[u] = timer++;
    tp[u] = top;
    seg.update(in[u], v[u]);
    int big_child = -1, h_sz = -1;
    for (int to: adj[u])
        if (to != par and sz[to] > h_sz)
            h_sz = sz[to], big_child = to;

    if (big_child == -1) return;

    dfs_hld(big_child, u, top);

    for (int to: adj[u])
        if (to != par and to != big_child)
            dfs_hld(to, u, to);
}

int query_path(int x, int y) {
    int ret = 0;
    while (tp[x] != tp[y]) {
        if (dep[tp[x]] < dep[tp[y]])
            swap(x, y);
        ret = max(ret, seg.query(in[tp[x]], in[x]));
        x = p[tp[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    ret = max(ret, seg.query(in[x], in[y]));
    return ret;
}

void update_path(int x, int y, int val) {
    while (tp[x] != tp[y]) {
        if (dep[tp[x]] < dep[tp[y]])
            swap(x, y);
        seg.update(in[tp[x]], in[x], val);
        x = p[tp[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    seg.update(in[x], in[y], val);
}

int main() {
    scanf("%d%d", &n, &q);
    seg.init(n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 2, a, b; i <= n; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_sz(1, 1);
    dfs_hld(1, 1, 1);
    while (q--) {
        /// queries
    }
}

/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101147/problem/J
*/
#include <bits/stdc++.h>

using namespace std;
const int N = 500000 + 7;
#define int long long
int in[N], out[N], tree[N], dist[N], arr[N];
int timer;
vector<vector<pair<int, int>>> adj;

void DFS(int u, int p, int w) {
    in[u] = timer;
    dist[u] = w;
    tree[timer++] = w - arr[u];
    for (auto v: adj[u])
        if (v.first != p)
            DFS(v.first, u, w + v.second);
    out[u] = timer;
}

struct MergeSortTree {
private:
    vector<vector<int>> seg;
    int sz;

    void built(int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < timer) {
                seg[x].reserve(1);
                seg[x].push_back(tree[lx]);
            }
            return;
        }
        int m = (rx + lx) >> 1;
        built(x * 2 + 1, lx, m);
        built(x * 2 + 2, m, rx);
        seg[x].reserve(seg[x * 2 + 1].size() + seg[x * 2 + 2].size());
        merge(
                seg[x * 2 + 1].begin(), seg[x * 2 + 1].end(),
                seg[x * 2 + 2].begin(), seg[x * 2 + 2].end(),
                back_inserter(seg[x])
        );
    }

    int query(int l, int r, int v, int x, int lx, int rx) {
        if (r <= lx or rx <= l)return 0;
        if (l <= lx and rx <= r) {
            return upper_bound(seg[x].begin(), seg[x].end(), v) - seg[x].begin();
        }
        int m = (rx + lx) >> 1;
        return
                query(l, r, v, x * 2 + 1, lx, m) +
                query(l, r, v, x * 2 + 2, m, rx);
    }

public:
    void init() {
        sz = 1;
        while (sz < timer)sz <<= 1;
        seg = vector<vector<int>>(sz * 2);
        built(0, 0, sz);
    }

    int query(int l, int r, int v) {
        return query(l, r, v, 0, 0, sz);
    }

};

void solve() {
    int n;
    cin >> n;
    adj = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1, u, v, c; i < n; ++i) {
        cin >> u >> v >> c;
        --u, --v;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    timer = 0;
    DFS(0, 0, 0);
    MergeSortTree mst;
    mst.init();
    for (int i = 0; i < n; ++i) {
        int l = in[i], r = out[i], v = dist[i];
        int ans = (l != r) ? mst.query(l + 1, r, v) : 0;
        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("car.in", "r", stdin);
#endif
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
}

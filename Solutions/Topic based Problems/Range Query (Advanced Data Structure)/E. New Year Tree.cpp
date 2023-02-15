/*
 *      Topic : Segment Tree & BitMasks & flatting Tree
 *      Problem Name : E. New Year Tree
 *      Link To problem : https://codeforces.com/contest/620/problem/E
 *      Author : Abdelaleem Ahmed
 *      Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
 */

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 4e5 + 7;
vector<int> adj[N];
int tree[N], in[N], out[N], arr[N];

int flatting(int u, int f) {
    static int timer = 0;
    in[u] = timer;
    tree[timer++] = arr[u];
    for (int &v: adj[u])
        if (v != f)
            flatting(v, u);
    out[u] = timer;
    return timer;
}

struct SegmentTree {
private:
    vector<int> seg, lazy;
    int sz;
    const int none = (1ll << 61) - 1, ignored = 0;

    inline int merge(int x, int y) {
        return (x | y);
    }

    inline void propagate(int x, int lx, int rx) {
        if (lazy[x] == none) return;
        seg[x] = lazy[x];
        if (rx - lx > 1) {
            lazy[x * 2 + 1] = lazy[x];
            lazy[x * 2 + 2] = lazy[x];
        }
        lazy[x] = none;
    }

    void built(int n, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < n)
                seg[x] = (1ll << tree[lx]);
            return;
        }
        int m = (rx + lx) >> 1;
        built(n, x * 2 + 1, lx, m);
        built(n, x * 2 + 2, m, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    void update(int l, int r, int v, int x, int lx, int rx) {
        if (l <= lx and rx <= r) {
            lazy[x] = v;
            propagate(x, lx, rx);
            return;
        }
        propagate(x, lx, rx);
        if (r <= lx or rx <= l)return;
        int m = (rx + lx) >> 1;
        update(l, r, v, x * 2 + 1, lx, m);
        update(l, r, v, x * 2 + 2, m, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    int query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (l <= lx and rx <= r) return seg[x];
        if (r <= lx or rx <= l)return ignored;
        int m = (rx + lx) >> 1;
        return merge(
                query(l, r, x * 2 + 1, lx, m),
                query(l, r, x * 2 + 2, m, rx)
        );
    }

public:

    SegmentTree(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(sz << 1, 0);
        lazy.assign(sz << 1, none);
        built(n);
    }

    void built(int n) {
        built(n, 0, 0, sz);
    }

    void update(int l, int r, int val) {
        update(l, r, (1ll << val), 0, 0, sz);
    }

    int query(int l, int r) {
        int ret = query(l, r, 0, 0, sz);
        return __builtin_popcountll(ret);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }
    int sz = flatting(0, -1);
    SegmentTree seg(sz);
    int t, u, val;
    while (q--) {
        cin >> t >> u;
        if (t == 1) {
            cin >> val;
            seg.update(in[u - 1], out[u - 1], val);
        } else {
            cout << seg.query(in[u - 1], out[u - 1]) << '\n';
        }
    }

}

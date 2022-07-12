#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
private:
    vector<int> seg;
    int sz;

    int merge(int x, int y) {
        return min(x, y);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = v;
            return;
        }
        int m = (rx + lx) >> 1;
        if (i < m) update(i, v, x * 2 + 1, lx, m);
        else update(i, v, x * 2 + 2, m, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    int query(int l, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (seg[x] >= l) return lx + 1;
            return lx;
        }
        int m = (rx + lx) >> 1;
        if (seg[x * 2 + 1] >= l)
            return query(l, x * 2 + 2, m, rx);
        return query(l, x * 2 + 1, lx, m);
    }

public:

    SegmentTree(int n) {
        ++n;
        sz = 1;
        while (sz < n)sz <<= 1;
        seg.assign(sz << 1, -1);
    }

    int query(int l) {
        return query(l, 0, 0, sz);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, sz);
    }

};

struct Query {
    int l, r, idx;

    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}

    Query() {}

    bool operator<(const Query &x) const {
        return r < x.r;
    }
};

void solve() {
    int n, Q;
    cin >> n >> Q;
    int arr[n];
    for (int &i: arr) cin >> i;
    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        --queries[i].r, --queries[i].l;
        queries[i].idx = i;
    }
    sort(queries.begin(), queries.end());
    int q = 0;
    SegmentTree seg(n);
    int ret[Q];
    for (int i = 0; i < n; ++i) {
        if (arr[i] < n) seg.update(arr[i] - 1, i); /// -1 to avoid Zero
        while (q < queries.size() and queries[q].r == i) {
            ret[queries[q].idx] = seg.query(queries[q].l) + 1; /// +1 if avoid el zero
            q++;
        }
    }
    for (int &i: ret) cout << i << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//    freopen("mex.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
        solve();
}

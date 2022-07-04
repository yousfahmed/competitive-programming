/*
 *      Topic : Faltting Tree & Segment Tree
 *      Problem Name : Subtree Queries
 *      Link To problem : https://www.hackerearth.com/problem/algorithm/subtree-queries
 *      Author : Abdelaleem Ahmed 
 *      Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
 */

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;
int arr[N], in[N], out[N], tree[N];
vector<int> adj[N];

int flatting(int u, int f) {
    static int cnt = 0;
    tree[cnt] = arr[u];
    in[u] = cnt++;
    for (int &v: adj[u])
        if (v != f)
            flatting(v, u);
    out[u] = cnt;
    return cnt;
}

struct SegmentTree {
private:
    int sz, *seg;

    void init(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg = new int[sz << 1];
    }

    int merge(int x, int y) {
        return __gcd(x, y);
    }

    void built(int n, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < n) seg[x] = tree[lx];
            return;
        }
        int m = (rx + lx) >> 1;
        built(n, x * 2 + 1, lx, m);
        built(n, x * 2 + 2, m, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (r <= lx or l >= rx)return 0;
        if (lx >= l and rx <= r) return seg[x];
        int m = (rx + lx) >> 1;
        return merge(
                query(l, r, x * 2 + 1, lx, m),
                query(l, r, x * 2 + 2, m, rx)
        );
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = v;
            return;
        }
        int m = (rx + lx) >> 1;
        if (i < m) update(i, v, x * 2 + 1, lx, m);
        else update(i, v, x * 2 + 2, m, rx);
        seg[x] = merge(
                seg[x * 2 + 1],
                seg[x * 2 + 2]
        );
    }

public:
    SegmentTree() : sz(1), seg(nullptr) {}

    SegmentTree(int n) {
        built(n);
    }

    void built(int n) {
        init(n);
        built(n, 0, 0, sz);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, sz);
    }

    void update(int idx, int v) {
        update(idx, v, 0, 0, sz);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }
    int sz = flatting(0, -1);


    SegmentTree seg(sz);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, x;
            cin >> u >> x;
            u--;
            seg.update(in[u], x);
        } else {
            int i;
            cin >> i;
            --i;
            cout << seg.query(in[i], out[i]) << '\n';
        }
    }

}

#include <bits/stdc++.h>

using namespace std;
#define int long long

struct SegmentTree {
private:
  vector<int> seg, lazy;
  int sz;

  void propagate(int x, int lx, int rx) {
    if (!lazy[x])return;
    if (lx != rx) {
      lazy[x * 2 + 1] += lazy[x];
      lazy[x * 2 + 2] += lazy[x];
    }
    seg[x] += lazy[x];
    lazy[x] = 0;
  }

  void update(int l, int r, int v, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l <= lx && rx <= r) {
      lazy[x] += v;
      propagate(x, lx, rx);
      return;
    }
    if (r < lx || rx < l)return;
    int m = (rx + lx) >> 1;
    update(l, r, v, x * 2 + 1, lx, m);
    update(l, r, v, x * 2 + 2, m + 1, rx);
    seg[x] = min(
        seg[x * 2 + 1],
        seg[x * 2 + 2]
    );
  }

  int query(int l, int r, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l <= lx && rx <= r) {
      return seg[x];
    }
    if (r < lx || rx < l)return 1e18;
    int m = (rx + lx) >> 1;
    return min(
        query(l, r, x * 2 + 1, lx, m),
        query(l, r, x * 2 + 2, m + 1, rx)
    );

  }

public:

  SegmentTree(int n) {
    sz = 1;
    while (sz < n)sz <<= 1;
    seg = vector<int>(sz << 1);
    lazy = vector<int>(sz << 1);
  }

  void update(int l, int r, int v) {
    update(l, r, v, 0, 0, sz - 1);
  }

  int query(int l, int r) {
    return query(l, r, 0, 0, sz - 1);
  }
};


signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr), cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  SegmentTree seg(n);
  int l, r, ty, v;
  while (q--) {
    cin >> ty;
    if (ty == 1) {
      cin >> l >> r >> v;
      seg.update(l, --r, v);
    } else {
      cin >> l >> r;
      cout << seg.query(l, --r) << '\n';
    }
  }
}

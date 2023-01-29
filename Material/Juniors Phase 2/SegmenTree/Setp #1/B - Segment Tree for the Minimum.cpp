#include <bits/stdc++.h>

using namespace std;
#define int long long

struct SegmentTree {
private:
  int sz, ignored;
  vector<int> seg;

  int op(int a, int b) {
    return min(a, b);
  }

  void update(int i, int v, int x, int lx, int rx) {
    if (lx == rx) {
      seg[x] = v;
      return;
    }
    int m = (rx + lx) >> 1;
    if (i <= m) { /// go left
      update(i, v, x * 2 + 1, lx, m);
    } else { /// go right
      update(i, v, x * 2 + 2, m + 1, rx);
    }
    seg[x] = op(seg[x * 2 + 1], seg[x * 2 + 2]);
  }

  int query(int l, int r, int x, int lx, int rx) {
    if (r < lx || rx < l) return ignored;
    if (l <= lx && rx <= r)return seg[x];
    int m = (rx + lx) >> 1;
    return op(
        query(l, r, x * 2 + 1, lx, m),
        query(l, r, x * 2 + 2, m + 1, rx)
    );
  }

public:
  SegmentTree(int n) {
    sz = 1, ignored = 1e9 + 1;
    while (sz < n)sz <<= 1;
    seg = vector<int>(sz << 1);
  }

  void update(int i, int v) {
    update(i, v, 0, 0, sz - 1);
  }

  int query(int l, int r) {
    return query(l, r, 0, 0, sz - 1);
  }

};


signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  SegmentTree seg(n);
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    seg.update(i, x);
  }
  int ty, l, r;
  while (m--) {
    cin >> ty >> l >> r;
    if (ty == 1) {
      seg.update(l, r);
    } else {
      cout << seg.query(l, r - 1) << '\n';
    }
  }

}

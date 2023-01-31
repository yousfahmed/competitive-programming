#include <bits/stdc++.h>

using namespace std;
#define int long long

struct SegmentTree {
private:
  vector<int> seg;
  int sz;

  void update(int l, int r, int v, int x, int lx, int rx) {
    if (l <= lx && rx <= r) {
      seg[x] += v;
      return;
    }
    if (r < lx || rx < l)return;
    int m = (rx + lx) >> 1;
    update(l, r, v, x * 2 + 1, lx, m);
    update(l, r, v, x * 2 + 2, m + 1, rx);
  }

  int query(int i, int x, int lx, int rx) {
    if (rx == lx) {
      return seg[x];
    }
    int m = (rx + lx) >> 1;
    if (i <= m) {
      return seg[x] + query(i, x * 2 + 1, lx, m);
    }
    return seg[x] + query(i, x * 2 + 2, m + 1, rx);
  }

public:

  SegmentTree(int n) {
    sz = 1;
    while (sz < n)sz <<= 1;
    seg = vector<int>(sz << 1);
  }

  void update(int l, int r, int v) {
    update(l, r, v, 0, 0, sz - 1);
  }

  int query(int i) {
    return query(i, 0, 0, sz - 1);
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
      cin >> l;
      cout << seg.query(l) << '\n';
    }
  }
}

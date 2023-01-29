#include <bits/stdc++.h>

using namespace std;
#define int long long

struct SegmentTree {
private:
  struct node {
    int val, frq;

    node() : val(1e9 + 7), frq(0) {}
  } ignored;

  int sz;
  vector<node> seg;


  node op(node a, node b) {
    node res;
    res.val = min(a.val, b.val);
    res.frq = 0;
    if (a.val == res.val)res.frq += a.frq;
    if (b.val == res.val)res.frq += b.frq;
    return res;
  }

  void update(int i, int v, int x, int lx, int rx) {
    if (lx == rx) {
      seg[x].val = v;
      seg[x].frq = 1;
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

  node query(int l, int r, int x, int lx, int rx) {
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
    sz = 1;
    while (sz < n)sz <<= 1;
    seg = vector<node>(sz << 1);
  }

  void update(int i, int v) {
    update(i, v, 0, 0, sz - 1);
  }

  pair<int, int> query(int l, int r) {
    auto res = query(l, r, 0, 0, sz - 1);
    return {res.val, res.frq};
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
      auto res = seg.query(l, r - 1);
      cout << res.first << ' ' << res.second << '\n';
    }
  }

}

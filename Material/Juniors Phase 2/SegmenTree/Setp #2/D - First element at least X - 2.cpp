#include <bits/stdc++.h>

using namespace std;
#define int long long

struct SegmentTree {
private:
#define node int
  int sz;
  vector<node> seg;

  node op(node a, node b) {
    return max(a, b);
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

  node query(int v, int i, int x, int lx, int rx) {
    if (seg[x] < v || i > rx)return -1;
    if (rx == lx) return lx;
    int m = (lx + rx) >> 1;
    int res = query(v, i, x * 2 + 1, lx, m);
    if (res != -1)return res;
    return query(v, i, x * 2 + 2, m + 1, rx);
  }

public:
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)sz <<= 1;
    seg = vector<node>(sz << 1);
  }

  void update(int i, int x) {
    update(i, x, 0, 0, sz - 1);
  }

  int query(int k, int i) {
    return query(k, i, 0, 0, sz - 1);
  }

};


signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  SegmentTree seg(n);
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    seg.update(i, x);
  }
  int ty, i, x;
  while (m--) {
    cin >> ty >> i >> x;
    if (ty == 1) {
      seg.update(i, x);
    } else {
      cout << seg.query(i, x) << '\n';
    }
  }

}

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

  node query(int K, int x, int lx, int rx) {
    if (lx == rx) {
      return lx;
    }
    int lf = seg[x * 2 + 1];
    int m = (rx + lx) >> 1;
    if (K <= lf) {
      return query(K, x * 2 + 1, lx, m);
    } else {
      return query(K, x * 2 + 2, m + 1, rx);
    }
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

  int query(int k) {
    if (seg[0] < k)return -1;
    return query(k, 0, 0, sz - 1);
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
    cin >> ty >> i;
    if (ty == 1) {
      cin >> x;
      seg.update(i, x);
    } else {
      cout << seg.query(i) << '\n';
    }
  }

}

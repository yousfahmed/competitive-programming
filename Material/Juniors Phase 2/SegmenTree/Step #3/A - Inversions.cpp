#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
private:
#define node long long

  vector<node> seg;
  int sz;

  node opt(node lft, node rt) {
    return lft + rt;
  }

  void update(int i, int x, int lx, int rx) {
    if (rx == lx) {
      seg[x] = 1;
      return;
    }
    int m = (rx + lx) >> 1;
    if (i <= m) {
      update(i, x * 2 + 1, lx, m);
    } else {
      update(i, x * 2 + 2, m + 1, rx);
    }
    seg[x] = opt(seg[x * 2 + 1], seg[x * 2 + 2]);
  }

  int query(int i, int x, int lx, int rx) {
    if (rx < i)return 0;
    if (i <= lx)return seg[x];
    int m = (rx + lx) >> 1;
    return opt(
        query(i, x * 2 + 1, lx, m),
        query(i, x * 2 + 2, m + 1, rx)
    );
  }

public:
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)sz <<= 1;
    seg = vector<node>(sz << 1);
  }

  void update(int i) {
    update(i, 0, 0, sz - 1);
  }

  int query(int i) {
    return query(i, 0, 0, sz - 1);
  }

#undef node
};

signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr), cin.tie(nullptr);
  int n;
  cin >> n;
  int x;
  SegmentTree seg(n);
  for (int i = 0; i < n; ++i) {
    cin >> x;
    cout << seg.query(--x) << ' ';
    seg.update(x);
  }
}

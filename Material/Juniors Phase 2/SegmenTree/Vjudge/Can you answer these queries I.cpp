#include <bits/stdc++.h>

using namespace std;
#define int long long

struct SegmentTree {
private:

  struct node {
    int sum, maxSeg, suf, pref;

    node() : sum(-1e9), maxSeg(-1e9), suf(-1e9), pref(-1e9) {}

    node(int v) : sum(v), maxSeg(v), suf(v), pref(v) {}

  } ign;

  vector<node> seg;
  int sz;

  node opt(node lft, node rt) {
    node res;
    res.sum = lft.sum + rt.sum;
    res.maxSeg = max({
                         lft.maxSeg,
                         rt.maxSeg,
                         lft.suf + rt.pref
                     });
    res.suf = max(
        rt.suf,
        rt.sum + lft.suf
    );
    res.pref = max(
        lft.pref,
        lft.sum + rt.pref
    );
    return res;
  }

  void update(int i, int v, int x, int lx, int rx) {
    if (rx == lx) {
      seg[x] = {v};
      return;
    }
    int m = (rx + lx) >> 1;
    if (i <= m) {
      update(i, v, x * 2 + 1, lx, m);
    } else {
      update(i, v, x * 2 + 2, m + 1, rx);
    }
    seg[x] = opt(seg[x * 2 + 1], seg[x * 2 + 2]);
  }

  node query(int l, int r, int x, int lx, int rx) {
    if (r < lx or rx < l)return ign;
    if (l <= lx && rx <= r)return seg[x];
    int m = (rx + lx) >> 1;
    return opt(
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

  int query(int l, int r) {
    return query(l, r, 0, 0, sz - 1).maxSeg;
  }


};


signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr), cin.tie(nullptr);
  int n;
  cin >> n;
  SegmentTree seg(n);
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    seg.update(i, x);
  }
  int q, l, r;
  cin >> q;
  while (q--) {
    cin >> l >> r;
    cout << seg.query(--l, --r) << '\n';
  }
}

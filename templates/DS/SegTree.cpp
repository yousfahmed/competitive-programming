struct SegTree {
#define LF (x*2+1)
#define RT (x*2+2)
#define md ((lx+rx) >> 1)
  vector<int> seg, lazy;
  int ign;
  int sz;

  SegTree(int n) {
    sz = n;
    ign = 2e9; /// TODO::update this
    seg.assign(4 * n, {});
    lazy.assign(4 * n, {});
  }

  int merge(const int &lf, const int &rt) {
    return min(lf, rt); /// update this
  }

  void propagate(int x, int lx, int rx) {
    if (!lazy[x])return;
    if (lx != rx) {
      lazy[LF] += lazy[x];
      lazy[RT] += lazy[x];
    }
    seg[x] += lazy[x]; //// add lazy to the node
    lazy[x] = 0; //// set lazy value
  }

  void update(int l, int r, int v, int x = 0, int lx = 0, int rx = -1) {
    if (rx == -1)rx = sz - 1;
    propagate(x, lx, rx);
    if (l <= lx and rx <= r) {
      lazy[x] += v; //// add lazy to the node
      propagate(x, lx, rx);
      return;
    }
    if (r < lx or rx < l)return;
    update(l, r, v, LF, lx, md);
    update(l, r, v, RT, md + 1, rx);
    seg[x] = merge(seg[LF], seg[RT]);
  }

  int query(int l, int r, int x = 0, int lx = 0, int rx = -1) {
    if (rx == -1)rx = sz - 1;
    propagate(x, lx, rx);
    if (l <= lx and rx <= r) return seg[x];
    if (r < lx or rx < l) return ign;
    return merge(
        query(l, r, LF, lx, md),
        query(l, r, RT, md + 1, rx)
    );
  }

#undef md
#undef LF
#undef RT
};

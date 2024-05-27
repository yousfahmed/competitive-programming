/// update point / query range
struct SegTree {
  vector<int> seg;
  int N;
  int ign;

  SegTree(int n) {
    N = 1;
    while (N <= n)N <<= 1;
    ign = 0; /// update this
    seg.assign(N << 1, ign);
  }

  int mrg(int a, int b) { return a + b; }

  void update(int i, int val) {
    seg[i += N - 1] = val; /// update this
    while ((i >>= 1) >= 1) {
      seg[i] = mrg(seg[i << 1], seg[i << 1 | 1]);
    }
  }

  int query(int l, int r) {
    int ret = ign, k = 0;
    l += N - 2, r += N - 1;
    while ((l += (1 << k)) <= r) {
      ret = mrg(ret, seg[l >> (k = min(__lg(l & -l), __lg(r - l + 1)))]);
    }
    return ret;
  }
};
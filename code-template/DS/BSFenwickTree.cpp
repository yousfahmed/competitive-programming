struct BSFenwickTree {
public:
  vector<int> tree, vis;
  int n;

  BSFenwickTree(int n, int v = 0) {
    this->n = 1 << (__lg(n) + !!(n & (n - 1)));
    tree.assign(this->n + 1, v);
    vis.assign(this->n + 1, 0);
  }

  void update(int x, int v) {
    for (++x; x <= n; x += (x) & (-x)) {
      tree[x - 1] += v;
      vis[x - 1] += v < 0 ? -1 : 1;
    }
  }

  int query(int l, int r) {
    ++r;
    int res = 0;
    while (r > 0) {
      res += tree[r - 1];
      r -= r & -r;
    }
    while (l > 0) {
      res -= tree[l - 1];
      l -= l & -l;
    }
    return res;
  }

  /// max prefix [size] that has sum <= v
  int search(int v) {
    int p = 0, idx = 0;
    for (int sz = n >> 1; sz; sz >>= 1) {
      if (tree[p + sz - 1] <= v) {
        v -= tree[p + sz - 1];
        idx += vis[p + sz - 1];
        p += sz;
      }
    }
    return idx;
  }
};


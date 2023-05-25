template<typename T>
class BSFenwickTree {
public:
  vector<T> tree;
  vector<int> vis;
  int n;

  void init(int n, T v = 0) {
    this->n = 1 << (__lg(n) + !!(n & (n - 1)));
    tree.assign(this->n + 1, v);
    vis.assign(this->n + 1, 0);
  }

  T mrg(T &x, T &y) { return x + y; }

  void upd(int x, T v) {
    for (++x; x <= n; x += (x) & (-x)) {
      tree[x - 1] = mrg(tree[x - 1], v);
      vis[x - 1] += v < 0 ? -1 : 1;
    }
  }

  int search(T v) {
    /// max prefix size that has sum less than or equal to v
    int p = 0, idx = 0;
    if (tree[n - 1] <= v) {
      return vis[n - 1];
    }
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

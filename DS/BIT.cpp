/// point update - range query
struct BIT {
  vector<int> tree;

  BIT(int n) { tree.assign(n + 5, {}); }

  int query(int l, int r) {
    ++r;
    int res = 0;
    while (r > 0) {
      res += tree[r], r -= r & -r;
    }
    while (l > 0) {
      res -= tree[l], l -= l & -l;
    }
    return res;
  }

  void update(int i, int v) {
    ++i;
    while (i < tree.size()) {
      tree[i] += v;
      i += i & -i;
    }
  }

};
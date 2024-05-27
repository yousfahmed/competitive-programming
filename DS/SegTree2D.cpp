struct SegTree2d {
  int n, m;
  vector<vector<int>> seg;

  int neutral() const { return 1e8; }

  int merge(int a, int b) const { return min(a, b); }

  SegTree2d(int n, int m) : n(n), m(m) {
    seg = vector<vector<int>>(2 * n, vector<int>(2 * m, neutral()));
  }

  int qry(int x1, int y1, int x2, int y2) const {
    int ret = neutral();
    int y3 = y1 + m, y4 = y2 + m;
    for (x1 += n, x2 += n; x1 <= x2; ++x1 /= 2, --x2 /= 2) {
      for (y1 = y3, y2 = y4; y1 <= y2; ++y1 /= 2, --y2 /= 2) {
        if ((x1 & 1) and (y1 & 1))
          ret = merge(ret, seg[x1][y1]);
        if ((x1 & 1) and !(y2 & 1))
          ret = merge(ret, seg[x1][y2]);
        if (!(x2 & 1) and (y1 & 1))
          ret = merge(ret, seg[x2][y1]);
        if (!(x2 & 1) and !(y2 & 1))
          ret = merge(ret, seg[x2][y2]);
      }
    }
    return ret;
  }

  void upd(int x, int y, int val) {
    int y2 = y += m;
    for (x += n; x; x /= 2, y = y2) {
      if (x >= n)
        seg[x][y] = val;
      else
        seg[x][y] = merge(seg[2 * x][y], seg[2 * x + 1][y]);
      while (y /= 2)
        seg[x][y] = merge(seg[x][2 * y], seg[x][2 * y + 1]);
    }
  }
};
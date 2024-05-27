/// point update / sub-rectangle query
struct BIT2D {
  int n, m;
  vector<vector<int>> bit;

  BIT2D(int n, int m) : n(n), m(m) {
    bit.assign(n + 2, vector<int>(m + 2));
  }

  void update(int x, int y, int val) {
    ++x, ++y;
    for (; x <= n; x += x & -x) {
      for (int i = y; i <= m; i += i & -i) {
        bit[x][i] += val;
      }
    }
  }

  int prefix(int x, int y) {
    ++x, ++y;
    int res = 0;
    for (; x > 0; x -= x & -x) {
      for (int i = y; i > 0; i -= i & -i) {
        res += bit[x][i];
      }
    }
    return res;
  }

  int query(int sx, int sy, int ex, int ey) {
    int ans = 0;
    ans += prefix(ex, ey);
    ans -= prefix(ex, sy - 1);
    ans -= prefix(sx - 1, ey);
    ans += prefix(sx - 1, sy - 1);
    return ans;
  }
};
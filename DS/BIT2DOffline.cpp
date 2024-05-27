#define pii pair<int,int>

class BIT2D {
private:
  int n;  // max x-coordinate
  vector<vector<int>> vals, bit;

  // index of largest value <= x in v (sorted)
  // if v = [1, 2, 4], ind(v, 3) would return 1
  int ind(const vector<int> &v, int x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
  }

public:
  BIT2D(int n, vector<pii > &todo) : n(n), vals(n + 1), bit(n + 1) {
    // sort points by y-coordinate
    sort(todo.begin(), todo.end(), [](pii a, pii b) {
      return a.second < b.second;
    });
    // ensures vals and bit are 1-indexed
    for (int i = 1; i <= n; i++) { vals[i].push_back(0); }
    for (auto [x, y]: todo) {
      for (int z = x; z <= n; z += z & -z) {
        if (vals[z].back() != y) { vals[z].push_back(y); }
      }
    }
    for (int i = 1; i <= n; i++) {
      bit[i].resize(vals[i].size());
    }
  }

  /** adds t to the point (x, y) */
  void update(int x, int y, int val) {
    for (; x <= n; x += x & -x) {
      int z = ind(vals[x], y);
      assert(z && vals[x][z] == y);
      for (; z < bit[x].size(); z += z & -z) {
        bit[x][z] += val;
      }
    }
  }

  /** @return sum of points in rectangle with top-right corner (x, y) */
  int query(int x, int y) {
    int tot = 0;
    for (; x > 0; x -= x & -x) {
      for (int z = ind(vals[x], y); z > 0; z -= z & -z) {
        tot += bit[x][z];
      }
    }
    return tot;
  }

  /** @returns sum of points with x in [x1, x2] and y in [y1, y2] */
  int query(int x1, int x2, int y1, int y2) {
    if (x1 > x2 || y1 > y2) { return 0; }
    int tr = query(x2, y2);          // top-right
    int tl = query(x1 - 1, y2);      // top-left
    int br = query(x2, y1 - 1);      // bottom-right
    int bl = query(x1 - 1, y1 - 1);  // bottom-left
    return tr - tl - br + bl;
  }
};
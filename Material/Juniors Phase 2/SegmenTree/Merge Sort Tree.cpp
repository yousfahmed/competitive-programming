
#include <bits/stdc++.h>

using namespace std;

struct MergeSortTree {
private:
  vector<vector<int>> seg;
  int sz;

  void merge(vector<int> &res, vector<int> &a, vector<int> &b) {
    int l = 0, r = 0;
    res.reserve(a.size() + b.size());
    while (l < a.size() && r < b.size()) {
      if (a[l] < b[r]) {
        res.push_back(a[l++]);
      } else {
        res.push_back(b[r++]);
      }
    }
    while (l < a.size()) {
      res.push_back(a[l++]);
    }
    while (r < b.size()) {
      res.push_back(b[r++]);
    }
  }

  void built(vector<int> &a, int x, int lx, int rx) {
    if (lx == rx) {
      if (lx < a.size()) {
        seg[x] = {a[lx]};
      }
      return;
    }
    int m = (rx + lx) >> 1;
    built(a, x * 2 + 1, lx, m);
    built(a, x * 2 + 2, m + 1, rx);
    merge(seg[x], seg[x * 2 + 1], seg[x * 2 + 2]);
  }

  int query(int v, int lq, int rq, int x, int lx, int rx) {
    if (rq < lx || rx < lq)return 0;
    if (lq <= lx && rx <= rq) {
      return lower_bound(seg[x].begin(), seg[x].end(), v) - seg[x].begin();
    }
    int m = (rx + lx) >> 1;
    return query(v, lq, rq, x * 2 + 1, lx, m) +
           query(v, lq, rq, x * 2 + 2, m + 1, rx);
  }

public:
  MergeSortTree(vector<int> &a) {
    sz = 1;
    while (sz < a.size())sz <<= 1;
    seg = vector<vector<int>>(sz << 1);
    built(a, 0, 0, sz - 1);
  }

  int query(int v, int l, int r) {
    return query(v, l, r, 0, 0, sz - 1);
  }

};


int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> tmp;
  tmp.reserve(n);
  for (int &x: a) cin >> x, tmp.emplace_back(x);
  sort(tmp.begin(), tmp.end());
  for (int &x: a) {
    x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
  }
  MergeSortTree tree(a);
  int l, r, k;
  auto solve = [&]() -> int {
    --l, --r;
    int s = -1e9, e = 1e9, md, ans;
    while (s <= e) {
      md = (e - s) / 2 + s;
      if (tree.query(md, l, r) < k) {
        s = md + 1, ans = md;
      } else {
        e = md - 1;
      }
    }
    return ans;
  };
  while (m--) {
    cin >> l >> r >> k;
    cout << solve() << '\n';
  }


}

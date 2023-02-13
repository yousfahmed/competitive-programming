
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update>

struct MergeSortTree {
private:
  vector<ordered_set > seg;
  int sz;

  void built(vector<int> &a, int x, int lx, int rx) {
    if (lx == rx) {
      if (lx < a.size()) {
        seg[x].insert(a[lx]);
      }
      return;
    }
    int m = (rx + lx) >> 1;
    built(a, x * 2 + 1, lx, m);
    built(a, x * 2 + 2, m + 1, rx);
    for (const int &v: seg[x * 2 + 1])
      seg[x].insert(v);
    for (const int &v: seg[x * 2 + 2])
      seg[x].insert(v);
  }

  int query(int v, int lq, int rq, int x, int lx, int rx) {
    if (rq < lx || rx < lq)return 0;
    if (lq <= lx && rx <= rq) {
      return (int) seg[x].order_of_key(v);
    }
    int m = (rx + lx) >> 1;
    return query(v, lq, rq, x * 2 + 1, lx, m) +
           query(v, lq, rq, x * 2 + 2, m + 1, rx);
  }

  void update(int i, int old, int New, int x, int lx, int rx) {
    seg[x].erase(old), seg[x].insert(New);
    if (lx == rx) {
      return;
    }
    int m = (rx + lx) >> 1;
    if (i <= m) {
      update(i, old, New, x * 2 + 1, lx, m);
    } else {
      update(i, old, New, x * 2 + 2, m + 1, rx);
    }
  }

public:
  MergeSortTree(vector<int> &a) {
    sz = 1;
    while (sz < a.size())sz <<= 1;
    seg = vector<ordered_set >(sz << 1);
    built(a, 0, 0, sz - 1);
  }

  int query(int v, int l, int r) {
    return query(v, l, r, 0, 0, sz - 1);
  }

  void update(int i, int old, int New) {
    update(i, old, New, 0, 0, sz - 1);
  }
};


int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
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

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define int long long
#define MAXN 100005

int n, q;
int v[MAXN];
int vv[MAXN];

namespace mo {
  struct query {
    int idx, l, r, t;
  };
  struct update {
    int i, prevx, x;
  };

  int block;
  vector<query> queries;
  vector<update> updates;
  vector<int> ans;

  bool cmp(query x, query y) {
    if (x.l / block != y.l / block)
      return x.l / block < y.l / block;
    if (x.r / block != y.r / block)
      return x.r / block < y.r / block;
    return x.t < y.t;
  }

  void run() {
    block = 3153; // (2 * n) ^ 0.666
    sort(queries.begin(), queries.end(), cmp);
    ans.resize(queries.size());

    int l = 0, r = 0, t = 0, sum = 0;
    auto add = [&](int x) {
      sum += x;
    };
    auto rem = [&](int x) {
      sum -= x;
    };
    add(v[0]);
    for (const auto &q: queries) {
      while (r < q.r) add(v[++r]);
      while (l > q.l) add(v[--l]);
      while (r > q.r) rem(v[r--]);
      while (l < q.l) rem(v[l++]);

      while (t > q.t) {
        t--;
        if (q.l <= updates[t].i && q.r >= updates[t].i) {
          rem(updates[t].x);
          add(updates[t].prevx);
        }
        v[updates[t].i] = updates[t].prevx;
      }
      while (t < q.t) {
        if (q.l <= updates[t].i && q.r >= updates[t].i) {
          rem(updates[t].prevx);
          add(updates[t].x);
        }
        v[updates[t].i] = updates[t].x;
        t++;
      }
      ans[q.idx] = sum;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    vv[i] = v[i];
  }
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      mo::update curr{};
      cin >> curr.i >> curr.x;
      curr.prevx = vv[curr.i];
      vv[curr.i] = curr.x;
      mo::updates.pb(curr);
    } else {
      mo::query curr{};
      cin >> curr.l >> curr.r;
      curr.r--;
      curr.idx = (int) mo::queries.size();
      curr.t = (int) mo::updates.size();
      mo::queries.pb(curr);
    }
  }
  mo::run();
  for (auto const &i: mo::ans)
    cout << i << endl;
}
// 1 i v - set the element with index i to v
// 2 l r - calculate the sum of elements with indices from l to r - 1
// n, q <= 100000
// runs in 467ms
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define piii pair<pair<int,int>,int >
#define F first
#define S second

const int N = 1e5 + 5, mod1 = 1e9 + 7, mod2 = 2e9 + 11;

int pw1[N], pw2[N], n;

struct SegmentHash {
  vector<pii > seg;

  void init(int sz) {
    seg = vector<pii >(sz * 4);
  }

  pii merge(pii lf, pii rt, int sz) {
    pii res = lf;
    res.F = res.F * pw1[sz] % mod1;
    res.S = res.S * pw2[sz] % mod2;
    res.F = (res.F + rt.F) % mod1;
    res.S = (res.S + rt.S) % mod2;
    return res;
  }

  void update(int i, char v, int x = 0, int lx = 0, int rx = n - 1) {
    if (lx == rx) {
      seg[x] = {v, v};
    } else {
      int m = (rx + lx) >> 1;
      if (i <= m)
        update(i, v, x * 2 + 1, lx, m);
      else
        update(i, v, x * 2 + 2, m + 1, rx);
      seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2], rx - m);
    }
  }

  piii query(int l, int r, int x = 0, int lx = 0, int rx = n - 1) {
    if (l <= lx && rx <= r) return {seg[x], rx - lx + 1};
    if (r < lx || rx < l)return {{0, 0}, 0};
    int m = (rx + lx) >> 1;
    auto lf = query(l, r, x * 2 + 1, lx, m);
    auto rt = query(l, r, x * 2 + 2, m + 1, rx);
    auto res = merge(lf.F, rt.F, rt.S);
    return {res, lf.S + rt.S};
  }

} s1, s2;

bool solve(int l, int r) {
  if (l > r)swap(l, r);
  int sz = (r - l + 1);
  if (sz == 1)return 1;
  int m = (r + l) / 2;
  pii f, s;
  if (sz & 1) {
    f = s1.query(l, m - 1).F;
    s = s2.query(n - r - 1, n - m - 2).F;
  } else {
    f = s1.query(l, m).F;
    s = s2.query(n - r - 1, n - m - 2).F;
  }
  return f == s;
}

void solve() {
  int q;
  cin >> n >> q;
  s1 = SegmentHash();
  s2 = SegmentHash();
  s1.init(n), s2.init(n);
  int ty, l, r;
  char v;
  string str;
  for (int i = 0; i < n; ++i) {
    cin >> v;
    str += v;
    s1.update(i, v - 'a' + 1);
  }
  reverse(str.begin(), str.end());
  for (int i = 0; i < n; ++i) {
    s2.update(i, str[i] - 'a' + 1);
  }
  while (q--) {
    cin >> ty;
    if (ty == 1) {
      cin >> l >> v;
      s1.update(--l, v - 'a' + 1);
      s2.update(n - l - 1, v - 'a' + 1);
    } else {
      cin >> l >> r;
      cout << (solve(--l, --r) ? "Adnan Wins" : "ARCNCD!") << '\n';
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw1[i] = pw1[i - 1] * 31 % mod1;
    pw2[i] = pw2[i - 1] * 37 % mod2;
  }
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }

}

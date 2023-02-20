
#include <bits/stdc++.h>

#define pii pair<int,int>
#define int long long
using namespace std;
const int N = 1e5;
vector<vector<pii > > seg(N << 4);
int vis[N << 4], vs;

void update(int i, pii v, int x = 0, int lx = 1, int rx = N) {
  if (vis[x] != vs)
    vis[x] = vs, seg[x].clear();
  if (lx == rx) {
    seg[x].emplace_back(v);
  } else {
    int m = (rx + lx) >> 1;
    if (i <= m) update(i, v, x * 2 + 1, lx, m);
    else update(i, v, x * 2 + 2, m + 1, rx);
  }
}

void built(int x = 0, int lx = 1, int rx = N) {
  if (vis[x] != vs) {
    seg[x].clear();
    return;
  }
  if (lx == rx) {
    sort(seg[x].begin(), seg[x].end());
    for (int i = 1; i < seg[x].size(); ++i)
      seg[x][i].second = max(seg[x][i].second, seg[x][i - 1].second);
    return;
  }
  int m = (rx + lx) >> 1;
  built(x * 2 + 1, lx, m);
  built(x * 2 + 2, m + 1, rx);
  seg[x].clear();
  seg[x].resize(seg[x * 2 + 1].size() + seg[x * 2 + 2].size());
  int i = 0, j = 0, k = 0;
  while (i < seg[x * 2 + 1].size() && j < seg[x * 2 + 2].size()) {
    if (seg[x * 2 + 1][i] < seg[x * 2 + 2][j]) {
      seg[x][k] = seg[x * 2 + 1][i++];
    } else {
      seg[x][k] = seg[x * 2 + 2][j++];
    }
    if (k) seg[x][k].second = max(seg[x][k - 1].second, seg[x][k].second);
    ++k;
  }
  while (i < seg[x * 2 + 1].size()) {
    seg[x][k] = seg[x * 2 + 1][i++];
    if (k) seg[x][k].second = max(seg[x][k - 1].second, seg[x][k].second);
    ++k;
  }
  while (j < seg[x * 2 + 2].size()) {
    seg[x][k] = seg[x * 2 + 2][j++];
    if (k) seg[x][k].second = max(seg[x][k - 1].second, seg[x][k].second);
    ++k;
  }
}

int queryMax(int l, int r, int y, int x = 0, int lx = 1, int rx = N) {
  if (vis[x] != vs) return -1e9;
  if (l <= lx && rx <= r) {
    auto it = upper_bound(seg[x].begin(), seg[x].end(), make_pair(y, (int) 1e9));
    if (it == seg[x].begin())return -1e9;
    assert(it == seg[x].end() || it->first > y);
    --it;
    assert(it->first <= y);
    return it->second;
  }
  if (r < lx || rx < l)return -1e9;
  int m = (rx + lx) >> 1;
  return max(
      queryMax(l, r, y, x * 2 + 1, lx, m),
      queryMax(l, r, y, x * 2 + 2, m + 1, rx)
  );
}

void solve() {
  ++vs;
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> arr(n);
  auto ok = [&](int sz) -> bool {
    for (auto [x1, x2, y]: arr) {
      int l = x1 + sz, r = x2 - sz;
      if (r < l)continue;
      int mx = queryMax(l, r, y - sz);
      if (mx - y >= sz)return true;
    }
    return false;
  };
  for (int i = 0; i < n; ++i) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }
  for (int i = 0, y1, y2, x; i < m; ++i) {
    cin >> y1 >> y2 >> x;
    if (y1 > y2)swap(y1, y2);
    update(x, {y1, y2});
  }
  built();
  int s = 0, e = 1e5, md, ans = 0;
  while (s <= e) {
    md = (e - s) / 2 + s;
    if (ok(md)) {
      s = md + 1, ans = md;
    } else {
      e = md - 1;
    }
  }
  cout << ans;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    solve(), cout << '\n';
  }

}

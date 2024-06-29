#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<int> mt, vis;
int vid;

bool can(int u) {
  if (vis[u] == vid)return false;
  vis[u] = vid;
  for (int v: adj[u]) {
    if (mt[v] == -1 or can(mt[v])) {
      mt[v] = u;
      return true;
    }
  }
  return false;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;

  adj.assign(n * n, {});
  mt.assign(n * n, -1);
  vis.assign(n * n, {});

  auto inside = [&](int i, int j) {
    return i >= 0 and j < n and j >= 0 and i < n;
  };

  vector<vector<bool>> a(n, vector<bool>(n));
  for (int i = 0, x, y; i < k; ++i) {
    cin >> x >> y;
    a[--x][--y] = true;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (!a[i][j] or (i + j) & 1) continue;
      int u = i * n + j;
      for (int ii = -2; ii <= 2; ++ii)
        for (int jj = -2; jj <= 2; ++jj) {
          int x = i + ii, y = j + jj;
          if (!ii or !jj or abs(ii) == abs(jj))continue;
          if (!inside(x, y) or !a[x][y])continue;
          int v = x * n + y;
          adj[u].emplace_back(v);
          adj[v].emplace_back(u);
        }
    }

  int res{};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!a[i][j] or (i + j) & 1)continue;
      ++vid;
      int u = i * n + j;
      res += can(u);
    }
  }
  cout << res;
}

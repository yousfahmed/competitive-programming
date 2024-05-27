const int N = 1e5 + 5, LOG = 22;
int lvl[N];
int up[LOG][N];
int dp[LOG][N];
vector<vector<pair<int, int>>> adj; /// [v , w]

int mrg(int u, int v) { return max(u, v); }/* TODO */

void dfs0(int u, int p = -1) {
  for (int i = 1; i < LOG; i++) {
    up[i][u] = up[i - 1][up[i - 1][u]];
    dp[i][u] = mrg(dp[i - 1][u], dp[i - 1][up[i - 1][u]]);
  }
  for (auto [v, w]: adj[u]) {
    if (v == p)continue;
    up[0][v] = u;
    dp[0][v] = w;
    lvl[v] = lvl[u] + 1;
    dfs0(v, u);
  }
}

int LCA(int u, int v) {
  if (lvl[u] < lvl[v]) {
    swap(u, v);
  }
  int diff = lvl[u] - lvl[v];
  for (int i = LOG - 1; i >= 0; i--) {
    if (diff >> i & 1) {
      u = up[i][u];
    }
  }
  if (u == v)return u;
  for (int i = LOG - 1; i >= 0; i--) {
    if (up[i][u] != up[i][v]) {
      u = up[i][u], v = up[i][v];
    }
  }
  return up[0][u];
}

int query(int u, int v) {
  if (lvl[u] < lvl[v]) {
    swap(u, v);
  }
  int res = 0; /// TODO
  int diff = lvl[u] - lvl[v];
  for (int i = LOG - 1; i >= 0; i--) {
    if (diff >> i & 1) {
      res = mrg(res, dp[i][u]);
      u = up[i][u];
    }
  }
  if (u == v)return res;
  for (int i = LOG - 1; i >= 0; i--) {
    if (up[i][u] != up[i][v]) {
      res = mrg(res, mrg(dp[i][u], dp[i][v]));
      u = up[i][u], v = up[i][v];
    }
  }
  res = mrg(res, mrg(dp[0][u], dp[0][v]));
  return res;
}

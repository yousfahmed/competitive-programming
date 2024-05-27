const int N = 2e5 + 5;
vector<vector<int>> adj;
int in[N], lvl[N];
vector<vector<int>> euler;

void dfs0(int u, int par) {
  in[u] = euler[0].size();
  euler[0].emplace_back(u);
  for (auto &v: adj[u]) {
    if (par == v)continue;
    lvl[v] = lvl[u] + 1;
    dfs0(v, u);
    euler[0].emplace_back(u);
  }
}

int mrg(int u, int v) {
  return lvl[u] < lvl[v] ? u : v;
}

void precompute_lca(int root = 0) {
  euler = {{}};
  dfs0(root, -1);
  const int sz = euler[0].size();
  for (int msk = 1; (1 << msk) <= sz; ++msk) {
    euler.emplace_back(sz - (1 << msk) + 1);
    for (int i = 0; i + (1 << msk) <= sz; ++i) {
      euler[msk][i] = mrg(
          euler[msk - 1][i],
          euler[msk - 1][i + (1 << (msk - 1))]
      );
    }
  }
}

int query(int u, int v) {
  u = in[u], v = in[v];
  if (u > v)swap(u, v);
  int msk = __lg(v - u + 1);
  return mrg(
      euler[msk][u],
      euler[msk][v - (1 << msk) + 1]
  );
}
vector<vector<int>> adj;
vector<int> in, lvl;
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
  in.assign(adj.size(), {});
  lvl.assign(adj.size(), {});
  dfs0(root, 0);
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

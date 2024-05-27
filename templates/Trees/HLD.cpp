struct HLD {
private:
  void dfs0(int u, vector<vector<int>> &adj) {
    sz[u] = 1;
    for (int &v: adj[u]) {
      if (v == p[u])continue;
      dep[v] = dep[u] + 1;
      p[v] = u;
      dfs0(v, adj);
      sz[u] += sz[v];
      if (adj[u][0] == p[u] or sz[adj[u][0]] < sz[v])
        swap(v, adj[u][0]);
    }
  }

  void dfs1(int u, int top, int &timer, const vector<vector<int>> &adj) {
    in[u] = timer++, tp[u] = top;
    for (int v: adj[u]) {
      if (v == p[u])continue;
      if (v == adj[u][0]) dfs1(v, top, timer, adj);
      else dfs1(v, v, timer, adj);
    }
  }

public:
  vector<int> sz, p, dep, in, tp;

  HLD(vector<vector<int>> adj, int root = 0) {
    int n = adj.size();
    sz.assign(n, {});
    p.assign(n, {});
    dep.assign(n, {});
    in.assign(n, {});
    tp.assign(n, {});
    int t = 0;
    dfs0(root, adj);
    dfs1(root, root, t, adj);
  }

  int LCA(int u, int v) {
    while (tp[u] != tp[v]) {
      if (dep[tp[u]] < dep[tp[v]])swap(u, v);
      u = p[tp[u]];
    }
    if (dep[u] < dep[v])return u;
    return v;
  }

  int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
  }

  int pos(int node) { return in[node]; }

  pair<int, int> sub_tree(int u) { return {in[u], in[u] + sz[u] - 1}; }

  vector<pair<int, int>> query_path(int x, int y) {
    vector<pair<int, int>> res;
    while (tp[x] != tp[y]) {
      if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
      res.emplace_back(in[tp[x]], in[x]);
      x = p[tp[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    res.emplace_back(in[x], in[y]);
    return res;
  }

};

struct DSU {
  vector<int> par, sz, checkPoints;
  vector<pair<int, int>> updates;

  void init(int n) {
    par.assign(n + 1, {});
    iota(par.begin(), par.end(), 0);
    sz.assign(n + 1, 1);
    checkPoints.clear();
    updates.clear();
  }

  int find(int u) {
    while (u ^ par[u]) {
      u = par[u];
    }
    return u;
  }

  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) {
      return false;
    }
    if (sz[u] < sz[v]) {
      swap(u, v);
    }
    updates.emplace_back(v, u);
    sz[u] += sz[v];
    par[v] = u;
    return true;
  }

  void snapshot() {
    checkPoints.emplace_back(updates.size());
  }

  void rollback() {
    if (checkPoints.empty()) {
      return;
    }
    while (checkPoints.back() != updates.size()) {
      auto [v, u] = updates.back();
      updates.pop_back();
      sz[u] -= sz[v];
      par[v] = v;
    }
    checkPoints.pop_back();
  }

  int size(int u) {
    return sz[find(u)];
  }

  int sameSet(int u, int v) {
    return find(u) == find(v);
  }

};

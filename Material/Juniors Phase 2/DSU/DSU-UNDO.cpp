struct DSU {
  vector<int> par, sz;
  stack<array<int, 4>> op;
  stack<int> stack_size;

  DSU(int n) {
    par = sz = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
      sz[i] = 1;
    }
  }

  int find(int u) {
    if (par[u] == u)return u;
    op.push({u, par[u], -1, -1});
    return par[u] = find(par[u]);
  }

  bool merge(int u, int v) {
    stack_size.emplace(op.size()); /// 3
    u = find(u), v = find(v); /// + 3
    if (u != v) {
      if (sz[u] < sz[v]) {
        swap(u, v);
      }
      op.push({v, par[v], u, sz[u]}); /// +1
      par[v] = u;
      sz[u] += sz[v];
    }
    return u != v; /// 7
  }

  void Undo() {
    int goal = stack_size.top();
    stack_size.pop();
    while (goal < op.size()) {
      auto [u, p, v, s] = op.top();
      op.pop();
      par[u] = p;
      if (v != -1)sz[v] = s;
    }
  }
};

struct DSU_LOG {
  vector<int> par, sz;
  stack<array<int, 4>> op;

  DSU_LOG(int n) {
    par = sz = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
      sz[i] = 1;
    }
  }

  int find(int u) {
    if (par[u] == u)return u;
    return find(par[u]);
  }

  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
      if (sz[u] < sz[v])
        swap(u, v);
      op.push({v, par[v], u, sz[u]});
      par[v] = u;
      sz[u] += sz[v];
    } else {
      op.push({-1, -1, -1, -1});
    }
    return u != v;
  }

  void Undo() {
    auto [u, p, v, s] = op.top();
    op.pop();
    if (u != -1) {
      par[u] = p, sz[v] = s;
    }
  }
};

struct Query {
  int l, r, iq, lca;
  int64_t ord = -1;

  Query() {}

  Query(int l, int r, int iq, int lca) : l(l), r(r), lca(lca), iq(iq) {
    calcOrder();
  }

  /// make sure to call it
  inline void calcOrder() {
    if (ord == -1)
      ord = hilbertOrder(l, r, 21, 0);
  }

  bool operator<(const Query &other) const {
    return ord < other.ord;
  }
};

const int N = 1e5 + 5, B = 317;
vector<vector<int>> adj;
int in[N], out[N], tree[N << 1];
bool vis[N];
int t; /// reset this to 0 each testcase

void dfs0(int u, int p = -1) {
  tree[t] = u;
  in[u] = t++;
  for (int v: adj[u]) {
    if (v == p) continue;
    dfs0(v, u);
  }
  tree[t] = u;
  out[u] = t++;
}

void add(int node) {}
void rem(int node) {}

void toggle(int id) {
  int node = tree[id];
  if (vis[node]) {
    rem(node); // val of the node
  } else {
    add(node); // val of the node
  }
  vis[node] = !vis[node];
}

vector<int> mo(vector<Query> queries) {
  sort(queries.begin(), queries.end());
  int l = 0, r = -1;
  vector<int> res(queries.size());
  for (const auto [lq, rq, iq, lca, _]: queries) {
    while (r < rq) toggle(++r);
    while (l > lq) toggle(--l);
    while (r > rq) toggle(r--);
    while (l < lq) toggle(l++);
    if (lca >= 0) {
      add(lca);
    }
//    res[iq] = answer();
    if (lca >= 0) {
      rem(lca);
    }
  }
  return res;
}

Query addQuery(int u, int v, int i) {
  if (in[u] > in[v]) {
    swap(u, v);
  }
  auto isLca = [&](int u, int v) { return in[u] <= in[v] && out[u] >= out[v]; };
  int lca = LCA(u, v);
  if (isLca(u, v)) {
    u = in[u];
    v = in[v];
    lca = -1;
  } else {
    u = out[u];
    v = in[v];
  }
  Query q(u, v, i, lca);
  return q;
}
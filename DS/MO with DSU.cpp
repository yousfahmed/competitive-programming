const int N = 50007;
int par[N], sz[N];
int comp;
vector<int> checkPoints;
vector<array<int, 4>> op;
void init(int n) {
  comp = n;
  iota(par, par + n, 0);
  fill(sz, sz + n, 1);
  checkPoints.clear();
  op.clear();
}
int leader(int u) {
  if (par[u] == u)return u;
  op.push_back({u, par[u], -1, -1});
  return par[u] = leader(par[u]);
}
void join(const pair<int, int> &ed) {
  auto [u, v] = ed;
  if ((u = leader(u)) == (v = leader(v)))return;
  if (sz[u] < sz[v])swap(u, v);
  comp--;
  op.push_back({v, par[v], u, sz[u]});
  par[v] = u;
  sz[u] += sz[v];
}
void rollBack() {
  if (checkPoints.empty())return;
  while (op.size() > checkPoints.back()) {
    auto [u, p, v, s] = op.back();
    op.pop_back();
    par[u] = p;
    if (~v)sz[v] = s, comp++;
  }
  checkPoints.pop_back();
}
void createCheckPoint() { checkPoints.emplace_back(op.size()); }
int32_t main() {
  int n, m;
  cin >> n >> m;
  const int SQ = ceil(sqrt(m));
  init(n);
  vector<pair<int, int>> edges(m);
  vector<vector<array<int, 3>>> queries(SQ);
  for (auto &[u, v]: edges) {
    cin >> u >> v;
    --u, --v;
  }
  int q;
  cin >> q;
  int ans[q];
  for (int i = 0, l, r; i < q; ++i) {
    cin >> l >> r;
    --l, --r;
    if (r - l + 1 <= SQ) {
      createCheckPoint();
      while (l <= r) {
        join(edges[l++]);
      }
      ans[i] = comp;
      rollBack();
    } else {
      queries[l / SQ].push_back({r, l, i});
    }
  }
  for (auto &x: queries) {
    sort(x.begin(), x.end());
  }
  for (int b = 1; b <= SQ; ++b) {
    if (queries[b - 1].empty())continue;
    int R = min(b * SQ, m) - 1;
    createCheckPoint();
    join(edges[R]);
    for (auto [rq, lq, iq]: queries[b - 1]) {
      while (R < rq) {
        join(edges[++R]);
      }
      createCheckPoint();
      int L = min(m, b * SQ) - 1;
      while (lq < L) {
        join(edges[--L]);
      }
      ans[iq] = comp;
      rollBack();
    }
    rollBack();
  }
  for (int &x: ans) {
    cout << x << '\n';
  }
}
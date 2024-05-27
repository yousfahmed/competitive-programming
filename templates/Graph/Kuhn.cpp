vector<set<int>> adj;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
  if (used[v]) return false;
  used[v] = true;
  for (int to: adj[v]) {
    if (mt[to] == -1 || try_kuhn(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int run() {
  int n = adj.size();
  mt.assign(n, -1);
  for (int v = 0; v < n; ++v) {
    used.assign(n, false);
    try_kuhn(v);
  }
  int res{};
  for (int x: mt) res += (x != -1);
  return res;
}

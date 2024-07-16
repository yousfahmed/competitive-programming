#define ull unsigned long long
#define all(X) X.begin(),X.end()

ull pw(ull b, ull p) {
  if (!p) return 1;
  ull ret = pw(b, p >> 1);
  ret *= ret;
  if (p & 1)
    ret = ret * b;
  return ret;
}

ull dfs(int u, int par) {
  vector<ull> child;
  for (auto v: adj[u]) {
    if (v == par)continue;
    child.push_back(dfs(v, u));
  }
  sort(all(child));
  ull ret = 0;
  for (int i = 0; i < child.size(); ++i) {
    ret += child[i] * child[i] + child[i] * pw(31, i + 1) + (ull) 42;
  }
  return ret;
}

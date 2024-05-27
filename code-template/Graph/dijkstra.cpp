const int INF = 1e17;
vector<vector<pair<int, int>>> adj; // [v,w]

vector<int> dijkstra(int s, vector<int> &par) {
  int n = adj.size();
  vector<int> vis(n, INF);
  par.resize(n, -1);
  vis[s] = 0;
  set<pair<int, int>> st = {{0, s}};
  while (st.size()) {
    auto [d, u] = *st.begin();
    st.erase(st.begin());
    for (auto [v, w]: adj[u]) {
      int dd = w + d;
      if (vis[v] > dd) {
        par[v] = u;
        st.erase({vis[v], v});
        st.insert({vis[v] = dd, v});
      }
    }
  }
  return vis;
}

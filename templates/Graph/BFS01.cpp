void bfs01(int src) {
  const int n = adj.size();
  const int INF = 1e9;
  vector<int> d(n, INF);
  d[src] = 0;
  deque<int> q;
  q.push_front(src);
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge: adj[v]) {
      int u = edge.first;
      int w = edge.second;
      if (d[v] + w < d[u]) {
        d[u] = d[v] + w;
        if (w == 1)
          q.push_back(u);
        else
          q.push_front(u);
      }
    }
  }
}

const ll INF = 1e18;
vector<vector<pair<int, int>>> adj;

bool SPFA(int s, vector<ll> &d) {
  int n = adj.size();
  d.assign(n, INF);
  vector<int> cnt(n, 0);
  vector<bool> inqueue(n, false);
  queue<int> q;
  d[s] = 0;
  q.push(s);
  inqueue[s] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inqueue[u] = false;
    for (auto [v, w]: adj[u]) {
      if (d[u] + w >= d[v]) continue;
      d[v] = d[u] + w;
      if (!inqueue[v]) {
        q.push(v);
        inqueue[v] = true;
        cnt[v]++;
        if (cnt[v] > n)
          return false;
      }
    }
  }
  return true;
}

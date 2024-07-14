vector<vector<int> > adj;
vector<int> in; /// in-degree of each node
int n; // number of nodes
vector<int> res;

bool Topological() {
  queue<int> q;
  res.clear();
  for (int i = 0; i < n; ++i)
    if (in[i] == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    res.emplace_back(u);
    for (int v: adj[u])
      if (!--in[v])
        q.push(v);
  }
  return res.size() == n;
}

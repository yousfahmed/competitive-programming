const int N = 200;
int adj[N][N];
int INF;

vector<vector<int>> floyed() {
//  memset(adj, '?', sizeof adj);
//  INF = adj[0][0];
  auto d = adj;
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (d[i][k] < INF && d[k][j] < INF)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}
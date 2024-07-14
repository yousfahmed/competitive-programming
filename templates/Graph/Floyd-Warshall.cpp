/// Don't forget to set the adj initially to INF (INF + INF shouldn't overflow)
void floyd() {
  int i, j, k;
  for (i = 0; i < N; ++i)
    adj[i][i] = 0;
  for (k = 0; k < N; ++k) for (i = 0; i < N; ++i)
      for (j = 0; j < N; ++j)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int Gauss(vector<vector<int>> a, vector<int> &ans) {
  int n = a.size(), m = (int) a[0].size() - 1;
  vector<int> pos(m, -1);
  int free_var = 0;
  const ll MODSQ = (ll) mod * mod;
  int det = 1, rank = 0;
  for (int col = 0, row = 0; col < m && row < n; col++) {
    int mx = row;
    for (int k = row; k < n; k++) if (a[k][col] > a[mx][col]) mx = k;
    if (a[mx][col] == 0) {
      det = 0;
      continue;
    }
    for (int j = col; j <= m; j++) swap(a[mx][j], a[row][j]);
    if (row != mx) det = det == 0 ? 0 : mod - det;
    det = 1LL * det * a[row][col] % mod;
    pos[col] = row;
    int inv = power(a[row][col], mod - 2);
    for (int i = 0; i < n && inv; i++) {
      if (i != row && a[i][col]) {
        int x = ((ll) a[i][col] * inv) % mod;
        for (int j = col; j <= m && x; j++) {
          if (a[row][j]) a[i][j] = (MODSQ + a[i][j] - ((ll) a[row][j] * x)) % mod;
        }
      }
    }
    row++;
    ++rank;
  }
  ans.assign(m, 0);
  for (int i = 0; i < m; i++) {
    if (pos[i] == -1) free_var++;
    else ans[i] = ((ll) a[pos[i]][m] * power(a[pos[i]][i], mod - 2)) % mod;
  }
  for (int i = 0; i < n; i++) {
    ll val = 0;
    for (int j = 0; j < m; j++) val = (val + ((ll) ans[j] * a[i][j])) % mod;
    if (val != a[i][m]) return -1; //no solution
  }
  return free_var; //has solution
}

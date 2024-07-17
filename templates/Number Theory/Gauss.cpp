vector<ll> gauss(vector<vector<ll>> &a) {
  int n = a.size(), m = a[0].size() - 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= m; j++)
      a[i][j] = (a[i][j] % mod + mod) % mod;

  vector<int> where(m, -1);
  for (int col = 0, row = 0; col < m && row < n; col++) {
    int sel = row;
    for (int i = row; i < n; i++)
      if (a[i][col] > a[sel][col])
        sel = i;
    if (a[sel][col] == 0) {
      where[col] = -1;
      continue;
    }
    for (int i = col; i <= m; i++)
      swap(a[sel][i], a[row][i]);
    where[col] = row;
    ll c_inv = inv(a[row][col]);
    for (int i = 0; i < n; i++)
      if (i != row) {
        if (a[i][col] == 0) continue;
        ll c = (a[i][col] * c_inv) % mod;
        for (int j = 0; j <= m; j++)
          a[i][j] = (a[i][j] - c * a[row][j] % mod + mod) % mod;
      }
    row++;
  }
  vector<ll> ans(m, 0);
  ll ways = 1;
  for (int i = 0; i < m; i++) {
    if (where[i] != -1)
      ans[i] = a[where[i]][m] * inv(a[where[i]][i]) % mod;
    else
      ways = ways * mod % mod;
  }
  for (int i = 0; i < n; i++) {
    ll sum = a[i][m] % mod;
    for (int j = 0; j < m; j++)
      sum = (sum + mod - (ans[j] * a[i][j]) % mod) % mod;
    if (sum != 0) return {}; //Has No Sol
    return ans;
  }
}

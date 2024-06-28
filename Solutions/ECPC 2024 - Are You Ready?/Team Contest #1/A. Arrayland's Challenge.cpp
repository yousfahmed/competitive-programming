#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e4;
int dp[N][N];

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a[n];
  for (int &x: a) {
    cin >> x;
  }
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 2e6;
  }
  for (int sz = 2, l, r; sz <= n; ++sz) {
    for (l = 0, r = sz - 1; r < n; ++l, ++r) {
      dp[l][r] = min({
                         dp[l][r - 1],
                         dp[l + 1][r],
                         abs(a[l] - a[r])
                     });
    }
  }
  int q, l, r;
  cin >> q;
  while (q--) {
    cin >> l >> r;
    cout << dp[--l][--r] << '\n';
  }
}

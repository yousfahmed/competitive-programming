#include<bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size();
  vector<int> dp(n);
  dp[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    dp[i] = !dp[i + 1];
    if ((a[i] - a[i - 1]) > 1)
      dp[i] |= dp[i + 1];
  }
  cout << (dp[1] ? "Alicius\n" : "Bobius\n");
}

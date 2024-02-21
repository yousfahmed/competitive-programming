#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
  int n, k;
  cin >> n >> k;
  int res = -1;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    if (x >= k) {
      int v = x % k;
      if (res == -1 || res > v)res = v;
    }
  }
  cout << res << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}


#include <bits/stdc++.h>

using namespace std;

#define int long long


void solve() {
  int n;cin >> n;
  for (int i = 0,x; i < n; ++i) {
    cin >> x;
    cout << __builtin_popcount(x) << ' ';
  }

}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
    cout << '\n';
  }

}

#include <bits/stdc++.h>

using namespace std;

#define int long long


void solve() {
  int n, k;
  cin >> n >> k;
  cout << (n - k + 5) / 6;

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

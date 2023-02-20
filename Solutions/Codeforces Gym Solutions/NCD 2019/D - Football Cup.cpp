#include <bits/stdc++.h>

using namespace std;

#define int long long


void solve() {
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "Iskandar";
  } else if (x > y) {
    cout << "Bashar";
  } else {
    cout << "Hamada";
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

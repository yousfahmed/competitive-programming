#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, k;
  cin >> a >> b >> k;
  for (int x = 1; x <= k; ++x) {
    cout << a * x + b << ' ';
  }
}

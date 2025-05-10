#include <bits/stdc++.h>

using namespace std;
#define ll long long

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a[3], b[3];
  for (int &x: a) cin >> x;
  for (int &x: b) cin >> x;
  sort(b, b + 3);
  int ans = 0;
  do {
    int cur = 1;
    for (int i = 0; i < 3; ++i) {
      cur *= a[i] / b[i];
    }
    ans = max(ans, cur);
  } while (next_permutation(b, b + 3));

  cout << ans;
}

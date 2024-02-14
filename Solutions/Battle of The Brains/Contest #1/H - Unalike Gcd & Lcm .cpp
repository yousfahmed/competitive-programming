#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
  int x, q;
  cin >> x >> q;
  vector<int> primes;
  for (int i = 2; i <= x / i; ++i) {
    if (x % i)continue;
    int c = 0;
    while (!(x % i))++c, x /= i;
    primes.emplace_back(c);
  }
  if (x > 1)primes.emplace_back(1);
  int p;
  while (q--) {
    cin >> p;
    int res = 1;
    if (p > 1) {
      for (auto &pw: primes) {
        res <<= (pw % p == 0);
      }
    }
    cout << res << '\n';
  }

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


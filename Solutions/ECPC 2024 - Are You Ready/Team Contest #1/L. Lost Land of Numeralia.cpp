#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e3 + 1;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, sum, p;
  cin >> n >> q;
  while (q--) {
    cin >> sum >> p;
    int limit = n / p;
    ll res{};
    for (int sz = 2; sz <= N; ++sz) {
      ll ss = (sz - 1) * sz / 2;
      ll a = sum / p - ss;
      a = max(1ll, (a + sz - 1) / sz);
      if (p * (ss + a * sz) < sum)++a;
      ll r = (limit - sz + 1);
      if (r <= 0)break;
      res += max(0ll, r - a + 1);
    }
    cout << res << '\n';
  }
}

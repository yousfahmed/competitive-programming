#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 5;


void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> pref = {0};
  int res = 0;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    pref.emplace_back(x + pref.back());
    int s = 0, e = i + 1, md, ans = -1;
    while (s <= e) {
      md = (e - s) / 2 + s;
      if (pref.back() - pref[md] < k) {
        ans = md, e = md - 1;
      } else {
        s = md + 1;
      }
    }
    if (~ans)
      res += i + 1 - ans;
  }
  cout << res;
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

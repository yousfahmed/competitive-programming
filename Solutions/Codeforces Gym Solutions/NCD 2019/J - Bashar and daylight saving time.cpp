#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 5;


void solve() {
  int m, n;
  cin >> m >> n;
  int a[n];
  vector<int> pref(m + 5);
  for (int &x: a) cin >> x, --x;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    int s = a[i], &e = a[i];
    e += x;
    if (x >= 0) {
      if (e >= m) {
        ++s, ++e;
        ++pref[s], ++pref[1], --pref[e - m + 1];
      } else {
        ++s, ++e;
        ++pref[s], --pref[e + 1];
      }
    } else {
      if (e >= 0) {
        ++s, ++e;
        ++pref[e], --pref[s + 1];
      } else {
        ++s, ++e;
        --pref[s + 1], ++pref[1], ++pref[e + m];
      }
    }
  }
  int mx = -1, ans;
  for (int i = 1; i <= m; ++i) {
    pref[i] += pref[i - 1];
    if (pref[i] > mx)
      mx = pref[i], ans = i;
  }
  cout << ans << ' ' << mx;
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

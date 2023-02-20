#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 5;


void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  long double f;
  if (a) f = (long double) b * log(a);
  else f = -1;
  long double s;
  if (x) s = (long double) y * log(x);
  else s = -1;
  if (fabs(f - s) < 1e-9) {
    cout << "Lazy";
  } else if (f > s) {
    cout << "HaHa";
  } else {
    cout << "Congrats";
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

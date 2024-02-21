#include <bits/stdc++.h>

using namespace std;

int w1, w2, w3, a, b, c;

int p(int w) { return w < 5 ? a : w < 10 ? b : c; }

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> w1 >> w2 >> w3 >> a >> b >> c;
  int ans = p(w1) + p(w2) + p(w3);
  ans = min(ans, p(w1 + w2) + p(w3));
  ans = min(ans, p(w1 + w3) + p(w2));
  ans = min(ans, p(w3 + w2) + p(w1));
  ans = min(ans, p(w1 + w2 + w3));
  cout << ans << '\n';
}

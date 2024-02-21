#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> s >> n;
  vector<int> frq(26);
  for (auto &i: s) {
    frq[i - 'a']++;
  }
  int ans = s.size();
  while (n--) {
    char c;
    int x;
    cin >> c >> x;
    ans += (frq[c - 'a'] + x - 2) / (x - 1);
  }
  cout << ans ;
}

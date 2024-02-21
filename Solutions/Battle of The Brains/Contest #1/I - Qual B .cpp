#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; ++i) {
    if (k > 0 && s[i] == 'o') {
      --k;
    } else {
      s[i] = 'x';
    }
  }
  cout << s;
}


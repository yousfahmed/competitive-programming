#include <bits/stdc++.h>

using namespace std;
const int N = 500;
int mem[N][N][N + 1];
int n;
string s;

int dp(int l, int r, int rem) {
  if (rem == 0)return 0;
  if (r < l or (r - l + 1) < rem)return 1e9;
  int &res = mem[l][r][rem];
  if (~res)return res;
  res = min(dp(l + 1, r, rem), dp(l, r - 1, rem));
  res = min(
      res,
      (s[l] != s[r]) + dp(l + 1, r - 1, rem - 1 - (l != r))
  );
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> n >> k >> s;
  memset(mem, -1, sizeof mem);
  cout << dp(0, n - 1, k);
  return 0;
}

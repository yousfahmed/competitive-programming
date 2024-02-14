#include <bits/stdc++.h>

#define int long long
using namespace std;

const int M = 1e9 + 7, N = 5008;
int mem[N][N];

int dp(int i, int x) {
  if (i == 0) return !x;
  auto &ret = mem[i][x];
  if (~ret) return ret;
  ret = dp(i - 1, x);
  if (x >= 1) ret = (ret + dp(i - 1, x - 1)) % M;
  if (x >= 2) ret = (ret + dp(i - 1, x - 2)) % M;
  return ret;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ans = 1;
  memset(mem, -1, sizeof mem);
  for (int i = 2; i <= n; ++i) {
    ans = dp(i - 1, i) * ans % M;
  }
  cout << ans << '\n';
}

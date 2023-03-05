#include <bits/stdc++.h>

using namespace std;
vector<array<int, 2>> a;
int n, k;
int full;

double mem[19][(1 << 18) + 5];

double dis(int i, int j) {
  return ::hypot(a[i][0] - a[j][0], a[i][1] - a[j][1]);
}

double dp(int i, int msk) {
  if (msk == full)return dis(i, k);
  double &ret = mem[i][msk];
  if (ret == ret)return ret;
  ret = 0;
  for (int j = 0; j < n; ++j) {
    if (msk & (1 << j))continue;
    ret = min(
        ret,
        dp(j, msk | (1 << j)) + dis(i, j)
    );
  }
  return ret;
}


int32_t main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  memset(mem, -1, sizeof mem);
  cin >> n >> k, --k;
  full = (1 << n) - 1;
  a.resize(n);
  for (auto &[x, y]: a)cin >> x >> y;
  cout << dp(k, 1 << k);
}

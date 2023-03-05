#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 200000 + 5, mod = 5000000;

struct BIT {

  int bit[N];

  BIT() {
    memset(bit, 0, sizeof bit);
  }

  int query(int i) {
    int res = 0;
    for (++i; i > 0; i -= i & -i) {
      res += bit[i];
      if (res >= mod)res -= mod;
    }
    return res;
  }

  void add(int i, int v) {
    for (++i; i < N; i += i & -i) {
      bit[i] += v;
      if (bit[i] >= mod)bit[i] -= mod;
    }
  }
} dp[51];

int n, k;
int a[N];


void solve() {
  for (int sz = 2; sz <= k; ++sz) {
    for (int j = 0; j < n; ++j) {
      int value = a[j];
      dp[sz].add(
          value,
          dp[sz - 1].query(value - 1)
      );
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] += 2;
    dp[1].add(a[i], 1);
  }
  solve();
  cout << dp[k].query(N - 1) << '\n';
}

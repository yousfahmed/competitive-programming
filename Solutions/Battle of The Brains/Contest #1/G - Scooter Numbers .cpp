#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e3 + 5, mod = 1e9 + 7;

int add(int a, int b) { return (a + b) % mod; }

int dp1[N][N];
int dp2[N][N];

int increasing(int i, int rem) {
  if (rem == 0)return 1;
  if (rem < i)return 0;
  int &res = dp1[i][rem];
  if (~res)return res;
  res = increasing(i + 1, rem);
  if (rem >= i) {
    res = add(res, increasing(i, rem - i));
  }
  return res;
}

int decreasing(int i, int rem) {
  if (rem == 0)return i <= 1;
  if (rem < 0 || i == 0)return 0;
  int &res = dp2[i][rem];
  if (~res)return res;
  res = add(
      decreasing(i, rem - i),          /// add same number
      decreasing(i - 1, rem - i + 1) /// add (i-1) to the list
  );
  return res;
}


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  
  int n;
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n + 1; ++i) {
    for (int sumNext = 0, sumBefore = n; sumNext <= n; ++sumNext, sumBefore--) {
      int after_mex = increasing(i + 1, sumNext);
      int before_mex = decreasing(i - 1, sumBefore - i + 1);
      int cnt = after_mex * before_mex % mod;
      res = add(res, cnt * i % mod);
    }
  }
  cout << res;

}

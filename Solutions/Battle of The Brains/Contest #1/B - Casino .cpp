#include <bits/stdc++.h>

#define int long long
using namespace std;
const int mod = 1e9 + 7, N = 1e5 + 5;
int fact[N], inv[N];
int f[3];

int power(int a, int p) {
  if (!p)return 1;
  int res = power(a, p / 2);
  res = res * res % mod;
  if (p & 1)res = res * a % mod;
  return res;
}

int per(int n, int k) {
  if (k > n)return 0;
  return fact[n] * inv[n - k] % mod;
}

int solve(int i) {
  if (!f[1] && !f[2])return 1;
  int res = f[i];
  if (res == 0)return 0;
  f[i]--;
  res = res * solve((i + i) % 3) % mod;
  f[i]++;
  return res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  fact[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = i * fact[i - 1] % mod;
    inv[i] = power(fact[i], mod - 2);
  }
  int n;
  cin >> n;
  for (int i = 0, x; i < n; ++i) {
    cin >> x, f[x % 3]++;
  }
  int a = 0, b = 0;
  if (f[1]) {
    f[1]--;
    a = (f[1] + 1) * solve(1) % mod;
    f[1]++;
  }
  if (f[2]) {
    f[2]--;
    b = (f[2] + 1) * solve(2) % mod;
    f[2]++;
  }
  int c = per(n - 1, f[0]);
  cout << (a + b) % mod * c % mod;
}

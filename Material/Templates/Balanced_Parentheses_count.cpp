/*https://codeforces.com/blog/entry/87585 */
#include <bits/stdc++.h>

using namespace std;
#define int long long


struct Balanced_Parentheses_count {
  /*
   *  General formula is
   *   fact[n*2] * modinv( fact[n] * fact[n+1] )
   */

  static int power(int n, int p, int mod) {
    if (!p)return 1;
    int res = power(n, p / 2, mod);
    res = 1ll * res * res % mod;
    if (p & 1)res = 1ll * res * n % mod;
    return res;
  }

  /// n is the size of the string
  static int only_one_use(int n, int mod) {
    if (n & 1)return 0;
    n /= 2;
    long long a = 1, b = 1, c = 1;
    for (int i = 1; i <= 2 * n; ++i) {
      a = a * i % mod;
      if (i == n)b = a;
      if (i == n + 1)c = a;
    }
    return a * power(b, mod - 2, mod) % mod * power(c, mod - 2, mod) % mod;
  }

  /// n is the size of the string
  /// with k different type
  static int only_one_use(int n, int k, int mod) {
    if (n & 1)return 0;
    n /= 2;
    long long a = 1, b = 1, c = 1;
    for (int i = 1; i <= 2 * n; ++i) {
      a = a * i % mod;
      if (i == n)b = a;
      if (i == n + 1)c = a;
    }
    int res = a * power(b, mod - 2, mod) % mod * power(c, mod - 2, mod) % mod;
    return res * power(k, n, mod) % mod;
  }
};


signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  cout << Balanced_Parentheses_count::only_one_use(n * 2, k, 1e9 + 7);
}

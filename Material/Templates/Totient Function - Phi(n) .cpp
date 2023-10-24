#include <bits/stdc++.h>

using namespace std;
#define ll long long

//int phi(int n) {
//  int res = n;
//  for (int i = 2; i * i <= n; ++i) {
//    if (n % i)continue;
//    res -= (res / i);
//    while (!(n % i))n /= i;
//  }
//  if (n > 1) {
//    res -= (res / n);
//  }
//  return res;
//}

const int N = 1e7 + 1, M = 1e5 + 1;

ll phi[M], bg_prime[M];
int p[664'579 + 1], cnt;
bool vis[N];
//// 664'579

void pre_phi(ll a, ll b) {
  int n = b - a + 1;
  iota(phi, phi + n + 1, a);
  iota(bg_prime, bg_prime + n + 1, a);
  for (int i = 0; i < cnt && p[i] <= b / p[i]; ++i) {
    for (ll j = ((a + p[i] - 1) / p[i]) * p[i]; j <= b; j += p[i]) {
      phi[j - a] -= (phi[j - a] / p[i]);
      while (!(bg_prime[j - a] % p[i])) {
        bg_prime[j - a] /= p[i];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (bg_prime[i] != 1) {
      phi[i] -= phi[i] / bg_prime[i];
    }
  }
}

void sieve() {
  for (int i = 2; i < N; ++i) {
    if (!vis[i]) {
      p[cnt++] = i;
      for (ll j = 1LL * i * i; j < N; j += i) {
        vis[j] = true;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  sieve();
  pre_phi(a, b);
  for (int i = 0; i < b - a + 1; ++i) {
    cout << phi[i] << '\n';
  }
}

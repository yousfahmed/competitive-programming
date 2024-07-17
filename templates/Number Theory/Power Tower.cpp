map<ll, ll> mp;

ll phi(ll n) {
  if (mp.count(n)) return mp[n];
  ll ans = n, m = n;
  for (ll i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      while (m % i == 0) m /= i;
      ans = ans / i * (i - 1);
    }
  }
  if (m > 1) ans = ans / m * (m - 1);
  return mp[n] = ans;
}

inline ll MOD(ll x, ll m) {
  if (x < m) return x;
  return x % m + m;
}

ll power(ll n, ll k, ll mod) {
  ll ans = MOD(1, mod);
  while (k) {
    if (k & 1) ans = MOD(ans * n, mod);
    n = MOD(n * n, mod);
    k >>= 1;
  }
  return ans;
}

// if x >= log2(m), then a^x = a^(MOD(x, phi(m))) % m
ll powerTower(const vector<int> &a, ll l, ll r, ll m) {
  if (l == r) return MOD(a[l], m);
  if (m == 1) return 1;
  return power(a[l], powerTower(a, l + 1, r, phi(m)), m);
}

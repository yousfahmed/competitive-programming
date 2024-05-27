#define ll long long
#define M first
#define R second
typedef pair<ll, ll> mod_eq;

void nxt_r(ll &r0, ll &r1, ll &r) {
  int r2 = r0 - r * r1;
  r0 = r1, r1 = r2;
}

// r0 = a , r1 = b
// return gcd = a * x0 + b * y0
ll egcd(ll r0, ll r1, ll &x0, ll &y0) {
  ll x1 = y0 = 0, y1 = x0 = 1;
  while (r1) {
    ll r = r0 / r1;
    nxt_r(r0, r1, r);
    nxt_r(x0, x1, r);
    nxt_r(y0, y1, r);
  }
  return r0;
}

// c = x * a + y * b
// x` = x - (b / g) * k , y` = y + (a / g) * k - for any k
bool solveLDE(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
  g = egcd(a, b, x, y);
  ll m = c / g;
  x *= m, y *= m;
  return m * g == c;
}

bool mod_inv(ll a, ll mod, ll &x) {
  ll y, g = egcd(a, mod, x, y);
  if (g != 1) {
    return false; // a and mod are not co-prime
  }
  x %= mod;
  if (x < 0)x += mod;
  return true;
}

bool CRT(const mod_eq &e1, const mod_eq &e2, mod_eq &res) {
  ll q1, q2, g;
  if (!solveLDE(e1.M, -e2.M, e2.R - e1.R, q1, q2, g)) {
    return false;
  }
  q2 %= e1.M / g;
  ll lcm = abs(e1.M / g * e2.M);
////  ll x = ((__int128) e2.M * (__int128) q2 + (__int128) e2.R) % lcm; ??
  ll x = e2.M * q2 + e2.R;
  x %= lcm;
  if (x < 0)x += lcm;
  res = {lcm, x};
  return true;
}

bool CRT(const vector<mod_eq> &eq, mod_eq &ret) {
  ret = eq[0];
  for (int i = 1; i < eq.size(); ++i) {
    if (!CRT(eq[i], ret, ret)) {
      return false;
    }
  }
  return true;
}
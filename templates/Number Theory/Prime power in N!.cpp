ll count_p_in_nfact(ll p, ll n) {
  ll res = 0, q = p;
  while (q <= n) {
    res += n / q, q *= p;
  }
  return res;
}

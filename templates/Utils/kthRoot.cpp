ll kthRoot(ll n, ll k) // return integer kth root for n
{ // Also can be done by binary search for accurate results
  double root = powl((double) n, 1.0 / (double) k);
  // will have percision errors
  ll realRoot = (ll) (root - 1);
  while (1) {
    ll a = realRoot + 1, p = 1;
    // compute a^k
    for (int j = 0; j < k; j++) {
      if (p > n / a) // we exceed n, this also detect overflow
        return realRoot;
      p *= a;
    }
    ++realRoot;
  }
}

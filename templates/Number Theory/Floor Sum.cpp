// \sum{k=1}^{n}{floor(n/k)}
// count of numbers such that n/i = k -> n/k - n/(k+1)
ll floor_sum(ll n) {
  ll sum = 0;
  for (ll i = 1, last; i <= n; i = last + 1) {
    last = n / (n / i);
    sum += (n / i) * (last - i + 1);
    // n / x yields the same value for i <= x <= last.
  }
  return sum;
}

void Divbygcd(ll &a, ll &b) {
  ll g = gcd(a, b);
  a /= g, b /= g;
}

ll nCr(int n, int k) {
  if (n < k) return 0;
  if (k > n / 2) k = n - k; // use smaller k
  ll numerator = 1, denominator = 1, toMul, toDiv, i;
  for (i = k; i; i--) {
    toMul = n - k + i;
    toDiv = i;
    Divbygcd(toMul, toDiv); // always divide before multiply
    Divbygcd(numerator, toDiv);
    Divbygcd(toMul, denominator);
    numerator *= toMul;
    denominator *= toDiv;
  }
  return numerator / denominator;
}

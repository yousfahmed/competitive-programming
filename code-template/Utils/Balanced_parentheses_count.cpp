/// n size of the string , k is the number of different type
int Balanced_parentheses_count(int n, int k, int mod) {
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
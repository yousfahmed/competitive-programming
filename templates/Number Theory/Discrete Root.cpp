// returns any or all numbers x such that x ^ k = a (mod m)
// existence: a = 0 is trivial, and if a > 0: a ^ (phi(m) / gcd(k, phi(m))) == 1 mod m
// if solution exists, then number of solutions = gcd(k, phi(m)).
// here m is prime, but it will work for any integer which has a primitive root
int discrete_root(int k, int a, int m) {
  if (a == 0) return 1;
  int g = primitive_root(m);
  int phi = m - 1; // m is prime
  // run baby step-giant step
  int sq = (int) sqrt(m + .0) + 1;
  vector<pair<int, int>> dec(sq);
  for (int i = 1; i <= sq; ++i) dec[i - 1] = make_pair(power(g, 1LL * i * sq % phi * k % phi, m), i);
  sort(dec.begin(), dec.end());
  int any_ans = -1;
  for (int i = 0; i < sq; ++i) {
    int my = power(g, 1LL * i * k % phi, m) * 1LL * a % m;
    auto it = lower_bound(dec.begin(), dec.end(), make_pair(my, 0));
    if (it != dec.end() && it->first == my) {
      any_ans = it->second * sq - i;
      break;
    }
  }
  if (any_ans == -1) return -1; //no solution
  // for any answer
  int delta = (m - 1) / __gcd(k, m - 1);
  return power(g, any_ans % delta, m);
  // // for all possible answers
  // int delta = (m - 1) / __gcd(k, m - 1);
  // vector<int> ans;
  // for (int cur = any_ans % delta; cur < m-1; cur += delta) ans.push_back(power(g, cur, m));
  // sort(ans.begin(), ans.end());
  // // assert(ans.size() == __gcd(k, m - 1))
  // return ans;
}

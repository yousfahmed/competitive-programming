#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

int phi(int n) {
  int res = n;
  for (int i = 2; i <= n / i; ++i) {
    if (n % i)continue;
    res -= res / i;
    while (!(n % i))n /= i;
  }
  if (n > 1) {
    res -= res / n;
  }
  return res;
}

struct mul {
  int mod;
  mul(int mod) : mod(mod) {}
  int operator()(int a, int b) const { return a * 1ll * b % mod; }
};

int identity_element(const mul &) { return 1; }

//// a ^ x = b (% mod) --- O( sqrt(mod) )
bool DiscreteLog(int a, int b, int mod, int &x) {
  a %= mod; //// b %= mod ???
  mul M(mod);
  int alpha = 1, add = 0, g;
  while ((g = __gcd(a, mod)) > 1) {
    if (b == alpha)
      return x = add, true;
    if (b % g)return false;
    b /= g;
    mod /= g;
    M = mul(mod);
    ++add;
    alpha = M(alpha, a / g);
  }
  int ph = phi(mod);
  int inv = power(a, ph - 1, M);
  unordered_map<int, int> mp;
  int m = ceil(sqrt(mod));
  int k = 1;
  for (int i = 0, j = alpha; i < m; ++i) {
    mp.emplace(j, i);
    j = M(j, a);
    k = M(k, inv);
  }
  x = -1;
  for (int i = 0, j = b; i < m; ++i) {
    auto it = mp.find(j);
    if (it != mp.end()) {
      int cur = it->second + i * m + add;
      if (x == -1 || cur < x)
        x = cur;
    }
    j = M(j, k);
  }
  return x != -1;
}

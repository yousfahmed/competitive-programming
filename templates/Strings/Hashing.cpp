const int N = 3e5 + 5;
#define fr first
#define sc second
int B1, B2, MOD1, MOD2;
int pw1[N], pw2[N];

struct Hash {
private:
  vector<pair<int, int>> prefix, suffix;
  int n;

  void hash_prefix(const string &str) {
    int h1 = 0, h2 = 0;
    prefix.clear();
    prefix.reserve(str.size());
    for (char i: str) {
      h1 = (1LL * h1 * B1) % MOD1;
      h1 = (h1 + i) % MOD1;
      h2 = (1LL * h2 * B2) % MOD2;
      h2 = (h2 + i) % MOD2;
      prefix.emplace_back(h1, h2);
    }
  }

  void hash_suffix(const string &str) {
    int h1 = 0, h2 = 0;
    suffix.assign(n, {});
    for (int i = n - 1; i >= 0; i--) {
      h1 = (1LL * h1 * B1) % MOD1;
      h1 = (h1 + str[i]) % MOD1;
      h2 = (1LL * h2 * B2) % MOD2;
      h2 = (h2 + str[i]) % MOD2;
      suffix[i] = {h1, h2};
    }
  }

public:
  Hash() {}

  Hash(const string &s) { build(s); }

  void build(const string &s) {
    assert(B1);
    n = s.size();
    hash_prefix(s);
    hash_suffix(s); /// we need this ?
  }

  pair<int, int> getSuffix(int l, int r) {
    auto ret = suffix[l];
    int len = r - l + 1;
    r++;
    if (r < n) {
      ret.fr -= 1LL * suffix[r].fr * pw1[len] % MOD1;
      if (ret.fr < 0)ret.fr += MOD1;

      ret.sc -= 1LL * suffix[r].sc * pw2[len] % MOD2;
      if (ret.sc < 0)ret.sc += MOD2;

    }
    return ret;
  }

  pair<int, int> getPrefix(int l, int r) {
    auto ret = prefix[r];
    int sz = r - l + 1;
    l--;
    if (l >= 0) {
      ret.fr -= 1LL * prefix[l].fr * pw1[sz] % MOD1;
      if (ret.fr < 0)ret.fr += MOD1;
      ret.sc -= 1LL * prefix[l].sc * pw2[sz] % MOD2;
      if (ret.sc < 0)ret.sc += MOD2;
    }
    return ret;
  }
};

void build() {
  if (B1)return;
  random_device rd;
  mt19937 mt(rd());
  auto rnd = [&](int l, int r) { return uniform_int_distribution<int>(l, r)(mt); };
  auto check = [](int x) {
    for (int i = 2; i <= x / i; ++i) if (!(x % i)) return false;
    return true;
  };
  B1 = rnd(100, 500);
  B2 = rnd(100, 500);
  MOD1 = rnd(2e8, 2e9);
  MOD2 = rnd(2e8, 2e9);
  while (!check(MOD1))MOD1--;
  while (MOD1 == MOD2 or !check(MOD2))MOD2--;
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw1[i] = 1LL * pw1[i - 1] * B1 % MOD1;
    pw2[i] = 1LL * pw2[i - 1] * B2 % MOD2;
  }
}

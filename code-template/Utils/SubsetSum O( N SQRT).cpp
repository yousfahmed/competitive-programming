// Computes all possible subset sums from 0 to n that can be made using values from sizes. Runs in O(n sqrt n / 64) if
// the sum of sizes is bounded by n, and O(n^2 / 64) otherwise.
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
struct custom_bitset {
  vector<uint64_t> bits;
  int64_t b, n;

  custom_bitset(int64_t _b = 0) { init(_b); }

  void init(int64_t _b) {
    b = _b;
    n = (b + 63) / 64;
    bits.assign(n, 0);
  }

  void clear() {
    b = n = 0;
    bits.clear();
  }

  void reset() {
    bits.assign(n, 0);
  }

  void _clean() {
    // Reset all bits after `b`.
    if (b != 64 * n)
      bits.back() &= (1LLU << (b - 64 * (n - 1))) - 1;
  }

  bool get(int64_t index) const {
    return bits[index / 64] >> (index % 64) & 1;
  }

  void set(int64_t index, bool value) {
    assert(0 <= index && index < b);
    bits[index / 64] &= ~(1LLU << (index % 64));
    bits[index / 64] |= uint64_t(value) << (index % 64);
  }

  // Simulates `bs |= bs << shift;`
  void or_shift(int64_t shift) {
    int64_t div = shift / 64, mod = shift % 64;

    if (mod == 0) {
      for (int64_t i = n - 1; i >= div; i--)
        bits[i] |= bits[i - div];

      return;
    }

    for (int64_t i = n - 1; i >= div + 1; i--)
      bits[i] |= bits[i - (div + 1)] >> (64 - mod) | bits[i - div] << mod;

    if (div < n)
      bits[div] |= bits[0] << mod;

    _clean();
  }

  // Simulates `bs |= bs >> shift;`
  void or_shift_down(int64_t shift) {
    int64_t div = shift / 64, mod = shift % 64;

    if (mod == 0) {
      for (int64_t i = div; i < n; i++)
        bits[i - div] |= bits[i];

      return;
    }

    for (int64_t i = 0; i < n - (div + 1); i++)
      bits[i] |= bits[i + (div + 1)] << (64 - mod) | bits[i + div] >> mod;

    if (div < n)
      bits[n - div - 1] |= bits[n - 1] >> mod;

    _clean();
  }

  int64_t find_first() const {
    for (int i = 0; i < n; i++)
      if (bits[i] != 0)
        return 64 * i + __builtin_ctzll(bits[i]);

    return -1;
  }

  custom_bitset &operator&=(const custom_bitset &other) {
    assert(b == other.b);

    for (int i = 0; i < n; i++)
      bits[i] &= other.bits[i];

    return *this;
  }
};
custom_bitset possible_subsets_knapsack(int n, const vector<int> &sizes) {
  vector<int> freq(n + 1, 0);
  for (int s: sizes) if (1 <= s && s <= n) freq[s]++;
  custom_bitset knapsack(n + 1);
  knapsack.set(0, 1);
  for (int s = 1; s <= n; s++) {
    if (freq[s] >= 3) {
      int move = (freq[s] - 1) / 2;
      if (2 * s <= n) freq[2 * s] += move;
      freq[s] -= 2 * move;
    }
    for (int r = 0; r < freq[s]; r++)
      knapsack.or_shift(s);
  }
  return knapsack;
}
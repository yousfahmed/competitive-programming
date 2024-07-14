template<typename T = int, int B = 31>
struct Basis {
  T a[B];
  Basis() {
    memset(a, 0, sizeof a);
  }
  void insert(T x){
    for (int i = B - 1; i >= 0; i--) {
      if (x >> i & 1) {
        if (a[i]) x ^= a[i];
        else {
          a[i] = x;
          break;
        }
      }
    }
  }
  bool can(T x) {
    for(int i = B - 1; i >= 0; i--) {
      x = min(x, x ^ a[i]);
    }
    return x == 0;
  }
  T max_xor(T ans = 0) {
    for(int i = B - 1; i >= 0; i--) {
      ans = max(ans, ans ^ a[i]);
    }
    return ans;
  }
};

#define ABS(x) ((x)>=0?(x):-(x))

struct frac {
  long long n, d;

  frac(const long long &N, const long long &D = 1) :
    n(N), d(D) {
    long long g = gcd(ABS(n), ABS(d));
    if (!g) {
      this->n = this->d = 0;
      return;
    }
    n /= g, d /= g;
    if (n == 0) d = 1;
    if (d < 0) n *= -1, d *= -1;
    if (d == 0) n = 1;
  }

  bool operator<(const frac &f) const {
    return n * f.d < d * f.n;
  }

  frac operator*(const frac &f) const {
    return frac(n * f.n, d * f.d);
  }

  frac operator/(const frac &f) const {
    return frac(n * f.d, d * f.n);
  }

  frac operator-(const frac &f) const {
    return frac(n * f.d - d * f.n, d * f.d);
  }

  frac operator+(const frac &f) const {
    return frac(n * f.d + d * f.n, d * f.d);
  }
};

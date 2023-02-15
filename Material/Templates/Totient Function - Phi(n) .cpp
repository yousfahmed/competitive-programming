#define int long long
int phi(int n) {
    int ret = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int p = 1;
            while (!(n % i)) {
                n /= i;
                p *= i;
            }
            ret *= ((p / i) * (i - 1));
        }
    }
    if (n > 1)ret *= (n - 1);
    return ret;
}

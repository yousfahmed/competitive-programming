int Phi(int n) {
    int ret = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            ret -= ret / i;
        }
    }
    if (n > 1)
        ret -= ret / n;
    return ret;
}
void Phi_1_n() {
  iota(phi, phi + N, 0);
  for (int i = 2; i < N; ++i) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i)
        phi[j] -= phi[j] / i;
    }
  }
}

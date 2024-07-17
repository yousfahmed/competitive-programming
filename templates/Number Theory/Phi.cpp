void Phi_1_n() {
  iota(phi, phi + N, 0);
  for (int i = 2; i < N; ++i) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i)
        phi[j] -= phi[j] / i;
    }
  }
}

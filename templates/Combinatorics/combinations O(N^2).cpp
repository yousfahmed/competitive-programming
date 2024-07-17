const int MAX = 31;
int comb[MAX][MAX];

void pre() {
  comb[0][0] = 1;
  for (int i = 1; i <= MAX; i++) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; j++)
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
  }
}

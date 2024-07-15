vector<int> kmp(const string &s) {
  const int n = (int) s.length();
  vector<int> fail(n);
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && s[i] != s[j]) j = fail[j - 1];
    j += (s[j] == s[i]);
    fail[i] = j;
  }
  return fail;
}

void compute_automaton(string s, vector<vector<int>> &aut) {
  s += '#';
  int n = s.size();
  vector<int> pi = kmp(s);
  aut.assign(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (i > 0 && 'a' + c != s[i]) {
        aut[i][c] = aut[pi[i - 1]][c];
      } else {
        aut[i][c] = i + ('a' + c == s[i]);
      }
    }
  }
}

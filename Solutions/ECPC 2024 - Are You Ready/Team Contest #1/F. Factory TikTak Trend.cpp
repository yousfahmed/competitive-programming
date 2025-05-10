#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
using namespace std;
using ll = long long;

struct SuffixArray {
  string S;
  int N;
  vector<int> sa, isa;

  void init(const string &s) {
    S = s;
    N = sz(S) + 1;
    genSa();
  }

  void genSa() {
    sa = isa = vector<int>(N);
    sa[0] = N - 1;
    iota(1 + all(sa), 0);
    sort(1 + all(sa), [&](int a, int b) { return S[a] < S[b]; });
    for (int i = 1; i < N; ++i) {
      int a = sa[i - 1], b = sa[i];
      isa[b] = i > 1 && S[a] == S[b] ? isa[a] : i;
    }
    for (int len = 1; len < N; len *= 2) {
      vector<int> s(sa), is(isa), pos(N);
      iota(all(pos), 0);
      for (auto &t: s) {
        int T = t - len;
        if (T >= 0)sa[pos[isa[T]]++] = T;
      }
      for (int i = 1; i < N; ++i) {
        int a = sa[i - 1], b = sa[i];
        isa[b] = is[a] == is[b] && is[a + len] == is[b + len] ? isa[a] : i;
      }
    }
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s, t;
  cin >> n >> s >> t;

  SuffixArray sa;
  sa.init(t + t + '{' + s + s);

  vector<int> s_ids;
  for (int i = 0; i < n; ++i) {
    s_ids.emplace_back(sa.isa[2 * n + 1 + i]);
  }
  sort(all(s_ids));
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += s_ids.end() - upper_bound(all(s_ids), sa.isa[i]);
  }
  cout << n * 1LL * n - res;
  return 0;
}

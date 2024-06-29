#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> row;
typedef vector<row> mat;

const int mod = 1e9 + 7;

int add(int a, int b) { return (a + b) % mod; }

int mul(int a, int b) { return a * 1LL * b % mod; }

mat operator*(const mat &a, const mat &b) {
  int r1 = a.size(), r2 = b.size(), c2 = b[0].size();
  mat ret(r1, row(c2));

  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c2; j++)
      for (int k = 0; k < r2; k++)
        ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));

  return ret;
}

mat operator^(const mat &a, ll k) {
  mat ret(a.size(), row(a.size()));
  for (int i = 0; i < a.size(); i++)ret[i][i] = 1;
  for (mat tmp = a; k; tmp = tmp * tmp, k /= 2) if (k & 1) ret = ret * tmp;
  return ret;
}

const int N = 10;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    mat trans(N, row(N)), init(N, row(1));
    init[0][0] = 1;
    for (int i = 2; i < N; i += 2) {
      trans[0][i] = 3;
    }
    for (int i = 1; i < N; ++i) {
      trans[i][i - 1] = 1;
    }
    int n;
    cin >> n;
    n /= 2;
    trans = trans ^ n;
    auto ans = trans * init;
    int res{};
    for (auto &x: ans) {
      res = add(res, x[0]);
    }
    cout << res << '\n';
  }
}

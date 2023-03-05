#include <bits/stdc++.h>

using namespace std;
const int N = 5e4 + 1;
int n;
string s;
int mem[1 << 5][N];
int vis[1 << 5][N], vs;

bool check(int l, int r, int msk) {
  while (l < r) {
    if (((msk >> l) & 1) != ((msk >> r) & 1))
      return true;
    ++l, --r;
  }
  return false;
}

int dp(int i, int m) {
  if (i == n)return 1;
  int &ret = mem[m][i];
  if (vis[m][i] == vs)return ret;
  vis[m][i] = vs;
  if (s[i] == '?') {
    m <<= 1;
    if ((i < 4 || check(0, 4, m)) && (i < 5 || check(0, 5, m))) {
      if (dp(i + 1, m & ((1 << 5) - 1)))
        return ret = 1;
    }
    m |= 1;
    if ((i < 4 || check(0, 4, m)) && (i < 5 || check(0, 5, m))) {
      m &= ((1 << 5) - 1);
      if (dp(i + 1, m))
        return ret = 1;
    }
  } else {
    m <<= 1;
    m |= (s[i] - '0');
    if ((i < 4 || check(0, 4, m)) && (i < 5 || check(0, 5, m))) {
      m &= ((1 << 5) - 1);
      if (dp(i + 1, m))
        return ret = 1;
    }
  }
  return ret = 0;
}

void solve() {
  cin >> n >> s;
  cout << (dp(0, 0) ? "POSSIBLE" : "IMPOSSIBLE");
}

int32_t main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int tc;
  cin >> tc;
  for (vs = 1; vs <= tc; ++vs) {
    cout << "Case #" << vs << ": ";
    solve();
    if (vs != tc)cout << '\n';
  }
}

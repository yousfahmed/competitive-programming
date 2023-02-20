#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e3 + 5, mod = 1e9 + 7;
int a[N], n;
int mem[N][N], vis[N][N], vs;
int mem2[N][N], vis2[N][N];

int dpMax(int i, int j) {
  if (i == n)return 0;
  int &ret = mem[i][j];
  if (vis[i][j] == vs)return ret;
  vis[i][j] = vs;
  ret = dpMax(i + 1, j);
  if (a[i] > a[j])
    ret = max(ret, 1 + dpMax(i + 1, i));
  return ret;
}

int dpCount(int i, int j) {
  if (i == n)return 1;
  int &ret = mem2[i][j];
  if (vis2[i][j] == vs)return ret;
  vis2[i][j] = vs;
  ret = 0;
  int mx = dpMax(i, j);
  int op1 = dpMax(i + 1, j), op2 = -1;
  if (a[i] > a[j])
    op2 = 1 + dpMax(i + 1, i);
  if (op1 == mx)
    ret = dpCount(i + 1, j);
  if (op2 == mx) {
    ret += dpCount(i + 1, i);
    if (ret >= mod)ret -= mod;
  }
  return ret;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ++vs;
  int ret = 0;

  for (int i = 0; i < n; ++i)
    ret = max(ret, 1 + dpMax(i + 1, i));
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (1 + dpMax(i + 1, i) == ret) {
      cnt += dpCount(i + 1, i);
      if (cnt >= mod)cnt -= mod;
    }
  cout << ret << ' ' << cnt;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
    cout << '\n';
  }

}

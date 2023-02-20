#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 5;
int par[N];
int vis[N], vs;

int findLeader(int u) {
  if (vis[u] != vs) {
    vis[u] = vs, par[u] = u;
  }
  if (u == par[u])return u;
  return par[u] = findLeader(par[u]);
}

void join(int u, int v) {
  u = findLeader(u), v = findLeader(v);
  par[u] = v;
}

void solve() {
  ++vs;
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    assert(u <= n);
    join(u, v);
  }
  int u, v;
  while (q--) {
    cin >> u >> v;
    cout << (findLeader(u) == findLeader(v));
  }


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

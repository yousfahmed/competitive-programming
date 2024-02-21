#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 2e5 + 5;
int n;
vector<int> c[N];
int ans[N], d[N], p[N];

void dfs(int u, int left) {
  if (c[u].empty())
    return;
  if (!left)
    ans[u]++, left = d[u];
  for (auto &v: c[u])
    ans[v] = ans[u], dfs(v, left - 1);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1, x; i < n; ++i) {
    cin >> x, p[i] = --x, c[x].push_back(i);
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (!c[i].size())
      q.push(i);
  }
  vector<bool> vis(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (!vis[p[u]]) {
      vis[p[u]] = true;
      d[p[u]] = d[u] + 1;
      q.push(p[u]);
    }
  }
  dfs(0, 0);
  cout << *max_element(ans, ans + N) << '\n';
}

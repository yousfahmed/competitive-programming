/*
all the edges should be in the same connected component
#directed graph: euler path: for all -> indeg = outdeg or nodes having indeg > outdeg = outdeg > indeg = 1 and for others in = out
#directed graph: euler circuit: for all -> indeg = outdeg
*/

vector<int> g[N], ans;
int done[N];

void dfs(int u) {
  while (done[u] < g[u].size()) dfs(g[u][done[u]++]);
  ans.push_back(u);
}

int solve(int n) {
  int edges = 0;
  vector<int> in(n + 1, 0), out(n + 1, 0);
  for (int u = 1; u <= n; u++) {
    for (auto v: g[u])
      in[v]++, out[u]++, edges++;
  }
  int ok = 1, cnt1 = 0, cnt2 = 0, root = 0;
  for (int i = 1; i <= n; i++) {
    if (in[i] - out[i] == 1) cnt1++;
    if (out[i] - in[i] == 1) cnt2++, root = i;
    if (abs(in[i] - out[i]) > 1) ok = 0;
  }
  if (cnt1 > 1 || cnt2 > 1) ok = 0;
  if (!ok) return 0;
  if (root == 0) {
    for (int i = 1; i <= n; i++) if (out[i]) root = i;
  }
  if (root == 0) return 1; //empty graph
  dfs(root);
  if (ans.size() != edges + 1) return 0; //connectivity
  reverse(ans.begin(), ans.end());
  return 1;
}

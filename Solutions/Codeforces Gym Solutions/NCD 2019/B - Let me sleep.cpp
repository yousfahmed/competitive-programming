
#include <bits/stdc++.h>

using namespace std;
const int N = 1e6;

vector<vector<int> > SCCs;
#define comps SCCs
vector<int> compIndex , ind, lowLink;
stack<int> st;
vector<bool> inst;
vector<vector<int> > adj;
int idx = 0;;
set<pair<int, int>> mp;

void tarjanSCC(int i) {
  lowLink[i] = ind[i] = idx++;
  st.push(i);
  inst[i] = true;
  for (int j = 0; j < adj[i].size(); j++) {
    int k = adj[i][j];
    if (mp.count({min(k, i), max(k, i)}))continue;
    mp.insert({min(k, i), max(k, i)});
    if (ind[k] == -1) {
      tarjanSCC(k);
      lowLink[i] = min(lowLink[i], lowLink[k]);
    } else if (inst[k]) {
      lowLink[i] = min(lowLink[i], lowLink[k]);
    }
  }
  if (lowLink[i] == ind[i]) {
    vector<int> comp;
    int n = -1;
    while (n != i) {
      n = st.top();
      st.pop();
      comp.push_back(n);
      inst[n] = 0;
      compIndex[n] = comps.size();
    }
    comps.push_back(comp);
  }
}

void SCC() {
  comps.clear();
  compIndex.resize(adj.size());
  ind.clear();
  ind.resize(adj.size(), -1);
  lowLink.resize(adj.size());
  inst.resize(adj.size());
  idx = 0;
  for (int i = 0; i < adj.size(); i++)
    if (ind[i] == -1)
      tarjanSCC(i);
}

int cntSrc ,cntSnk;
vector<vector<int> > cmpAdj;
vector<int> inDeg, outDeg;

void computeNewGraph() {
  outDeg.clear();
  outDeg.resize(comps.size());
  inDeg.clear();
  inDeg.resize(comps.size());
  cntSrc = cntSnk = comps.size();
  cmpAdj.clear();
  cmpAdj.resize(comps.size());
  for (int i = 0; i < adj.size(); i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      int k = adj[i][j];
      if (compIndex[k] != compIndex[i]) {
        cmpAdj[compIndex[i]].push_back(compIndex[k]);
        if (!(inDeg[compIndex[k]]++))
          cntSrc--;
        if (!(outDeg[compIndex[i]]++))
          cntSnk--;
      }
    }
  }
}


void solve() {
  mp.clear();
  int n, m;
  cin >> n >> m;
  adj = vector<vector<int>>(n);
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    adj[--u].emplace_back(--v);
    adj[v].emplace_back(u);
  }
  SCC();
  computeNewGraph();
  n = cmpAdj.size();
  queue<int> q;
  vector<char> vis(n);
  q.emplace(0);
  vis[0] = 1;
  int farthestNode = 0;
  while (q.size()) {
    int sz = q.size();
    while (sz--) {
      int u = q.front();
      q.pop();
      for (int &v: cmpAdj[u]) {
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
      if (q.empty())
        farthestNode = u;
    }
  }
  vis = vector<char>(n);
  vis[farthestNode] = 1;
  q.push(farthestNode);
  int lvl = 0;
  while (q.size()) {
    int sz = q.size();
    ++lvl;
    while (sz--) {
      int u = q.front();
      q.pop();
      for (int &v: cmpAdj[u])
        if (!vis[v])
          vis[v] = true, q.push(v);
    }
  }
  int cnt = 0;
  for (auto &u: cmpAdj) {
    cnt += u.size();
  }
  cnt /= 2;
  cout << cnt - lvl + 1 << ' ';;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    solve(), cout << '\n';
  }
}

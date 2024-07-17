// O( sqrt(n) * m )
struct HopcroftKarp {
private:
  vector<vector<int>> *g = nullptr;
  int n, m;
  vector<int> dis;

  void bfs() {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (matchL[i] == -1) {
        dis[i] = 0;
        q.push(i);
      } else {
        dis[i] = -1;
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v: (*g)[u]) {
        if (matchR[v] != -1 && dis[matchR[v]] == -1) {
          dis[matchR[v]] = dis[u] + 1;
          q.push(matchR[v]);
        }
      }
    }
  };

  bool dfs(int u) {
    for (int v: (*g)[u]) {
      if (matchR[v] == -1 || (dis[matchR[v]] == dis[u] + 1 && dfs(matchR[v]))) {
        matchL[u] = v;
        matchR[v] = u;
        return true;
      }
    }
    // dis[u] = -1;
    return false;
  };

public:
  vector<int> matchL, matchR;

  void SetGraph(int numleft, int numright, vector<vector<int>> *graph) {
    n = numleft;
    m = numright;
    g = graph;
    assert(g != nullptr && g->size() == n);

    matchL.resize(n);
    matchR.resize(m);
    dis.resize(n);
  }

  int max_match() {
    assert(g != nullptr);
    fill(matchL.begin(), matchL.end(), -1);
    fill(matchR.begin(), matchR.end(), -1);

    int ans = 0;
    while (true) {
      bfs();
      int add = 0;
      for (int i = 0; i < n; ++i) {
        if (matchL[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0)
        break;
      ans += add;
    }
    return ans;
  }
};

int main() {
  int n, m, e;
  cin >> n >> m >> e;
  vector<vector<int>> g(n);
  for (int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  HopcroftKarp hk;
  hk.SetGraph(n, m, &g);
  cout << hk.max_match() << '\n';
  for (int i = 0; i < n; ++i) {
    if (hk.matchL[i] != -1) {
      cout << i << ' ' << hk.matchL[i] << '\n';
    }
  }
  return 0;
}

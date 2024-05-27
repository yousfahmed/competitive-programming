#define ll long long
#define ED g[from[it]][from_edge[it]]

struct Edge {
  int to;
  int cost;
  int cap, flow, backEdge;
};

struct MCMF {

  static const int inf = 1e9;
  int n;
  vector<vector<Edge>> g;

  MCMF(int n) : n(n), g(n) {}

  void addEdge(int u, int v, int cost, int cap, int rev_cap = 0) {
    Edge e1 = {v, cost, cap, 0, (int) g[v].size()};
    Edge e2 = {u, -cost, rev_cap, 0, (int) g[u].size()};
    g[u].push_back(e1);
    g[v].push_back(e2);
  }

  pair<ll, int> minCostMaxFlow(int s, int t, int k) {
    int flow = 0;
    ll cost = 0;
    vector<int> state(n), from(n), from_edge(n);
    vector<ll> d(n);
    deque<int> q;
    while (flow < k) {
      for (int i = 0; i < n; i++)
        state[i] = 2, d[i] = inf, from[i] = -1;
      state[s] = 1;
      q.clear();
      q.push_back(s);
      d[s] = 0;
      while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        state[v] = 0;
        for (int i = 0; i < (int) g[v].size(); i++) {
          Edge e = g[v][i];
          if (e.cap <= e.flow or d[e.to] <= d[v] + e.cost)
            continue;
          int to = e.to;
          d[to] = d[v] + e.cost;
          from[to] = v;
          from_edge[to] = i;
          if (state[to] == 1) continue;
          state[to] = 1;
          if (!state[to] or (!q.empty() and d[q.front()] > d[to])) {
            q.push_front(to);
          } else {
            q.push_back(to);
          }
        }
      }
      if (d[t] == inf) break;
      int it = t;
      int addflow = k - flow;
      while (it != s) {
        addflow = min(
            addflow,
            ED.cap - ED.flow
        );
        it = from[it];
      }
      it = t;
      while (it != s) {
        ED.flow += addflow;
        g[it][ED.backEdge].flow -= addflow;
        cost += ED.cost * addflow;
        it = from[it];
      }
      flow += addflow;
    }
    return {cost, flow};
  }
};

struct edge {
  int s, e, c; //start, end, cost
  bool operator<(const edge &e) const { return c < e.c; }
};

const int SIZE = 100; //max nodes number
int N, start, sink, K; //find the k-th shortest path from start to end
int adj[SIZE][SIZE]; //this can be adjList instead of adjMatrix

//Returns -1 of no k-th shortest path exist between start and end
int getKthShortestPath() {
  multiset<edge> pq; //first is cost and second is node
  edge e = {-1, start, 0};
  pq.insert(e);
  vector<int> reached[N];
  //reached[i][j] is the cost of the j-th shortest path from start to i
  while (!pq.empty()) {
    edge e = *pq.begin();
    pq.erase(pq.begin());
    if (reached[e.e].size() >= K)continue;
    reached[e.e].push_back(e.c);
    for (int i = 0; i < N; i++) {
      if (adj[e.e][i] == -1)continue;
      edge ne = {e.e, i, e.c + adj[e.e][i]};
      pq.insert(ne);
    }
  }
  // no k-th path exist between start and end
  return reached[sink].size() >= K ? reached[sink].back() : -1;
}

void solve() {
  /// set N, start, end, K, dist
  /// Initialize adjacency matrix with -1 (not adjacent)
  memset(adj, -1, sizeof adj); 
  
  int d = getKthShortestPath();
}

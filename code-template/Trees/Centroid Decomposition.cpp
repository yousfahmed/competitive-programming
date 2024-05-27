#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<vector<int>> adj;
vector<int> sz;
// min_dist[v] := the minimal distance between v and a red node
vector<int> min_dist;
vector<bool> is_removed;
vector<vector<pair<int, int>>> ancestors;

int get_subtree_size(int u, int p = -1) {
  sz[u] = 1;
  for (int v: adj[u]) {
    if (v == p || is_removed[v]) continue;
    sz[u] += get_subtree_size(v, u);
  }
  return sz[u];
}

int get_centroid(int u, int tree_size, int p = -1) {
  for (int v: adj[u]) {
    if (v == p || is_removed[v]) continue;
    if (sz[v] * 2 > tree_size) {
      return get_centroid(v, tree_size, u);
    }
  }
  return u;
}

/**
 * Calculate the distance between current `node` and the `centroid` it belongs
 * to. The distances between a node and all its centroid ancestors are stored
 * in the vector `ancestors`.
 * @param cur_dist the distance between `node` and `centroid`
 */
void get_dists(int u, int centroid, int p = -1, int d = 1) {
  for (int v: adj[u]) {
    if (v == p || is_removed[v]) continue;
    get_dists(v, centroid, u, d + 1);
  }
  ancestors[u].emplace_back(centroid, d);
}

void build_centroid_decomp(int u = 0) {
  int centroid = get_centroid(u, get_subtree_size(u));
  /* For all nodes in the subtree rooted at `centroid`, calculate their
   * distances to the centroid */
  for (int v: adj[centroid]) {
    if (is_removed[v]) { continue; }
    get_dists(v, centroid, centroid);
  }
  is_removed[centroid] = true;
  for (int v: adj[centroid]) {
    if (is_removed[v]) { continue; }
    // build the centroid decomposition for all v components
    build_centroid_decomp(v);
  }
}

/**
 * Paint `node` red by updating all of its ancestors' minimal distances
 * to a red node
 */
void paint(int u) {
  for (auto &[v, dist]: ancestors[u]) {
    min_dist[v] = min(min_dist[v], dist);
  }
  min_dist[u] = 0;
}

/** Print the minimal distance between `node` to a red node */
void query(int u) {
  int ans = min_dist[u];
  for (auto &[v, dist]: ancestors[u]) {
    if (!dist) continue;
    /* The distance between `node` and a red painted node is the sum of
     * the distance from `node` to one of its ancestors (`dist`) and the
     * distance from this ancestor to the nearest red node
     * (`min_dist[ancestor]`). */
    ans = min(ans, dist + min_dist[v]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  adj.assign(N, vector<int>());
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  sz.assign(N, 0);
  ancestors.assign(N, {});
  is_removed.assign(N, false);
  build_centroid_decomp();
  min_dist.assign(N, INF);
  paint(0);
  for (int i = 0; i < M; i++) {
    int t, v;
    cin >> t >> v;
    v--;
    if (t == 1) {
      paint(v);
    } else {
      query(v);
    }
  }
}
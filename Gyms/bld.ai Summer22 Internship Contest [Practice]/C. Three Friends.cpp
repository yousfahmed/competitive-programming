/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int inf = 1e18, N = 1e5 + 7;

int dijkstra(int s, int e, vector<vector<pair<int, int>>> &adj, int dist[]) {
    fill(dist, dist + adj.size(), inf);
    dist[s] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, s));
    while (q.size()) {
        int cur = q.top().second;
        int d = -q.top().first;
        q.pop();
        if (d != dist[cur])
            continue;
        if (cur == e)
            return d;
        for (int i = 0; i < adj[cur].size(); ++i) {
            int j = adj[cur][i].first;
            int dd = d + adj[cur][i].second;
            if (dist[j] > dd) {
                dist[j] = dd;
                q.push(make_pair(-dd, j));
            }
        }
    }
    return inf;
}


vector<vector<pair<int, int>>> goAhead, goBack;
int back[3][N], go[3][N];

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, u, v, c;
    cin >> n >> m;
    goAhead.resize(n + 7);
    goBack.resize(n + 7);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        goAhead[u].emplace_back(v, c);
        goBack[v].emplace_back(u, c);
    }
    vector<int> arr(3);
    for (int &i: arr) cin >> i;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 3; ++i) /// from X to all Nodes
        dijkstra(arr[i], n + 1, goAhead, go[i]);
    for (int i = 0; i < 3; ++i) /// from all nodes to arr[i]
        dijkstra(arr[i], n + 1, goBack, back[i]);
    int ret = inf, idx = inf;
    for (int meetMe = 1; meetMe <= n; ++meetMe) {
        for (int home = 0; home < 3; ++home) {
            int sum = 0;
            for (int fr = 0; fr < 3; ++fr)
                if (home != fr) sum += go[fr][meetMe];
            sum += back[home][meetMe];
            if (sum < ret) ret = sum, idx = arr[home];
            else if (sum == ret) idx = min(idx, arr[home]);
        }
    }

    if (ret >= inf) cout << -1;
    else cout << idx << ' ' << ret;


}

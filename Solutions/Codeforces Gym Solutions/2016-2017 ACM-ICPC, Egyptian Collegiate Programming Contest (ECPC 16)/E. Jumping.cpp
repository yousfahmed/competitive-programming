/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101147/problem/E
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long


void solve() {
    int n;
    cin >> n;
    int arr[n + 1];
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if (i - arr[i] > 0)
            adj[i - arr[i]].emplace_back(i);
        if (arr[i] + i <= n)
            adj[i + arr[i]].emplace_back(i);
    }

    int dist[n + 1];
    priority_queue<pair<int, int>> pq;
    memset(dist, 63, sizeof dist);
    const int inf = dist[0];
    dist[n] = 0;
    pq.emplace(0, n);
    while (pq.size()) {
        int u, d;
        tie(d, u) = pq.top();
        d *= -1;
        pq.pop();
        if (dist[u] != d)continue;
        for (int &v: adj[u]) {
            int dd = d + 1;
            if (dist[v] > dd) {
                dist[v] = dd;
                pq.emplace(-dd, v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == inf) {
            cout << "-1\n";
        } else {
            cout << dist[i] << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("jumping.in", "r", stdin);
#endif
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
}

/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/C
*/
#include <bits/stdc++.h>

using namespace std;
#define all(X) X.begin(),X.end()
#define ll long long
#define int ll
const int MAX = 1e4 + 7;
bool f[26][MAX];


#define infinity (long long)1e18
vector<vector<pair<int, long long> > > adj;
long long dist[MAX];

long long dijkstra(int s, int e) {
    fill(dist, dist + adj.size(), infinity);
    dist[s] = 0;
    priority_queue<pair<long long, int> > q;
    q.push(make_pair(0, s));
    while (q.size()) {
        int cur = q.top().second;
        long long d = -q.top().first;
        q.pop();
        if (d != dist[cur])
            continue;
        if (cur == e)
            return d;
        for (int i = 0; i < adj[cur].size(); ++i) {
            int j = adj[cur][i].first;
            long long dd = d + adj[cur][i].second;
            if (dist[j] > dd) {
                dist[j] = dd;
                q.push(make_pair(-dd, j));
            }
        }
    }
    return infinity;
}


int prolog(int u, int v) {
    int ret = 0;
    for (auto &i: f)
        if (i[u] and i[v])
            ++ret;

    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (char &j: s) {
            j = tolower(j);
            f[j - 'a'][i] = true;
        }
    }
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        int c = prolog(u, v);
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    int u, v;
    cin >> u >> v;
    cout << dijkstra(--u, --v);


}

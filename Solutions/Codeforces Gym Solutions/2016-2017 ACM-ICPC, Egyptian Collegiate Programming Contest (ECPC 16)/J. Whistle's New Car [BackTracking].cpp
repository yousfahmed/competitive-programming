/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101147/problem/J
*/
#include <bits/stdc++.h>

using namespace std;
const int N = 500000 + 7;
#define int long long
int arr[N];
vector<vector<pair<int, int>>> adj;
vector<int> ans, path, ret;

void DFS(int u, int p, int w) {
    if (ans.size()) {
        ans.back()++;
        int f = lower_bound(path.begin(), path.end(), w - arr[u]) - path.begin();
        if (f)ans[f - 1]--;
    }
    ans.push_back(0);
    path.emplace_back(w);
    for (auto &v: adj[u])
        if (v.first != p)
            DFS(v.first, u, w + v.second);
    path.pop_back();
    ret[u] = ans.back();
    if (ans.size() > 1)
        ans[ans.size() - 2] += ans.back();
    ans.pop_back();
}

void solve() {
    int n;
    cin >> n;
    adj = vector<vector<pair<int, int>>>(n);
    ret = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1, u, v, c; i < n; ++i) {
        cin >> u >> v >> c;
        adj[--u].emplace_back(--v, c);
        adj[v].emplace_back(u, c);
    }
    DFS(0, 0, 0);
    for (int i = 0; i < n; ++i)
        cout << ret[i] << " \n"[i + 1 == n];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("car.in", "r", stdin);
#endif
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
}

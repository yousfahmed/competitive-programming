/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To Gym : https://codeforces.com/gym/101653
*/

#include<bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define double long double
struct coordinate {
    int x, y, z;
};

double distance(const coordinate &x, const coordinate &y) {
    return sqrt(
            (x.x - y.x) * (x.x - y.x) +
            (x.y - y.y) * (x.y - y.y) +
            (x.z - y.z) * (x.z - y.z)
    );
}

const double inf = 1e18;

void solve() {
    map<string, int> mp;
    int n;
    cin >> n;
    vector<coordinate> arr(n);
    vector<vector<double>> adj(n, vector<double>(n, inf));
    string s, e;
    for (int i = 0; i < n; ++i) {
        cin >> s >> arr[i].x >> arr[i].y >> arr[i].z;
        mp[s] = i;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = distance(arr[i], arr[j]);
    int w;
    cin >> w;
    while (w--) {
        cin >> s >> e;
        adj[mp[s]][mp[e]] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = min(
                        adj[i][j],
                        adj[i][k] + adj[k][j]
                );
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        cin >> s >> e;
        cout << "The distance from " << s << " to " << e << " is ";
        cout << (int) (llround(adj[mp[s]][mp[e]]));
        cout << " parsecs.\n";
    }

}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case " << i << ":\n";
        solve();
    }
}

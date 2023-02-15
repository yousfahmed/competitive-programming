/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To Gym : https://codeforces.com/gym/101653
*/

#include<bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
const int mod = 1e9 + 7, N = 2e5 + 7;


void solve() {
    vector<int> ret;
    int n;  cin >> n;
    string a[n], b[n];
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    int i = 0;
    while (i < n) {
        map<string, int> x, y;
        int sz = 1;
        x[a[i]]++;
        y[b[i]]++;
        i++;
        while (x != y) {
            assert(i < n);
            x[a[i]]++;
            y[b[i]]++;
            ++sz, ++i;
        }
        ret.emplace_back(sz);
    }
    cout << ret.front();
    for (i = 1; i < ret.size(); ++i) cout << ' ' << ret[i];
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
    double x;
    while (T--) {
        solve();
        if (T) cout << '\n';
    }
}

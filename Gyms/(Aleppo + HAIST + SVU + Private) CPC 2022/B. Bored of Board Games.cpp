/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/103821/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(),x.end()
int n, m;
int arr[207][207];

pair<int, int> minRow() {
    pair<int, int> ret = {1e9, 1e9};
    for (int i = 1; i <= n; ++i) {
        int sum = accumulate(arr[i], arr[i] + m + 1, 0LL);
        if (ret.first > sum)
            ret = {sum, i};
    }
    return ret;
}

pair<int, int> minColumn() {
    pair<int, int> ret = {1e9, 1e9};
    int sum = 0;
    for (int j = 1; j <= m; ++j, sum = 0) {
        for (int i = 1; i <= n; ++i) sum += arr[i][j];
        if (ret.first > sum)
            ret = {sum, j};
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> arr[i][j];
    pair<int, int> r = minRow(), c = minColumn();
    map<int, int> R, C;
    while (r.first < 0 or c.first < 0) {
        if (r.first < c.first) {
            R[r.second]++;
            for (int i = 1; i <= m; ++i) arr[r.second][i] *= -1;
        } else {
            C[c.second]++;
            for (int i = 1; i <= n; ++i) arr[i][c.second] *= -1;
        }
        r = minRow(), c = minColumn();
    }
    cout << "Yes\n";
    auto cmp = [](const pair<int, int> x) {
        return x.second & 1;
    };
    cout << count_if(all(R), cmp) << '\n';
    for (auto &i: R) { if (i.second & 1)cout << i.first << ' '; }
    cout << '\n' << count_if(all(C), cmp) << '\n';
    for (auto &i: C) { if (i.second & 1)cout << i.first << ' '; }
    cout << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();

}

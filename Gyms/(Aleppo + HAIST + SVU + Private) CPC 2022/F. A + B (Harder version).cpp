/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/103821/problem/F
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    int ret = 0, x;
    for (int i = 0; i < 7; ++i) {
        cin >> x;
        ret += x;
    }
    cout << ret << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
}

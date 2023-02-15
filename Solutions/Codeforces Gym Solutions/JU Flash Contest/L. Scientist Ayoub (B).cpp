/*
  Link : https://codeforces.com/gym/102035/problem/L
  Author : Abdelaleleem
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int mx = 2e8, n;
    cin >> n;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            cout << cnt++ << ' ';
        } else {
            cout << mx << ' ';
            assert(mx <= 1e9);
            mx += (cnt + cnt);
        }
    }

}

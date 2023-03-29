/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("ziko.in", "r", stdin);
    int TC;
    TC = 1;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        cout << ((n - 1) | n) << '\n';
    }
    return 0;
}

/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/103821/problem/C
*/


#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC = 1;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int mx = 0;
        bool yes = true;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            yes &= (x > mx);
            mx = max(x, mx);
        }
        cout << (yes ? "Yes\n" : "No\n");
    }
}

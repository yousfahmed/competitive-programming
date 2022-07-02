/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/I
*/
#include <bits/stdc++.h>

using namespace std;
signed main() {
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n;
    int ret[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            if (i == j) ret[i] = sqrt(x);
        }
    }
    for (int &i: ret) cout << i << ' ';
}

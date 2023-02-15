/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101147/problem/D
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long

int nCr(int n, int r) {
    if (n == r)return 1;
    return nCr(n - 1, r) * n / (n - r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("popcorn.in", "r", stdin);
#endif
    int TC;
    cin >> TC;
    int n, r;
    while (TC--) {
        cin >> n >> r;
        cout << nCr(n, r) << '\n';
    }
}

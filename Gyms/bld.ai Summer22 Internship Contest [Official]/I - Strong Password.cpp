/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e5 + 7, mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    while (i < n or j < m) {
        if (i < n)cout << a[i++];
        if (j < m)cout << b[j++];
    }
}

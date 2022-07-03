/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101755/problem/A
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
    int s, g;
    cin >> s >> g;
    int a = s - g;
    if (a % g or !a) return cout << -1, 0;
    cout << a << ' ' << g;
}

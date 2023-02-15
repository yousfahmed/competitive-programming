/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101755/problem/E
*/
#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s, t;
    cin >> s >> t;
    int n = s.length();
    if (s.length() != t.length()) return cout << "NO", 0;
    if (s == t) return cout << "YES", 0;
    int i = 0, j = n - 1;
    for (int k = 0; k < n; ++k) {
        if (s[i] == t[i]) i++;
        if (t[j] == s[j]) --j;
    }
    assert(i <= j);
    reverse(s.begin() + i, s.begin() + j + 1);
    cout << (s == t ? "YES" : "NO");
}

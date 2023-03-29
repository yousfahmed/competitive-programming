/*
   Author : Abdelaleem Ahmed 
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("adam.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length(), ret = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'D') {
                ret = i;
                break;
            }
        }
        cout << ret << '\n';
    }
}


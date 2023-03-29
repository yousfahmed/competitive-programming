/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("rev.in", "r", stdin);
    int TC = 1;
    cin >> TC;
    while (TC--) {
        int n, m, i = 0, flag = 0;
        string s, t;
        cin >> n >> m >> t >> s;
        if (n > m) {
            cout << "NO\n";
            continue;
        }
        while (m > n) {
            flag = !flag;
            if (flag)i++;
            m--;
        }
        string temp = s.substr(i, n);
        if (flag) reverse(temp.begin(), temp.end());
        cout << (temp == t ? "YES\n" : "NO\n");
    }
}

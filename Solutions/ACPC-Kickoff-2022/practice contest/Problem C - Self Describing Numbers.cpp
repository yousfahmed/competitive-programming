/*
   Author : Abdelaleem Ahmed
   Handle Codeforces : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("self.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string s, ret = "self-describing\n";
        int freq[10] = {0};
        cin >> s;
        for (char &i: s) ++freq[i - '0'];
        for (int i = 0, len = s.length(); i < len; ++i) {
            if (s[i] - '0' != freq[i]) {
                ret = "not self-describing\n";
                break;
            }
        }
        cout << ret;
    }
}


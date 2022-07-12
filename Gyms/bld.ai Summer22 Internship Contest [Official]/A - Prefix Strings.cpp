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
    int n, q;
    cin >> n >> q;
    map<string, int> mp;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        while (s.size()) {
            mp[s]++;
            s.pop_back();
        }
    }
    while (q--) {
        cin >> s;
        cout << mp[s] << '\n';
    }

}

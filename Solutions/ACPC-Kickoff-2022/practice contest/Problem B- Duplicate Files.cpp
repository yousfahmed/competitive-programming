/*
   Author : Abdelaleem Ahmed
   Handle Codeforces : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("files.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> mp; // FileName -> id
        set<int> ret;
        int id; string s;
        while (n--) {
            cin >> s >> id;
            if (mp.count(s) == 0 or mp[s] > id) {
                ret.erase(mp[s]);
                ret.insert(id);
                mp[s] = id;
            }
        }
        for (const int &i: ret)
            cout << i << ' ';
        cout << '\n';
    }
}


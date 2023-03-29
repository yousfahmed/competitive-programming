/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;

int to_seconds(string &s, string &t) {
    int ret = stoi(s.substr(0, 2)) * 60 * 60 +
              stoi(s.substr(3, 2)) * 60 +
              stoi(s.substr(6));
    if (t == "PM") ret += 12 * 60 * 60;
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("schedule.in", "r", stdin);
    int TC = 1;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        string s, t;
        for (int i = 0, x; i < n; ++i) {
            cin >> x >> s >> t;
            arr[i] = {to_seconds(s, t), x};
        }
        sort(arr.begin(), arr.end());
        for (auto &i: arr)
            cout << i.second << ' ';
        cout << '\n';
    }
}

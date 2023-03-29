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
    freopen("good.in", "r", stdin);
    int TC = 1;
    cin >> TC;
    while (TC--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<vector<int>> freq(k, vector<int>(26));
        for (int i = 0; i < n; ++i)
            freq[i % k][s[i] - 'a']++;
        int ret = 0;
        for (auto &i: freq)
            ret += accumulate(i.begin(), i.end(), 0)
                   - *max_element(i.begin(), i.end());
        cout << ret << '\n';
    }
}

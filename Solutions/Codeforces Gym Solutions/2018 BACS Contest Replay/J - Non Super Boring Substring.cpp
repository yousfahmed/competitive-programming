/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101864/problem/j
*/


#include <bits/stdc++.h>

using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define int long long

vector<int> mancherAlg(const string &s) {
    string t = "#";
    for (auto &ch: s)t.push_back(ch), t.push_back('#');
    int n = t.size();
    vector<int> ans(n);
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * C - i;
        int rad = (i < R) ? min(ans[mirror], R - i) : 0;
        while (i + 1 + rad < n && i + 1 + rad > -1 && t[i + 1 + rad] == t[i - rad - 1])
            rad++;
        ans[i] = rad;
        if (i + ans[i] > R) {
            C = i;
            R = i + ans[i];
        }
    }
    return ans;
}


void solve() {
    string s;
    int k;
    cin >> k;
    cin >> s;
    auto ans = mancherAlg(s);
    int idx = 0;
    int n = ans.size(), m = s.length();
    int ret = m * (m + 1) / 2;
    int prev = 0;
    for (int i = 1; i < n; ++i) {
        if (ans[i] >= k) {
            if (i & 1) {
                int x = min(ans[i], k + !(k & 1));
                x = (x - 1) >> 1;
                int l = idx - x;
                int r = idx + x;
                ret -= (l - prev + 1) * (m - r);
                prev = l + 1;
            } else {
                int x = min(ans[i], k + (k & 1));
                x >>= 1;
                int l = idx - x;
                int r = idx + x - 1;
                ret -= (l - prev + 1) * (m - r);
                prev = l + 1;
            }
        }
        if (i & 1)idx++;
    }
    cout << ret;
}

signed main() {
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
        if (i != t)cout << '\n';
    }

}


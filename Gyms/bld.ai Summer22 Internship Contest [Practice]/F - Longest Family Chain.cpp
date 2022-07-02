/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;
#define sz(n) ((int)((n).size()))
#define int long long

const int N = 1e5;
int n;
map<string, vector<int>> mp;
vector<string> str;
int dp[N];

void getAdj(string &s, int j) {
    for (int i = 0; i < sz(s); i++) {
        string tmp = s;
        tmp.erase(i, 1);
        mp[tmp].emplace_back(j);
    }
}

int solve(int idx) {
    int &ret = dp[idx];
    if (~ret) return ret;
    ret = 0;
    for (auto it: mp[str[idx]])
        ret = max(ret, solve(it));
    return ++ret;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    cin >> n;
    str = vector<string>(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        getAdj(str[i], i);
    }
    int ans = 1;
    for (int i = 0; i < n; i++) ans = max(solve(i), ans);
    cout << ans;
}

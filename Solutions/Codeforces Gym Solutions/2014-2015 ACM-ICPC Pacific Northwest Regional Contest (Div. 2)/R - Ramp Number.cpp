#include<bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
const int mod = 1e9 + 7, N = 2e5 + 7;
#define int long long
int n;
int mem[2][2][10][81];
vector<int> digits;

int dp(int i = 0, int ls = 0, bool st = 0, bool sm = 0) {
    if (i == n)return st;
    int &ret = mem[sm][st][ls][i];
    if (~ret)return ret;
    ret = 0;
    int mx = sm ? 9 : digits[i];
    for (int d = ls; d <= mx; ++d)
        ret += dp(i + 1, d, st or d, sm or d < digits[i]);

    return ret;
}

void init() {
    memset(mem, -1, sizeof mem);
    digits.clear();
}

int solve() {
    init();
    string s;
    cin >> s;
    n = s.length();
    while (s.size()) {
        digits.emplace_back(s.back() - '0');
        s.pop_back();
    }
    reverse(all(digits));
    for (int i = 1; i < n; ++i)
        if (digits[i] < digits[i - 1])return -1;
    return dp();
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
        cout << solve() << '\n';

}

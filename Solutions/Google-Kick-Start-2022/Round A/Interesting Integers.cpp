#include <bits/stdc++.h>

using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
int num[15], sz = 0, v, mod;
ll mem[13][120][120][2][2];
ll vis[13][120][120][2][2];

ll dp(int idx, int remSum, int m, bool s = false, bool st = false) {
    if (remSum < 0) return 0;
    if (idx == sz) return (remSum == 0 and m == 0);
    int mx = s ? 9 : num[idx];
    ll &ans = mem[idx][remSum][m][s][st];
    if (vis[idx][remSum][m][s][st] == v) return ans;
    vis[idx][remSum][m][s][st] = v;
    ans = 0;
    for (int d = 0; d <= mx; ++d) {
        int M = d % mod;
        if (st) M = (d * m) % mod;
        ans += dp(idx + 1, remSum - d, M, s or d < num[idx], d or st);
    }
    return ans;
}

ll solve(ll x) {
    if (x == 0) return 0;
    sz = log10(x) + 1;
    for (int i = sz - 1; i >= 0; --i) {
        num[i] = x % 10;
        x /= 10;
    }
    ll ans = 0;
    for (mod = 1, v++; mod <= 9 * sz; mod++, v++)
        ans += dp(0, mod, 0);

    return ans;
}

int main() {
    NeedForSpeed;
    int t = 1;
    cin >> t;
    ll l, r;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";

        cin >> l >> r;
        cout << solve(r) - solve(l - 1);

        if (t) cout << "\n";
    }
}

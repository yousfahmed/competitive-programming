/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long

double solve(int n, int m, int x, int y) {
    auto ok = [&](int idx) {
        int s = 0, e = 1e18, ans = 0;
        while (s <= e) {
            int mid = (e - s) / 2 + s;
            if (min(mid / x, n) + min(mid / y, m) >= idx) ans = mid, e = mid - 1;
            else if (min(mid / x, n) + min(mid / y, m) <= idx) s = mid + 1;
        }
        return ans;
    };
    int idx = (n + m) / 2 + 1;
    if ((n + m) & 1) return ok(idx);
    return (1.0 * ok(idx) + ok(idx - 1)) / 2.0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, x, y;
    cin >> n >> x >> m >> y;
    cout << fixed << setprecision(1) << solve(n, m, x, y);
}

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


const double PI = acos(-1);
#define ll long long
#define double long double
#define int ll

void solve() {
    int r, a, b;
    cin >> r >> a >> b;
    double res = 0;
    bool x = false;
    while (r > 0) {
        res += PI * r * r;
        (x ? r /= b : r *= a);
        x = !x;
    }
    cout << fixed << setprecision(6) << res;

}

signed main() {
    NeedForSpeed;
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        if (t) cout << '\n';
    }
    return 0;
}

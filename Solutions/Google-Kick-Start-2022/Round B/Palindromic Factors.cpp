#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


#define ll long long
#define int ll

void solve() {
    int a;
    cin >> a;
    int sz = 0;

    auto check = [&](int x) -> bool {
        string s = to_string(x);
        string l = s;
        reverse(s.begin(), s.end());
        return l == s;
    };

    for (int i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            sz += check(i);
            sz += i * i != a and check(a / i);
        }
    }
    cout << sz;
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

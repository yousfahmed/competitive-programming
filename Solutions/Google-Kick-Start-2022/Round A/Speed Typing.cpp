#include <bits/stdc++.h>

using namespace std;

#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

void solve() {
    string a, b;
    cin >> a >> b;
    int r = 0, cnt = 0;
    int n = a.length(), m = b.length();
    for (int i = 0; i < n; ++i) {
        while (r < m and b[r] != a[i])
            r++, cnt++;
        if (r == m) {
            cout << "IMPOSSIBLE";
            return;
        }
        r++;
    }
    cout << cnt + (m - r);
}

int main() {
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

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define int ll
int num[5004];

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int s1 = x + y;
    int s2 = n * (n + 1) / 2;
    if (s2 % s1 == 0) {
        cout << "POSSIBLE\n";
        set<int> st(num, num + n);
        vector<int> ans;
        ll x1 = s2 / s1 * x;
        while (x1 > 0) {
            auto l = st.upper_bound(x1);
            assert(st.begin() != l);
            l--;
            x1 -= *l;
            ans.emplace_back(*l);
            st.erase(l);
        }
        cout << ans.size() << '\n';
        for (int &i: ans)
            cout << i << ' ';
    } else {
        cout << "IMPOSSIBLE";
    }

}

signed main() {
    NeedForSpeed;
    iota(num, num + 5007, 1);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        if (t) cout << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("sort.in", "r", stdin);
    int TC;
    TC = 1;
    cin >> TC;
    while (TC--) {
        int n, x = (1 << 30) - 1;
        cin >> n;
        vector<int> v(n);
        for (int &i: v)
            cin >> i;

        for (int i = 29; ~i; --i) {
            x &= ~(1 << i);
            bool good = true;
            for (int j = 1; j < n; ++j)
                good &= (v[j] | x) >= (v[j - 1] | x);
            if (!good)
                x |= 1 << i;
        }
        cout << x << "\n";
    }
    return 0;
}

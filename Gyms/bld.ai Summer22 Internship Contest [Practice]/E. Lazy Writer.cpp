/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, h;
    cin >> n >> h;
    int arr[n];
    for (int &i: arr) cin >> i;
    auto okay = [&](int x) {
        int ret = 0;
        for (int &i: arr)
            ret += ((i + x - 1) / x);
        return ret <= h;
    };
    int s = 1, e = 1e18, m, ans;
    while (s <= e) {
        m = (e - s) / 2 + s;
        if (okay(m)) ans = m, e = m - 1;
        else s = m + 1;
    }
    cout << ans;
}

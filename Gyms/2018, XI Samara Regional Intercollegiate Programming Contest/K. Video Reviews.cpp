/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101755/problem/K
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int &i: arr) cin >> i;

    auto okay = [&](int x) -> bool {
        int ret = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= cnt) ++cnt;
            else if (x) cnt++, --x;
        }
        return cnt >= k;
    };

    int s = 0, e = k, m, ans = 0;
    while (s <= e) {
        m = (e - s) / 2 + s;
        if (okay(m)) ans = m, e = m - 1;
        else s = m + 1;
    }

    cout << ans;


}

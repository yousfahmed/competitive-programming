/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link : https://codeforces.com/gym/100801
*/
#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("output.out", "w", stdout);
#else
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
#endif
    double h, w;
    cin >> h >> w;
    double ret = max({
                             min(h, (w / 3.0)),
                             min((h / 3), w),
                             min(h / 2, w / 2)

                     }
    );
    cout << fixed << setprecision(4) << ret;
}


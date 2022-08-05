/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101810/problem/I
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> x >> n;
        if (n > x) {
            cout << -1 << '\n';
            continue;
        }
        int rem = (x % n);
        int num = x / n;
        vector<int> ret;
        while (x > 0) {
            ret.emplace_back(num + !!(rem));
            x -= num + !!(rem);
            if (rem)rem--;
            assert(x >= 0);
        }
        sort(all(ret));
        for (int i = 0; i < ret.size(); ++i) {
            cout << ret[i] << " \n"[i + 1 == ret.size()];
        }
    }
}


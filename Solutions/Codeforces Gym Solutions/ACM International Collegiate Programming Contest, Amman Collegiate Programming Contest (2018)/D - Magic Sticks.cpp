/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101810/problem/D
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int fun(int n, int m) {
    int r1 = m / 2;
    int r2 = m - r1;
    int c1 = (n + 1) / 2;
    int c2 = (n + 2) / 2;
    return min(
            r1 * c1 + r2 * c2,
            r1 * c2 + r2 * c1
    );
}

int solve() {
    int n, m;
    cin >> n >> m;
    return min(fun(n, m), fun(m, n));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';

}


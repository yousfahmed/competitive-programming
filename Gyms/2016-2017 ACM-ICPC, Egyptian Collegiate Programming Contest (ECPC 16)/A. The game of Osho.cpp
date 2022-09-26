/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101147/problem/A
*/

#include <bits/stdc++.h>

using namespace std;

int who_win(int n, int k) {
    if (k & 1)return n & 1;
    if ((n + 1) % (k + 1) == 0)return 2;
    if ((n - (((n + 1) / (k + 1)))) & 1)return 1;
    return 0;
}

void do_work() {
    int g;
    cin >> g;
    int n, k, ans = 0;
    for (int i = 0; i < g; ++i) {
        cin >> k >> n;
        ans ^= who_win(n, k);
    }
    if (ans) cout << 1;
    else cout << 2;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("powers.in", "r", stdin);
#endif
    int TC;
    cin >> TC;
    while (TC--) {
        do_work();
        cout << '\n';
    }
}

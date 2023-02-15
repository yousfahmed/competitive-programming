/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/103821/problem/E
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long

void solve() {
    int n;
    cin >> n;
    if (n == 1)return void(cout << "0\n");
    int r = (n >> 1);
    int ret = r * (r + 1);
    int l = n - r - 1;
    ret += l * (l + 1);
    cout << ret - max(l, r) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC = 1;
    cin >> TC;
    while (TC--)
        solve();

}

/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101810/problem/E
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
const int mod = 1e9 + 7;

int mul(int x, int y) {
    return (x * y) % mod;
}

int add(int x, int y) {
    x += y;
    while (x >= mod)x -= mod;
    while (x < 0)x += mod;
    return x;
}

void solve() {
    int n;
    cin >> n;
    ++n;
    int arr[n], pre[n], suf[n + 1];
    pre[0] = suf[n] = 1;
    for (int i = 1; i < n; ++i) {
        cin >> arr[i];
        pre[i] = mul(pre[i - 1], arr[i]);
        suf[i] = arr[i];
    }
    for (int i = n - 2; i; --i)
        suf[i] = mul(suf[i + 1], suf[i]);
    int ret = 0;
    for (int i = 1; i < n; ++i) {
        ret = add(
                ret,
                mul(
                        arr[i] - 1,
                        mul(
                                pre[i - 1],
                                suf[i + 1]
                        )
                )
        );
    }
    cout << ret << '\n';
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
        solve();

}
 

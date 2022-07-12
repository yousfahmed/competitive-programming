/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 20, mod = 1e9 + 7;

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
    for (int &i: arr)cin >> i;
    int mx = arr[0];
    for (int i = 0, len = min(n, k - 1); i < len; i++)
        mx = max(mx, arr[i]);
    cout << mx << "\n";

}

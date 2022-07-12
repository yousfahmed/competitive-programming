/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e5 + 7, mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int arr[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    map<int, int> mp;
    mp[0] = 0;
    int s = 0, ret = 0;
    for (int i = 1; i <= n; ++i) {
        s = (s + arr[i]) % k;
        if (mp.count(s)) ret = max(ret, i - mp[s]);
        else mp[s] = i;
    }
    cout << ret;

}

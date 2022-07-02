/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int arr[n + 1];
    map<int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    int ret = 0, s = 0;
    for (int i = 1; i <= n; ++i) {
        s += arr[i];
        int need = s - k;
        if (mp.count(need)) ret = max(ret, i - mp[need]);
        if (mp.count(s) == 0)mp[s] = i;
    }
    cout << ret;
}

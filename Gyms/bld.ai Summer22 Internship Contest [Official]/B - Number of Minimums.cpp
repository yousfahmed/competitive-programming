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
    int n;
    cin >> n;
    int arr[n];
    for (int &i: arr) cin >> i;
    int ret[n];
    int mn = arr[n - 1], cnt = 0;
    for (int i = n - 1; ~i; --i) {
        if (arr[i] < mn) {
            cnt = 1;
            mn = arr[i];
        } else if (arr[i] == mn)cnt++;
        ret[i] = cnt;
    }
    for (int &i: ret) cout << i << ' ';

}

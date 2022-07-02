/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/F
*/
#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int &i: arr) cin >> i;
    sort(arr, arr + n);
    int q, x;
    cin >> q;
    while (q--) {
        cin >> x;
        int idx = lower_bound(arr, arr + n, x) - arr;
        if (idx < n) {
            cout << arr[idx] << '\n';
        } else {
            cout << "Dr. Samer cannot take any offer :(.\n";
        }
    }
}

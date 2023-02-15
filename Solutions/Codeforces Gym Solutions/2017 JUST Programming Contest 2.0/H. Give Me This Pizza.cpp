/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/H
*/
#include <bits/stdc++.h>

using namespace std;
#define all(X) X.begin(),X.end()
#define int long long

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    vector<vector<int>> idx(51);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        idx[arr[i]].emplace_back(i);
    }

    auto query = [&](int i) -> int {
        int ret = n, v = -1;
        for (int j = arr[i] + 1; j <= 50; ++j) {
            auto &a = idx[j];
            auto x = upper_bound(all(a), i);
            if (x != a.end()) {
                if (*x < ret) {
                    ret = *x;
                    v = j;
                }
            }
        }
        return v;
    };

    for (int i = 0; i < n; ++i)
        cout << query(i) << ' ';


}

/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101810/problem/H
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
const int N = 1e5 + 7;
int arr[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        n <<= 1;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            int j = n - i + 1;
            if (j <= n)
                ret = max(ret, arr[i] + arr[j]);
        }
        cout << ret << '\n';
    }

}


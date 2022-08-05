/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101810/problem/B
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> x >> n;
        if (n == 1) {
            cout << x << '\n';
            continue;
        }
        int ret[n];
        memset(ret, 0, sizeof ret);
        int g = 2 + 2 * (n - 2);
        int a = x / g;
        for (int i = 1; i < n - 1; ++i)
            ret[i] += a * 2;
        ret[0] = ret[n - 1] = a;
        int rem = x % g;
        bool flag = true;
        int j = 0;
        for (int i = 0; i < rem; ++i) {
            ret[j]++;
            if (flag)j++;
            else j--;
            if (j == n) j -= 2, flag = !flag;
            if (!~j)j += 2, flag = !flag;
        }
        for (int i = 0; i < n; ++i) {
            cout << ret[i] << " \n"[i + 1 == n];
        }
    }

}


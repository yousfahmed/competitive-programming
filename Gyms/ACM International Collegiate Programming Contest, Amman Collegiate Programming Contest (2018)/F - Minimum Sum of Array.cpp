/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101810/problem/F
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e6 + 7;

int vis[N], val[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int vs = 1; vs <= t; ++vs) {
        int n, sum = 0;
        cin >> n;
        int arr[n];
        for (int &i: arr) cin >> i;
        sort(arr, arr + n);
        if (arr[0] == 1) {
            cout << n << '\n';
            continue;
        }
        for (int i = 0; i < n; ++i) {
            int x = arr[i];
            if (vis[x] != vs) 
                for (int j = x; j < N; j += x) 
                    if (vis[j] != vs)
                        vis[j] = vs, val[j] = x;
                
            
            sum += val[x];
        }
        cout << sum << '\n';
    }

}


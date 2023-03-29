/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(),x.end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("sub.in", "r", stdin);
    int TC;
    TC = 1;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        int arr[n], ret[n];
        map<int, int> mp;
        for (int &i: arr) cin >> i;
        vector<int> s(arr, arr + n);
        sort(all(s));
        for (int i = 0; i < n; ++i) {
            if (mp.count(arr[i])) ret[i] = mp[arr[i]]++;
            else {
                mp[arr[i]] = lower_bound(all(s), arr[i]) - s.begin();
                ret[i] = mp[arr[i]]++;
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int cur = ret[i];
            while (i > cur) {
                i--;
                if (i)cur = min(cur, ret[i]);
            }
            ans++;
        }
        cout << (ans >= k ? "YES" : "NO");
    }
    return 0;
}

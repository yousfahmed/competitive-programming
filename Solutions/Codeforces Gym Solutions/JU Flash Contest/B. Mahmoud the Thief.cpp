/*
  Link : https://codeforces.com/gym/102035/problem/B
  Author : Abdelaleleem
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define all(v)  (v).begin(),(v).end()


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    int arr[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] %= m;
        mp[arr[i]]++;
    }
    for (int i = 0, x; i < n; ++i) {
        if (mp.size() == 1) return cout << i, 0;
        cin >> x;
        mp[arr[x]]--;
        if (mp[arr[x]] == 0) mp.erase(arr[x]);
    }

}

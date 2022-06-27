/*
  Link : https://codeforces.com/gym/102035/problem/E
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
    int n, m, k, x;
    cin >> n >> m >> k;
    int found = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == m)found = 1;
        if (x > m)cnt++;
    }
    if (found == 0 and cnt == 0) cnt = 1;
    k -= cnt;
    cout << (0 <= k ? "YES" : "NO");
}

/*
  Link : https://codeforces.com/gym/102035/problem/K
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
    int n;
    cin >> n;
    int ret = 1;
    for (int i = 1; i <= n; ++i) {
        cout << ret << ' ';
        ret *= 2;
    }
}

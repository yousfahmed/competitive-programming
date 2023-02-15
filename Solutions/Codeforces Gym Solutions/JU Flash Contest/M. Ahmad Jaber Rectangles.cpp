/*
  Link : https://codeforces.com/gym/102035/problem/M
  Author : Abdelaleleem
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b, x, y, h;
    cin >> a >> b >> x >> y >> h;
    if (b < x or a > y) return cout << 0, 0;
    if (b <= y and a >= x) return cout << (b - a) * h, 0;
    if (y <= b and x >= a) return cout << (y - x) * h, 0;
    x = max(x, a);
    y = min(b, y);
    cout << (y - x) * h;
    return 0;
}

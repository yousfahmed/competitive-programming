/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if (a > b)swap(a, b);
    int s = (a + b) * (b - a + 1) / 2;
    cout << ((s & 1) ? "Hoss" : "Nasser");
}

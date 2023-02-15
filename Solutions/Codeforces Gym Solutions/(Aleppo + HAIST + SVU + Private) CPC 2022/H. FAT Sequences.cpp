/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/103821/problem/H
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
const int mod = 1000000007, N = (int) 1e5 + 7;
int fact[N];

int add(int x, int y) {
    x += y;
    while (x >= mod) x -= mod;
    while (x < 0) x += mod;
    return x;
}


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fact[1] = 1;
    fact[2] = 2;
    for (int i = 3; i < N; ++i)
        fact[i] = add(fact[i - 1], fact[i - 2] + 1);
    int TC = 1;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        cout << fact[n] << '\n';
    }

}

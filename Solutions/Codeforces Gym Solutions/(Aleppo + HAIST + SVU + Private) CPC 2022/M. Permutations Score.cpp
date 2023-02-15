/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/103821/problem/M
*/
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int mul(int x, int y) {
    return x * 1LL * y % mod;
}

const int N = 1e5 + 7;
int pref[N], fact[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    for (int i = 1; i < N; ++i)
        for (int j = i * 2; j < N; j += i)
            ++pref[j];
    partial_sum(pref, pref + N, pref);
    fact[1] = 0, fact[2] = 1;
    for (int i = 3; i < N; ++i)
        fact[i] = mul(fact[i - 1], i);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << mul(fact[n], pref[n]) << '\n';
    }

}

/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/A
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 7, mod = 1e9 + 7;
int fact[N];

void pre() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
}

int power(int x, int y) {
    if (y == 0) return 1;
    int temp = power(x, y >> 1) % mod;
    temp = temp * temp % mod;
    if (y & 1) temp = temp * x % mod;
    return temp;
}

int modInv(int x) {
    return power(x, mod - 2) % mod;
}

int nCr(int r, int n) {
    if (r > n)return 0;
    return fact[n] * modInv(fact[r] * fact[n - r] % mod) % mod;
}


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    pre();
    int n, m, k;
    double p;
    cin >> m >> n >> k >> p;
    int ncr = nCr(k - 1, n - 1);
    int c = p * 1000;
    int none = 1000 - c;
    c = c * modInv(1000) % mod;
    none = none * modInv(1000) % mod;
    int t = 1;
    for (int i = 0; i < k; ++i) t = (t * c) % mod;
    for (int i = k; i < n; ++i) t = (t * none) % mod;
    cout << t * ncr % mod;

}

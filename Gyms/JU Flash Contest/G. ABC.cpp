/*
  Link : https://codeforces.com/gym/102035/problem/G
  Author : Abdelaleleem
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 7, mod = 1000000007;
int fact[N];

int power(int n, int p) {
    if (!p) return 1;
    int x = power(n, p >> 1);
    x = (x * x) % mod;
    if (p & 1) x = (x * n) % mod;
    return x;
}

int mul(int x, int y) {
    if (x >= mod) x %= mod;
    if (y >= mod) y %= mod;
    return x * y % mod;
}

int add(int x, int y) {
    x += y;
    while (x >= mod) x -= mod;
    while (x < 0) x += mod;
    return x;
}

int modInv(int x) {
    return power(x, mod - 2);
}

int nCr(int n, int r) {
    if (n < 0 or n < r)return 0;
    if (n == r)return 1;
    return mul(
            fact[n],
            mul(
                    modInv(fact[n - r]),
                    modInv(fact[r])
            )
    );
}


int solve(int n, int k) {
    if (k & 1)return 0;
    int rem = n % k, ret = 0;
    for (int i = 0; i <= k / 2; ++i) {
        int r = k / 2 - i;
        int cur = mul(
                nCr(rem, i),
                power(2, mul(i, n / k + 1))
        );
        cur = mul(
                cur,
                nCr(k - rem, r)
        );
        cur = mul(
                cur,
                power(2, mul(r, n / k))
        );
        ret = add(ret, cur);
    }
    return ret;


}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
}

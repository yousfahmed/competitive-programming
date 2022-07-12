/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 20, mod = 1e9 + 7;

int mem[N][(1 << 20) + 7];
int arr[21][21];
int n, all;

int add(int i, int x) {
    i += x;
    while (i >= mod) i -= mod;
    while (i < 0)i += mod;
    return i;
}

int dp(int i, int msk, int cnt = 0) {
    if (i == n)return (cnt == n ? 1 : 0);
    int &ret = mem[i][msk];
    if (~ret)return ret;
    ret = 0;
    for (int j = 0; j < n; ++j)
        if (arr[i][j] and !(msk & (1 << j)))
            ret = add(ret, dp(i + 1, msk | (1 << j), cnt + 1));
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(mem, -1, sizeof mem);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << dp(0, 0);

}

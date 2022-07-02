/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/B
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll

const int N = 1e4 + 7, M = (1 << 11), mod = 1e9 + 7;
int mem[N][M], arr[N];
int n;

int dp(int i, int msk) {
    if (i == n)return 1;
    int &ret = mem[i][msk];
    if (~ret)return ret;
    ret = 0;
    ret = dp(i + 1, (1 << arr[i]));
    if (!(msk & (1 << arr[i]))) {
        ret = (ret +
               dp(i + 1, msk | (1 << arr[i]))
              ) % mod;
    }
    return ret;


}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(mem, -1, sizeof mem);
    cin >> n;
    char x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        arr[i] = x - '0';
    }
    cout << dp(1, (1 << arr[0]));

}

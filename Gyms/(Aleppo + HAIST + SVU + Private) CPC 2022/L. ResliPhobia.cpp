/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/103821/problem/L
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
const int N = 1007;
int mem[3][N][N], vis[3][N][N], arr[N], vs;
int n, k;

int dp(int i, int mx, int s) {
    if (mx > k)return -1e18;
    if (i == n)return 0;
    int &ret = mem[s][i][mx];
    if (vis[s][i][mx] == vs)return ret;
    vis[s][i][mx] = vs;
    ret = max(
            dp(i + 1, mx, s),
            arr[i] + dp(i + 1,
                        (s != (arr[i] & 1) ? 1 : mx + 1),
                        (arr[i] & 1)
            )
    );
    return ret;
}


int solve() {
    vs++;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    return dp(0, 0, 2);
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC = 1;
    cin >> TC;
    while (TC--)
        cout << solve() << '\n';

}

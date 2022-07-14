/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To Gym : https://codeforces.com/gym/101653
*/
#include<bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
const int mod = 1e9 + 7, N = 2e5 + 7;
int a[N], b[N];
int mem[2][102][102][201];
int vis[2][102][102][201], vs;
int n;


int dp(int i, int x, int y, bool st) {
    if (i == n)return 0;
    int &ret = mem[st][x][y][i];
    if (vis[st][x][y][i] == vs)return ret;
    vis[st][x][y][i] = vs;
    int op1 = 0;
    if (!st or (a[i] > x and b[i] < y) ) 
            op1 = 1 + dp(i + 1, a[i], b[i], true);
    ret = max(
            op1,
            dp(i + 1, x, y, st)
    );
    return ret;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    double x;
    for (vs = 1; vs <= T; ++vs) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;  a[i] = x * 10;
            cin >> x;  b[i] = x * 10;
        }
        cout << dp(0, 0, 0, false) << '\n';
    }
}

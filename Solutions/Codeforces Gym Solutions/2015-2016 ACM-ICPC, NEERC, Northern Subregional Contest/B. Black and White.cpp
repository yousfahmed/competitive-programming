/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link : https://codeforces.com/gym/100801
*/
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 2e4;

#define char unsigned char
char arr[4][N];

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("output.out", "w", stdout);
#else
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
#endif
    int n, m;
    cin >> m >> n;
    if (n == m) {
        cout << 1 << ' ' << n * 2 << '\n';
        for (int i = 0; n or m; ++i) {
            if (i & 1) {
                cout << '.';
                --n;
            } else {
                cout << '@';
                --m;
            }
        }
        return 0;
    }
    char b = '@', w = '.';
    if (n < m)swap(b, w), swap(n, m);
    for (auto &i: arr)
        for (char &j: i)
            j = w;
    int i = 0;
    --m, n--;
    while (n > 0) {
        arr[0][i] = arr[1][i] = b;
        arr[1][i + 1] = arr[1][i + 2] = b;
        i += 2;
        arr[0][i] = arr[1][i] = b;
        n--;
    }
    for (int j = 1; m > 0; j += 2) {
        arr[3][j] = b;
        --m;
    }
    cout << 4 << ' ' << N << '\n';
    for (auto &j: arr) {
        for (char k: j)
            cout << k;
        cout << '\n';
    }
}

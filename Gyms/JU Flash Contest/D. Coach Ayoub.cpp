/*
  Link : https://codeforces.com/gym/102035/problem/D
  Author : Abdelaleleem
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("pyramid.in", "r", stdin);
#endif
    int n, a, b, s;
    cin >> n >> a >> b >> s;

    if (n == 1) {
        cout << ((a == s and a == b) ? "YES" : "NO");
    } else if (n == 2) {
        cout << (a + b == s ? "YES" : "NO");
    } else {
        int rem = (s - ((n - 1) * a + b));
        if (rem < 0) cout << "NO";
        else if (!rem) {
            cout << "YES";
        } else {
            rem = (rem / (n - 2)) + (!!(rem % (n - 2)));
            cout << ((rem + a) <= b ? "YES" : "NO");
        }
    }
}

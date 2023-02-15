/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To Gym : https://codeforces.com/gym/101653
*/
#include<bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int v, e;
        cin >> v >> e;
        cout << (2 + e - v) << '\n';
    }
}

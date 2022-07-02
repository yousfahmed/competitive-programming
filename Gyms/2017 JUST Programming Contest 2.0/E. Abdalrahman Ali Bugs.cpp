/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/E
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
string s;
int f[30];

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> s;
    for (char &i: s) f[i - 'a']++;
    int ret = INT32_MAX, p = -1;
    for (int i = 2; i <= (int) 1e6; ++i) {
        int cnt = 0;
        for (int &j: f) cnt += ((j % i) * j);

        if (cnt < ret)
            ret = cnt, p = i;
    }
    assert(~p);
    cout << p;
}

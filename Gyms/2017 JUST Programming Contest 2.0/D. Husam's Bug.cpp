/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/D
*/
#include <bits/stdc++.h>

using namespace std;
#define all(X) X.begin(),X.end()

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int alpha = count_if(all(s), [&](char x) { return isalpha(x); });
        int num = count_if(all(s), [&](char x) { return isdigit(x); });
        int none = count_if(all(s), [&](char x) { return x == '@' or x == '?' or x == '!'; });
        cout << "The last character ";
        if (alpha < 4) cout << "must be a letter.\n";
        else if (num < 4) cout << "must be a digit.\n";
        else if (none < 2) cout << "must be a symbol.\n";
        else cout << "can be any type.\n";
    }
}

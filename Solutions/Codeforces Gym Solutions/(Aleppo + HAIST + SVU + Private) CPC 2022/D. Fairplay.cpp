/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/103821/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC;
    cin >> TC;

    auto can = [](int x) {
        int S = sqrt(x);
        return S * S != x;
    };

    while (TC--) {
        int n;
        cin >> n;
        int lst = n + 1;
        if (can(lst)) {
            cout << "-1\n";
            continue;
        }
        vector<int> ret;
        for (int i = 1; i * i != lst; ++i) ret.emplace_back(i);
        cout << ret.size() << '\n';
        for (int &i: ret)cout << i << ' ';
        cout << '\n';
    }


}

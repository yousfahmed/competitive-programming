/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101755/problem/L
*/
#include <bits/stdc++.h>

using namespace std;

#define all(v)  (v).begin(),(v).end()

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s, tmp;
    cin >> s;
    int lenS = (int) s.length(), q;
    vector<vector<int>> idx(300);
    for (int i = 0; i < lenS; ++i) idx[s[i]].emplace_back(i);
    stack<int> lstIdx;
    lstIdx.emplace(-2);
    cin >> q;
    char ch;
    while (q--) {
        cin >> tmp;
        if (tmp == "push") {
            cin >> ch;
            auto it = idx[ch].end();
            if (~lstIdx.top())
                it = upper_bound(all(idx[ch]), lstIdx.top());

            if (it == idx[ch].end()) lstIdx.emplace(-1);
            else lstIdx.emplace(*it);
        } else
            lstIdx.pop();

        cout << (~lstIdx.top() ? "YES\n" : "NO\n");
    }

}

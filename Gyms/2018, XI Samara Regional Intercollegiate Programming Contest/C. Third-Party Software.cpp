/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101755/problem/C
*/
#include <bits/stdc++.h>

using namespace std;

#define all(v)  (v).begin(),(v).end()
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    set<pair<int, int>> a, b;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.emplace(y, x);
        b.emplace(x, y);
    }

    vector<int> ret;
    while (a.size()) {
        auto it = a.begin();
        ret.emplace_back(it->first);
        stack<pair<int, int>> s;
        while (b.size() and b.begin()->first <= it->first) {
            s.emplace(*b.begin());
            b.erase(b.begin());
        }
        while (s.size())
            a.erase({s.top().second, s.top().first}), s.pop();
    }
    cout << ret.size() << '\n';
    for (auto &iy: ret)cout << iy << ' ';


}

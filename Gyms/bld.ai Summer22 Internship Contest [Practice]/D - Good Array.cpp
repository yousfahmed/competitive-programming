/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, x;
    cin >> n;
    stack<int> s;
    while (n--) {
        cin >> x;
        if (s.size() and s.top() == x) s.pop();
        else s.emplace(x);
    }
    vector<int> ret;
    while (s.size()) ret.emplace_back(s.top()), s.pop();
    reverse(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int &i: ret)cout << i << ' ';
}

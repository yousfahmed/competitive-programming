/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v)  (v).begin(),(v).end()
int n, k;

int solve(vector<int> &X, vector<int> &Y) {
    multiset<pair<int, int >> arr;
    multiset<int> mn;
    int ret = -1;
    for (int i = 0, x, y; i < n; ++i) {
        x = X[i], y = Y[i];
        while (arr.size() and arr.begin()->first < x - k) {
            int u = arr.begin()->first, v = arr.begin()->second;
            arr.erase(arr.begin());
            mn.erase(mn.find(u - v));
        }
        if (mn.size()) ret = max(ret, (x + y) - *mn.begin());
        arr.emplace(x, y);
        mn.emplace(x - y);
    }
    return ret;
}

int solve2(vector<int> &X, vector<int> &Y) {
    multiset<pair<int, int >> arr;
    multiset<int> mn;
    int ret = -1;
    for (int i = 0, x, y; i < n; ++i) {
        x = X[i], y = Y[i];
        while (arr.size() and arr.rbegin()->first > x + k) {
            int u = arr.rbegin()->first, v = arr.rbegin()->second;
            arr.erase(--arr.end());
            mn.erase(mn.find(u + v));
        }
        if (mn.size()) ret = max(ret, *mn.rbegin() - (x - y));
        arr.emplace(x, y);
        mn.emplace(x + y);
    }
    return ret;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    int ret = solve(x, y);
    reverse(all(x));
    reverse(all(y));
    ret = max(ret, solve2(x, y));
    cout << ret;
}

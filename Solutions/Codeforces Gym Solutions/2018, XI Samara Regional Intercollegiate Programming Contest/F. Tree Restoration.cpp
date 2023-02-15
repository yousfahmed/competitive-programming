/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101755/problem/F
*/
#include <bits/stdc++.h>

using namespace std;

#define all(v)  (v).begin(),(v).end()
#define bs binary_search

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> suc(n);
    int cnt[n];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0, sz; i < n; ++i) {
        cin >> sz;
        suc[i].resize(sz);
        for (int &j: suc[i]) {
            cin >> j;
            cnt[--j]++;
        }
        sort(all(suc[i]));
    }
    int numOfLvl = *max_element(cnt, cnt + n);
    vector<vector<int>> lvl(numOfLvl + 7);
    for (int i = 0; i < n; ++i) lvl[cnt[i]].emplace_back(i);
    if (lvl[0].size() > 1)return cout << "NO", 0;
    int par[n];
    memset(par, -1, sizeof par);
    for (int i = numOfLvl; i > 0; --i) {
        for (auto &ch: lvl[i]) {
            bool f = false;
            for (auto &p: lvl[i - 1]) {
                if (bs(all(suc[p]), ch)) {
                    if (f) return cout << "NO", 0;
                    f = true;
                    par[ch] = p;
                }
            }
            if (!f) return cout << "NO", 0;
        }
    }
    vector<pair<int, int>> ret;
    for (int i = 0; i < n; ++i) {
        if (~par[i]) ret.emplace_back(par[i] + 1, i + 1);
        for (int j = par[i]; ~j; j = par[j])
            if (!bs(all(suc[j]), i))return cout << "NO", 0;
    }
    assert(ret.size() == n - 1);
    cout << "YES\n";
    for (auto &i: ret)
        cout << i.first << ' ' << i.second << '\n';

}

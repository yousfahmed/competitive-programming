/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To Gym : https://codeforces.com/gym/101653
*/

#include<bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
const int mod = 1e9 + 7, N = 2e5 + 7;


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
        int n;
        cin >> n;
        vector<int> f(1001);
        while (n--) {
            int x;
            cin >> x;
            ++f[x];
        }
        int cnt = 0, ret = 0;
        for (int i = 0; i < f.size(); ++i)
            if (f[i] > cnt)
                ret = i, cnt = f[i];

        assert(ret);
        cout << ret << '\n';
    }
}

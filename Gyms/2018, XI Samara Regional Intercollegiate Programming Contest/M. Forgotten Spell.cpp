/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101755/problem/M
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 200000 + 7;
int mem[1 << 3][N];
int n;
string s[3];

int dp(int i, int msk) {
    if (i == n)return 1;
    int &ret = mem[msk][i];
    if (~ret) return ret;
    ret = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        int newMsk = msk;
        for (int j = 0; j < 3; ++j) {
            if (s[j][i] != c) {
                if (!(newMsk & (1 << j))) newMsk |= (1 << j);
                else {
                    newMsk = -1;
                    break;
                }
            }
        }
        if (~newMsk) {
            ret += dp(i + 1, newMsk);
            if (ret > 1)return 2;
        }
    }
    return ret;
}


string ans;

void builtOutput(int i, int msk) {
    if (i == n)return;
    int ret = dp(i, msk);
    for (char c = 'a'; c <= 'z'; ++c) {
        int newMsk = msk;
        for (int j = 0; j < 3; ++j) {
            if (s[j][i] != c) {
                if (!(newMsk & (1 << j))) newMsk |= (1 << j);
                else {
                    newMsk = -1;
                    break;
                }
            }
        }
        if (~newMsk and ret == dp(i + 1, newMsk)) {
            ans += c;
            builtOutput(i + 1, newMsk);
            return;
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(mem, -1, sizeof mem);
    for (string &i: s)cin >> i;
    n = s->size();
    int ret = dp(0, 0);
    if (!ret)cout << "Impossible";
    else if (ret > 1) cout << "Ambiguous";
    else {
        builtOutput(0, 0);
        assert(ans.length() == n);
        cout << ans;
    }
}

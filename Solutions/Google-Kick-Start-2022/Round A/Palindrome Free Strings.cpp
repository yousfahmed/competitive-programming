#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X).size())


const int N = 5e4 + 7, M = (1 << 6) - 1;
bool mem[N][M + 1];
int mem2[M + 1], vis[N][M + 1], vs;
char str[N];

bool havePalindrome(string s) {
    string x = s;
    reverse(s.begin(), s.end());
    return (x == s);
}

bool check(int msk) {
    int &res = mem2[msk];
    if (~res) return res;
    string s;
    for (int i = 5; i >= 0; --i) s += ((msk >> i) & 1)+'0';
    res = (havePalindrome(s) or havePalindrome(s.substr(0, 5)) or havePalindrome(s.substr(1)));
    return res;
}

bool BASE(int msk) {
    string s;
    for (int i = 4; i >= 0; --i) s += (((msk >> i) & 1) ? '1' : '0');
    return havePalindrome(s);
}

bool solve(int i, int msk) {
    if (i == 5 and BASE(msk)) return false;
    if (i > 5 and check(msk)) return false;
    if (!str[i]) return true;
    bool &ret = mem[i][msk];
    if (vis[i][msk] == vs)return ret;
    vis[i][msk] = vs;
    if (str[i] != '?') ret = solve(i + 1, ((msk << 1) + (str[i] == '1')) & M);
    else {
        ret = solve(i + 1, ((msk << 1) + 1) & M);
        ret |= solve(i + 1, (msk << 1) & M);
    }
    return ret;
}

signed main() {
    memset(mem2, -1, sizeof mem2);
    int t;
    scanf("%d", &t);
    for (int i = 1, x; i <= t and ++vs; ++i) {
        scanf("%d%s", &x, str);
        printf("Case #%d: %s\n", i, (solve(0, 0) ? "POSSIBLE" : "IMPOSSIBLE"));
    }
}


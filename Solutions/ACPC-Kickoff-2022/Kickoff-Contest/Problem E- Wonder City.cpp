
// By AmmarDab3an

#include "bits/stdc++.h"

using namespace std;
const int MOD = 1e9 + 7;
#define int long long

int mul(int a, int b) {
    int ret = a % MOD * (b % MOD) % MOD;
    return (ret + MOD) % MOD;
}

int add(int a, int b) {
    int ret = (a % MOD + b % MOD) % MOD;
    return (ret + MOD) % MOD;
}

int pow_exp(int n, int p) {
    if (!p) return 1;
    if (p & 1) return mul(n, pow_exp(n, p - 1));
    int tmp = pow_exp(n, p / 2);
    return mul(tmp, tmp);
}

const int NMAX = 2e5 + 10, _2 = pow_exp(2, MOD - 2),
        _3 = pow_exp(3, MOD - 2);

int n;
int pro[3];
int mem[NMAX][4][4];
int vis[NMAX][4][4], vs;

int dp(int i, int lst, int cnt_s) {
    if (i == n) return 0;
    int &ret = mem[i][lst][cnt_s];
    if (vis[i][lst][cnt_s] == vs) return ret;
    vis[i][lst][cnt_s] = vs;

    if (lst == 2) {
        int st_path = mul(_2, dp(i + 1, 0, 1));
        int nd_path = mul(_2, dp(i + 1, 1, 0));
        ret = add(st_path, nd_path);
    } else {
        int st_path = mul(_3, add(cnt_s == 2, dp(i + 1, 0, min(cnt_s + 1, 2ll))));
        int nd_path = mul(_3, dp(i + 1, 1, 0));
        int rd_path = mul(_3, dp(i + 1, 2, 0));
        ret = add(st_path, add(nd_path, rd_path));
    }
    return ret;
}

signed main() {

    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("wonder.in", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        vs++;
        cin >> n;
        for (int &i: pro) {
            int a, b;
            cin >> a >> b;
            i = mul(a, pow_exp(b, MOD - 2));
        }

        int st_path = mul(pro[0], dp(1, 0, 1));
        int nd_path = mul(pro[1], dp(1, 1, 0));
        int rd_path = mul(pro[2], dp(1, 2, 0));
        int ans = add(st_path, add(nd_path, rd_path));

        cout << ans << '\n';
    }
}

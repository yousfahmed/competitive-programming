#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define ll long long

const int N = 407;

int vis[N][N][N], vs;
int arr[N];
int n, d;

#define int ll

int mem[N][N][N];

int dp(int l, int r, int idx) {
    if (l == 0 and r == n - 1) return min(d - arr[idx], arr[idx]);
    int &ret = mem[l][r][idx];
    if (vis[l][r][idx] == vs) return ret;
    vis[l][r][idx] = vs;
    if (!l) {
        int v = min(
                arr[r + 1] > arr[idx] ? arr[r + 1] - arr[idx] : d - arr[idx] + arr[r + 1],
                arr[r + 1] > arr[idx] ? arr[idx] + d - arr[r + 1] : arr[idx] - arr[r + 1]
        );
        ret = dp(l, r + 1, r + 1) + v;
    } else if (r == n - 1) {

        int v = min(
                arr[l - 1] > arr[idx] ? arr[l - 1] - arr[idx] : d - arr[idx] + arr[l - 1],
                arr[l - 1] > arr[idx] ? arr[idx] + d - arr[l - 1] : arr[idx] - arr[l - 1]
        );
        ret = dp(l - 1, r, l - 1) + v;


    } else {
        int v1 = min(
                arr[r + 1] > arr[idx] ? arr[r + 1] - arr[idx] : d - arr[idx] + arr[r + 1],
                arr[r + 1] > arr[idx] ? arr[idx] + d - arr[r + 1] : arr[idx] - arr[r + 1]
        );
        int v2 = min(
                arr[l - 1] > arr[idx] ? arr[l - 1] - arr[idx] : d - arr[idx] + arr[l - 1],
                arr[l - 1] > arr[idx] ? arr[idx] + d - arr[l - 1] : arr[idx] - arr[l - 1]
        );
        ret = min(dp(l - 1, r, l - 1) + v2, dp(l, r + 1, r + 1) + v1);
    }
    return ret;
}


void solve() {
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (i and arr[i] == arr[i - 1])
            i--, n--;
    }
    int res = dp(0, 0, 0);
    for (int i = 1; i < n; ++i)
        res = min(res, dp(i, i, i));

    cout << res;

}

signed main() {
    NeedForSpeed;
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        vs++;
        cout << "Case #" << i << ": ";
        solve();
        if (t) cout << '\n';
    }
    return 0;
}

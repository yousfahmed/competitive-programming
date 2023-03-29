/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include "bits/stdc++.h"

using namespace std;
const int N = 1000007;
#define int long long

int arr[N];
bool vis[N];

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("erase.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[arr[i]]) {
            ret++;
            for (int j = arr[i]; j < N; j += arr[i])
                vis[j] = true;
        }
    }
    cout << ret;

}

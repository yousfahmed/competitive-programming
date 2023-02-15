/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101755/problem/B
*/


#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define all(v)  (v).begin(),(v).end()
#define bs binary_search

int area(int x1, int y1, int x2, int y2, int x3, int y3) {
    swap(x1, x3), swap(y1, y3);
    return ((x1 * y2) + (x2 * y3) + (x3 * y1))
           - ((y1 * x2) + (x1 * y3) + (y2 * x3));
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    pair<int, int> arr[n];
    for (auto &i: arr) cin >> i.first >> i.second;
    int ans = min(area(arr[1].first, arr[1].second,
                       arr[0].first, arr[0].second,
                       arr[n - 1].first, arr[n - 1].second),
                  area(arr[0].first, arr[0].second,
                       arr[n - 1].first, arr[n - 1].second,
                       arr[n - 2].first, arr[n - 2].second)
    );
    for (int i = 2; i < n; ++i) {
        ans = min(ans,
                  area(arr[i].first, arr[i].second,
                       arr[i - 1].first, arr[i - 1].second,
                       arr[i - 2].first, arr[i - 2].second
                  )
        );
    }
    cout << ans;

}


/*
   Author : Abdelaleem Ahmed
   Handle Codeforces : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int st = 1, end = 1e9, mid, ans = 1;
    string s;
    while (st <= end) {
        mid = (end - st) / 2 + st;
        cout << mid << "\n";
        cout.flush();
        cin >> s;
        if (s == "=") {
            ans = mid;
            break;
        } else if (s == "<")
            end = mid - 1;
        else
            ans = mid, st = mid + 1;

    }

    cout << "! " << ans;
    cout.flush();
}

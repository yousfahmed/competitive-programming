#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


void solve() {
    string s;
    ll sum = 0;
    cin >> s;
    for (char &i: s) sum += (i - '0');
    sum = ((sum - (sum % 9) + 9) - sum) % 9;
    bool printed = false, first = true;
    for (char &i: s) {
        if (printed or first and sum == 0) {
            cout << i;
        } else if (i - '0' > sum) {
            cout << sum << i;
            printed = true;
        } else
            cout << i;

        first = false;
    }
    if (!printed) cout << sum;
}

int main() {
    NeedForSpeed;
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        if (t) cout << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()

void solve() {

    int n;
    string s;
    cin >> n >> s;
    if (find_if(all(s), [&](char x) {
        return isdigit(x);
    }) == s.end()) {
        s += '1';
    }
    if (find_if(all(s), [&](char x) {
        return x == '#' or x == '@' or x == '*' or x == '&';
    }) == s.end()) {
        s += '@';
    }
    if (find_if(all(s), [&](char x) {
        return isalpha(x) and islower(x);
    }) == s.end()) {
        s += 'a';
    }
    if (find_if(all(s), [&](char x) {
        return isalpha(x) and isupper(x);
    }) == s.end()) {
        s += 'A';
    }
    while (s.length() < 7) {
        s += 'a';
    }
    cout << s;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        if (t) cout << '\n';
    }
    return 0;
}

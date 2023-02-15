/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To Gym : https://codeforces.com/gym/101653
*/

#include<bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
double dig;
pair<double, double> Round(double a) {
    return {ceil(a * dig) / dig, floor(a * dig) / dig};
}


bool num(string s) {
    if (count(all(s), '.') == 0)return 1;
    while (s.back() == '0')s.pop_back();
    return s.back() == '.';
}

void solve() {
    string s;
    getline(cin, s);
    assert(count(all(s), ' ') == 0);
    if (num(s)) {
        bool found = count(all(s), '.');
        while (found and s.back() == '0') s.pop_back();
        if (s.back() == '.')s.pop_back();
        if (s.empty())s.push_back('0');
        cout << s << "\"";
        return;
    }
    bool prolog = false;
    if (s.front() != '0') {
        while (s.front() != '.') {
            cout << s.front(), prolog = true;
            s = s.substr(1);
        }
    }
    while (s.size() and s.front() != '.')s = s.substr(1);
    if (prolog)cout << " ";
    dig = 1;
    for (int i = 1; i < s.length(); ++i) dig *= 10;
    for (int i = 1; i <= 128; i <<= 1) {
        for (int j = 1; j < i; ++j) {
            auto ret = Round((1.0 * j) / (1.0 * i));
            string a = to_string(ret.first), b = to_string(ret.second);
            a = a.substr(1), b = b.substr(1);
            while (a.size() > s.size())a.pop_back();
            while (b.size() > s.size())b.pop_back();
            while (a.size() < s.size())a.push_back('0');
            while (b.size() < s.size())b.push_back('0');
            if (a == s or b == s) {
                cout << j << '/' << i << "\"";
                return;
            }
        }
    }
    assert(false);
    cout << "Who brought you here?";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; ++i) {
        solve();
        cout << '\n';
    }
}

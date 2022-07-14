/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To Gym : https://codeforces.com/gym/101653
*/
#include<bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long


int solve(string s, int d) {
    for (char &i: s)if (i == '?')i = '0' + d;
    return stoll(s);
}

int solve() {

    int i = 0;
    string a, b, r, s;
    cin >> s;
    if (s.front() == '-') a += s[i++];
    for (; i < s.length(); ++i) {
        if (s[i] == '-' or s[i] == '*' or s[i] == '+') {
            a = s.substr(0, i);
            break;
        }
    }
    char op = s[i++];
    int prolog = i;
    for (; i < s.length(); ++i) {
        if (s[i] == '=') {
            b = s.substr(prolog, i - prolog);
            r = s.substr(i + 1);
            break;
        }
    }

    i = (*((a.front() == '-') + a.begin()) == '?' and a.size() > 1)
        or (*((b.front() == '-') + b.begin()) == '?' and b.size() > 1)
        or (*((r.front() == '-') + r.begin()) == '?' and r.size() > 1);

    while (i <= 9) {
        if (count(all(a), '0' + i) or count(all(b), '0' + i) or count(all(r), '0' + i)) { ++i; continue; }
        int n1 = solve(a, i);
        int n2 = solve(b, i);
        int res = solve(r, i);
        if (op == '+' and n1 + n2 == res) {
            return i;
        } else if (op == '-' and n1 - n2 == res) {
            return i;
        } else if (op == '*' and n1 * n2 == res) {
            return i;
        }
        i++;
    }
    return -1;
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
        cout << solve() << '\n';
    }
}

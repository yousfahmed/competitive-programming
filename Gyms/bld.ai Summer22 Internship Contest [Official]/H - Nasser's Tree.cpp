/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 20, mod = 1e9 + 7;

int prevNodes(int l) {
    l -= 1;
    return (1LL << l) - 1;
}

int valueForNode(int i, int l, int h) {
    int nodeId = i;
    nodeId -= prevNodes(l);
    return (1LL << (h - l)) * (2 * nodeId - 1);
}

int a, b;

int LCA(int i, int l, int h) {
    assert(l <= h);
    int v = valueForNode(i, l, h);
    if (v > a and v > b)
        return LCA(i << 1, l + 1, h);
    if (v < a and v < b)
        return LCA((i << 1) | 1, l + 1, h);
    return v;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    while (q--) {
        int h;
        cin >> h >> a >> b;
        cout << LCA(1, 1, h) << '\n';
    }
}

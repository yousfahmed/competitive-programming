#include<bits/stdc++.h>

using namespace std;
#define int long long
const int inf = 1e18;
vector<vector<int>> b;
vector<int> ans_for_block;
int SQ;

void SQRT_Dec(int *a, int n) {
    SQ = ceil(sqrt(n));
    b = vector<vector<int>>(SQ);
    ans_for_block = vector<int>(SQ, inf);
    for (int i = 0; i < n; ++i) {
        int b_num = i / SQ;
        b[b_num].emplace_back(a[i]);
        ans_for_block[b_num] = min(
                ans_for_block[b_num],
                a[i]
        );
    }
}

int query(int l, int r) {
    int ret = inf;
    while (l <= r) {
        int b_idx = l / SQ;
        if (l % SQ == 0 and l + b[b_idx].size() <= r) {
            ret = min(ret, ans_for_block[b_idx]);
            l += SQ;
        } else {
            ret = min(
                    ret,
                    b[b_idx][l % SQ]
            );
            ++l;
        }
    }
    return ret;
}

void update(int i, int v) {
    int b_idx = i / SQ;
    int idx_for = i % SQ;
    if (ans_for_block[b_idx] == b[b_idx][idx_for] and v < b[b_idx][idx_for]) {
        b[b_idx][idx_for] = v;
        int mx = inf;
        for (auto &j: b[b_idx]) {
            mx = min(j, mx);
        }
        ans_for_block[b_idx] = mx;
    } else {
        b[b_idx][idx_for] = v;
        ans_for_block[b_idx] = min(
                ans_for_block[b_idx],
                v
        );
    }
}

signed main() {
    int n;
    cin >> n;
    int a[n];
    for (int &i: a) cin >> i;
    int q;
    cin >> q;
    SQRT_Dec(a, n);
    int t = 2, l, r;
    int i, v;
    while (q--) {
//        cin >> t;
        if (t == 1) {
            cin >> i >> v;
            update(--i, v);
            /// update
        } else {
            if (r < l)swap(l, r);
            cin >> l >> r; ///query
            cout << query(l, r) << '\n';
        }

    }
}

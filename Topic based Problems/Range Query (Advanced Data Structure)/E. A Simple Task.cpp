/*
 *      Topic : Segment Tree & Counting Sort
 *      Problem Name : E. A Simple Task
 *      Link To problem : https://codeforces.com/contest/558/problem/E
 *      Author : Abdelaleem Ahmed
 *      Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
 */

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
private:
    vector<int> seg, lazy;
    int sz;

    void propagate(int x, int lx, int rx) {
        if (!~lazy[x])return;
        if (rx - lx > 1) {
            lazy[x * 2 + 1] = lazy[x];
            lazy[x * 2 + 2] = lazy[x];
        }
        seg[x] = lazy[x] * (rx - lx) ;
        lazy[x] = -1;
    }

    int merge(int x, int y) {
        return x + y;
    }

    void update(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (r <= lx or rx <= l) return;
        if (l <= lx and rx <= r) {
            lazy[x] = v;
            propagate(x, lx, rx);
            return;
        }
        int m = (rx + lx) >> 1;
        update(l, r, v, x * 2 + 1, lx, m);
        update(l, r, v, x * 2 + 2, m, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    int query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (r <= lx or rx <= l)return 0;
        if (l <= lx and rx <= r)return seg[x];
        int m = (rx + lx) >> 1;
        return merge(
                query(l, r, x * 2 + 1, lx, m),
                query(l, r, x * 2 + 2, m, rx)
        );
    }

public:
    void init(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(sz << 1, 0);
        lazy.assign(sz << 1, -1);
    }

    void update(int l, int r, int val) {
        if (l == r)return;
        if (r < l)swap(l, r);
        update(l, r, val, 0, 0, sz);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, sz);
    }

} seg[26];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    for (auto &i: seg)i.init(n);
    char x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        seg[x - 'a'].update(i, i + 1, 1);
    }
    int cnt[26]{};
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        for (int i = 0; i < 26; ++i) { /// count
            cnt[i] = seg[i].query(l, r);
            seg[i].update(l, r, 0);
            if (!k)cnt[i] *= -1;
        }
        if (!k) l = r;
        for (int i = 0; i < 26; ++i) {/// sort
            seg[i].update(l, l + cnt[i], 1);
            l += cnt[i];
            cnt[i] = 0;
        }
    }
    char ch = 'a';
    for (int i = 0; i < n; ++i , ch = 'a')
        for (auto &j: seg)
            if (j.query(i, i + 1) or (++ch , 0)) { cout << ch; break; }

}

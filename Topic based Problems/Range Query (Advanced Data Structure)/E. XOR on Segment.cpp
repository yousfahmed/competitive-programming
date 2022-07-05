/*
 *      Topic : Segment Tree & BitMasks
 *      Problem Name : E. XOR on Segment
 *      Link To problem : https://codeforces.com/contest/242/problem/E
 *      Author : Abdelaleem Ahmed
 *      Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
 */

#include <bits/stdc++.h>

using namespace std;
#define int long long

struct item {
    int freq[20]{0}, cnt = 0;

    item() : cnt(0) {}

    item(int x) {
        cnt = 1;
        int bit = 0;
        while (x) {
            freq[bit++] = (x & 1);
            x >>= 1;
        }
    }

    int value() {
        int ret = 0;
        for (int i = 0; i < 20; ++i)
            ret += ((1 << i) * freq[i]);
        return ret;
    }

};

struct SegmentTree {
private:
    vector<item> seg;
    vector<int> lazy;
    int sz;

    static item merge(const item &x, const item &y) {
        item ret;
        for (int j = 0; j < 20; ++j)
            ret.freq[j] = x.freq[j] + y.freq[j];
        ret.cnt = x.cnt + y.cnt;
        return ret;
    }

    void built(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size()) seg[x] = item(arr[lx]);
            return;
        }
        int mid = (rx + lx) >> 1;
        built(arr, x * 2 + 1, lx, mid);
        built(arr, x * 2 + 2, mid, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    void applyLazy(int x, int val) {
        if (x * 2 + 1 < (sz << 1)) lazy[x * 2 + 1] ^= val;
        if (x * 2 + 2 < (sz << 1)) lazy[x * 2 + 2] ^= val;
        int bit = 0;
        while (val) {
            if (val & 1)
                seg[x].freq[bit] = seg[x].cnt - seg[x].freq[bit];
            val >>= 1;
            bit++;
        }
        lazy[x] = 0;
    }

    void update(int l, int r, int val, int x, int lx, int rx) {
        applyLazy(x, lazy[x]);
        if (l >= rx or r <= lx)return;
        if (lx >= l and rx <= r) {
            lazy[x] ^= val;
            applyLazy(x, lazy[x]);
            return;
        }
        int mid = (rx + lx) >> 1;
        update(l, r, val, x * 2 + 1, lx, mid);
        update(l, r, val, x * 2 + 2, mid, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }


    int query(int l, int r, int x, int lx, int rx) {
        applyLazy(x, lazy[x]);
        if (rx <= r and lx >= l) return seg[x].value();
        if (l >= rx or lx >= r)return 0;
        int m = (rx + lx) >> 1;
        return
                query(l, r, x * 2 + 1, lx, m) +
                query(l, r, x * 2 + 2, m, rx);
    }


public:
    void init(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.resize(sz << 1), lazy.resize(sz << 1);
    }


    void built(vector<int> &arr) {
        init(arr.size());
        built(arr, 0, 0, sz);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, sz);
    }

    void update(int l, int r, int val) {
        update(l, r, val, 0, 0, sz);
    }


};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i: arr)cin >> i;
    SegmentTree seg;
    seg.built(arr);
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l - 1, r) << '\n';
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            seg.update(l - 1, r, x);
        }
    }
}

/*
  Link : https://codeforces.com/gym/102035/problem/J
  Author : Abdelaleleem
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long

class segmentTree {
private:
    struct item;
    vector<item> seg;
    int sz;

    struct item {
        int pref, suf, sum, ans;

        item(int pref,
             int suffix,
             int sum,
             int ans)
                : pref(pref), ans(ans), sum(sum), suf(suffix) {}

        item() : pref(0), ans(0), sum(0), suf(0) {}
    };

    static item singleItem(int s) {
        return {s, s, s, s};
    }

    item merge(item x, item y) {
        return item(max(x.sum + y.pref, x.pref),
                    max(y.sum + x.suf, y.suf),
                    x.sum + y.sum,
                    max({
                                x.ans,
                                y.ans,
                                x.suf + y.pref
                        })
        );
    }

    void built(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size()) seg[x] = singleItem(arr[lx]);
            return;
        }
        int mid = (rx + lx) >> 1;
        built(arr, x * 2 + 1, lx, mid);
        built(arr, x * 2 + 2, mid, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    void set(int idx, int val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = singleItem(val);
            return;
        }
        int mid = (rx + lx) >> 1;
        if (idx < mid) set(idx, val, x * 2 + 1, lx, mid);
        else set(idx, val, x * 2 + 2, mid, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

public:
    void init(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.resize(2 * sz);
    }

    void built(vector<int> &arr) {
        init(arr.size());
        built(arr, 0, 0, sz);
    }

    void set(int i, int val) {
        set(i, val, 0, 0, sz);
    }

    int Query() {
        return seg[0].ans;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int &i: arr) cin >> i;
    segmentTree s;
    s.built(arr);
    for (int i = 0; i < n; ++i) {
        s.set(i, m);
        cout << s.Query() << ' ';
        s.set(i, arr[i]);
    }
}

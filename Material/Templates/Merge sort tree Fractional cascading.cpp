#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()


struct node {
    int l, r, *lp, *rp;
    node *L, *R;
    vector<int> val;

    node(int l, int r, int a[]) : l(l), r(r) {
        if (l == r) {
            L = R = nullptr;
            val = {a[l]};
            return;
        }
        L = new node(l, (l + r) / 2, a);
        R = new node((l + r) / 2 + 1, r, a);
        int n = L->r - L->l + 1;
        int m = R->r - R->l + 1;
        val.reserve(n + m);
        val.resize(n + m);
        lp = new int[n + m + 1];
        rp = new int[n + m + 1];
        int i = 0, j = 0;
        while (i < n || j < m) {
            lp[i + j] = i;
            rp[i + j] = j;
            if (j == m || (i != n && L->val[i] < R->val[j])) {
                val[i + j] = L->val[i];
                ++i;
            } else {
                val[i + j] = R->val[j];
                ++j;
            }
        }
        lp[n + m] = n;
        rp[n + m] = m;
    }

    /// number of elements less than or equal to x
    int get(int lq, int rq, int x, int p = -1) {
        if (~!p)
            p = upper_bound(all(val), x) - val.begin();
        if (lq <= l && rq >= r)
            return p;
        if (rq < l || lq > r)
            return 0;
        return L->get(lq, rq, x, lp[p]) + R->get(lq, rq, x, rp[p]);
    }
};


struct SegmentTree {
private:
    struct data {
        int val, lp, rp;

        data() {}

        data(int val) : val(val), lp(0), rp(0) {}

        data(int val, int lp, int rp) : val(val), lp(lp), rp(rp) {}

        bool operator<(const data &x) const {
            return val < x.val;
        }
    };

    vector<vector<data>> seg;
    int sz;

    void merge(int x) {
        int n = seg[x * 2 + 1].size(), m = seg[x * 2 + 2].size();
        seg[x].reserve(n + m + 1);
        seg[x].resize(n + m);
        int i = 0, j = 0;
        while (i < n or j < m) {
            seg[x][i + j].lp = i;
            seg[x][i + j].rp = j;
            if (i < n and (j == m or seg[x * 2 + 1][i].val < seg[x * 2 + 2][j].val)) {
                seg[x][i + j].val = seg[x * 2 + 1][i].val;
                ++i;
            } else {
                seg[x][i + j].val = seg[x * 2 + 2][j].val;
                ++j;
            }
        }
        seg[x][n + m].lp = n, seg[x][n + m].rp = m;
    }

    void built(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                seg[x] = {data(arr[lx])};
            return;
        }
        int m = (rx + lx) >> 1;
        built(arr, x * 2 + 1, lx, m);
        built(arr, x * 2 + 2, m, rx);
        merge(x);
    }

    int query(int l, int r, int v, int x, int lx, int rx, int pos) {
        if (pos == -1)
            pos = upper_bound(seg[x].begin(), seg[x].end(), data(v)) - seg[x].begin();
        if (r <= lx or rx <= l)return 0;
        if (l <= lx and rx <= r)return pos;
        int m = (rx + lx) >> 1;
        return query(l, r, v, x * 2 + 1, lx, m, seg[x][pos].lp) +
               query(l, r, v, x * 2 + 2, m, rx, seg[x][pos].rp);
    }

public:

    void built(vector<int> &arr) {
        sz = 1;
        while (sz < arr.size())sz <<= 1;
        seg = vector<vector<data>>(sz << 1);
        built(arr, 0, 0, sz);
    }

    int query(int l, int r, int val) {
        return query(l, r, val, 0, 0, sz, -1);
    }

};


int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n);
    for (int &i: a)scanf("%d", &i);
    SegmentTree seg;
    seg.built(a);
    //node *t = new node(0, n - 1, a);
    while (q--) {
        int l, r, x, s = -1e9, e = 1e9, md, ans;
        scanf("%d%d%d", &l, &r, &x);
        --l;
        while (s <= e) {
            md = (e - s) / 2 + s;
            int xx = seg.query(l, r, md); // t->get(l, r, md);
            if (xx >= x)
                ans = md, e = md - 1;
            else
                s = md + 1;
        }
        printf("%d\n", ans);
    }

  
    
    

}

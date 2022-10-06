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
        if (!~p)
            p = upper_bound(all(val), x) - val.begin();
        if (lq <= l && rq >= r)
            return p;
        if (rq < l || lq > r)
            return 0;
        return L->get(lq, rq, x, lp[p]) + R->get(lq, rq, x, rp[p]);
    }
};


int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int a[n];
    for (int &i: a)scanf("%d", &i);
    node *t = new node(0, n - 1, a);
    while (q--) {
        int l, r, x, s = -1e9, e = 1e9, md, ans;
        scanf("%d%d%d", &l, &r, &x);
        --l, --r;
        while (s <= e) { /// search for the x-th element
            md = (e - s) / 2 + s;
            int xx = t->get(l, r, md);
            if (xx >= x)
                ans = md, e = md - 1;
            else
                s = md + 1;
        }
        printf("%d\n", ans);
    }
}

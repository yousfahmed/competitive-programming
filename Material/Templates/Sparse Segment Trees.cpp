/*
 * https://usaco.guide/plat/sparse-segtree?lang=cpp
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#define FOR(i, x, y) for (int i = x; i < y; i++)
typedef long long ll;
using namespace std;

struct Node {
    int sum, lazy, tl, tr, l, r;

    Node() : sum(0), lazy(0), l(-1), r(-1) {}
};

const int MAXN = 123456;
Node segtree[64 * MAXN];
int cnt = 2;

void push_lazy(int node) {
    if (segtree[node].lazy) {
        segtree[node].sum = segtree[node].tr - segtree[node].tl + 1;
        int mid = (segtree[node].tl + segtree[node].tr) / 2;
        if (segtree[node].l == -1) {
            segtree[node].l = cnt++;
            segtree[segtree[node].l].tl = segtree[node].tl;
            segtree[segtree[node].l].tr = mid;
        }
        if (segtree[node].r == -1) {
            segtree[node].r = cnt++;
            segtree[segtree[node].r].tl = mid + 1;
            segtree[segtree[node].r].tr = segtree[node].tr;
        }
        segtree[segtree[node].l].lazy = segtree[segtree[node].r].lazy = 1;
        segtree[node].lazy = 0;
    }
}

void update(int node, int l, int r) {
    push_lazy(node);
    if (l == segtree[node].tl && r == segtree[node].tr) {
        segtree[node].lazy = 1;
        push_lazy(node);
    } else {
        int mid = (segtree[node].tl + segtree[node].tr) / 2;
        if (segtree[node].l == -1) {
            segtree[node].l = cnt++;
            segtree[segtree[node].l].tl = segtree[node].tl;
            segtree[segtree[node].l].tr = mid;
        }
        if (segtree[node].r == -1) {
            segtree[node].r = cnt++;
            segtree[segtree[node].r].tl = mid + 1;
            segtree[segtree[node].r].tr = segtree[node].tr;
        }

        if (l > mid) update(segtree[node].r, l, r);
        else if (r <= mid) update(segtree[node].l, l, r);
        else {
            update(segtree[node].l, l, mid);
            update(segtree[node].r, mid + 1, r);
        }

        push_lazy(segtree[node].l);
        push_lazy(segtree[node].r);
        segtree[node].sum = segtree[segtree[node].l].sum + segtree[segtree[node].r].sum;
    }
}

int query(int node, int l, int r) {
    push_lazy(node);
    if (l == segtree[node].tl && r == segtree[node].tr) return segtree[node].sum;
    else {
        int mid = (segtree[node].tl + segtree[node].tr) / 2;
        if (segtree[node].l == -1) {
            segtree[node].l = cnt++;
            segtree[segtree[node].l].tl = segtree[node].tl;
            segtree[segtree[node].l].tr = mid;
        }
        if (segtree[node].r == -1) {
            segtree[node].r = cnt++;
            segtree[segtree[node].r].tl = mid + 1;
            segtree[segtree[node].r].tr = segtree[node].tr;
        }

        if (l > mid) return query(segtree[node].r, l, r);
        else if (r <= mid) return query(segtree[node].l, l, r);
        else return query(segtree[node].l, l, mid) + query(segtree[node].r, mid + 1, r);
    }
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;

    segtree[1].sum = 0;
    segtree[1].lazy = 0;
    segtree[1].tl = 1;
    segtree[1].tr = 1e9;

    int c = 0;
    FOR(_, 0, m) {
        int d, x, y;
        cin >> d >> x >> y;
        if (d == 1) {
            c = query(1, x + c, y + c);
            cout << c << '\n';
        } else update(1, x + c, y + c);
    }
    return 0;
}

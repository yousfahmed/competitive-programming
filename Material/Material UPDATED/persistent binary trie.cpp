#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
//#define int long long
ll pw1[50], pw2[50];

struct node {
    node *l, *r;
    ll h;

    node() : l(nullptr), r(nullptr), h(0) {}

    node(node *l, node *r, int lvl) {
        this->l = this->r = nullptr, h = 0;
        if (l) this->l = l, h = pw1[lvl] * l->h;
        if (r) this->r = r, h += pw2[lvl] * r->h;
    }

    node(ll val) {
        l = r = nullptr;
        h = ((ll) (1e9 + 345) ^ val) * (3 * val + 654);
    }

};

node *update(int val, node *x, int lvl) {
    if (!~lvl) {
        if (x)return nullptr;
        return new node(val);
    }
    if (val & (1 << lvl)) {
        return new node(
                x ? x->l : nullptr,
                update(val, x ? x->r : nullptr, lvl - 1),
                lvl + 1
        );
    }
    return new node(
            update(val, x ? x->l : nullptr, lvl - 1),
            x ? x->r : nullptr,
            lvl + 1
    );
}

int query(node *l, node *r, int msk, int lvl) {
    if ((l ? l->h : 0) == (r ? r->h : 0)) return -1;
    if (!~lvl) return msk;
    int lf = query(l ? l->l : l, r ? r->l : r, msk, lvl - 1);
    if (~lf) return lf;
    return query(l ? l->r : l, r ? r->r : r, msk | (1 << lvl), lvl - 1);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < 32; ++i) {
        pw1[i] = pw1[i - 1] * 31;
        pw2[i] = pw2[i - 1] * 53;
    }
    int n;
    cin >> n;
    int arr[n];
    map<int, int> valToI, idxToV;
    for (int &i: arr)cin >> i, valToI[i];
    int id = 0;
    for (auto &[i, v]: valToI)
        v = id++, idxToV[v] = i;
    vector<node *> roots(n + 1);
    roots[0] = new node();
    for (int i = 0; i < n; ++i) {
        arr[i] = valToI[arr[i]];
        roots[i + 1] = update(arr[i], roots[i], 18);
    }
    ll q, res = 0;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        ll l = res ^ a, r = res ^ b;
        res = idxToV[query(roots[l - 1], roots[r], 0, 18)];
        cout << res << '\n';
    }

}

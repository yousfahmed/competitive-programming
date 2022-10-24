struct node {
    node *l, *r;
    int v, lazy;

    node() : v(0), lazy(0), l(nullptr), r(nullptr) {}

    node(int v) : v(v), lazy(0), l(nullptr), r(nullptr) {}

    node(node *l, node *r) {
        this->l = l, this->r = r, lazy = 0, v = 0;
        if (l)v += l->v;
        if (r)v += r->v;
    }

    node(node *x) {
        l = x->l;
        r = x->r;
        v = x->v;
        lazy = x->lazy;
    }

    node(node *x, int add_lazy) {
        l = x->l;
        r = x->r;
        v = x->v;
        lazy = x->lazy + add_lazy;
    }

};


node *built(vector<int> &a, int lx, int rx) {
    if (rx - lx == 1) {
        node *ret = new node();
        if (lx < a.size())ret->v = a[lx];
        return ret;
    }
    int m = (rx + lx) >> 1;
    return new node(
            built(a, lx, m),
            built(a, m, rx)
    );
}

void propagate(node *x, int lx, int rx) {
    if (x->lazy) {
        if (rx - lx > 1) {
            x->l = new node(x->l);
            x->r = new node(x->r);
            x->l->lazy += x->lazy;
            x->r->lazy += x->lazy;
        }
        //// add x to all numbers if a gavien range
        x->v += x->lazy * (rx - lx); //////TODO
        x->lazy = 0;
    }
}

node *update(int l, int r, int v, node *x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l <= lx and rx <= r) {
        node *ret = new node(x, v);
        propagate(ret, lx, rx);
        return ret;
    }
    if (r <= lx or rx <= l)return x;
    int m = (rx + lx) >> 1;
    return new node(
            update(l, r, v, x->l, lx, m),
            update(l, r, v, x->r, m, rx)
    );
}

int query(int l, int r, node *x, int lx, int rx) {
    if (r <= lx or rx <= l)return 0;
    propagate(x, lx, rx);
    if (l <= lx and rx <= r)return x->v;
    int m = (rx + lx) >> 1;
    return query(l, r, x->l, lx, m) + //// TODO
           query(l, r, x->r, m, rx);
}

node *roots[(int) 1e5 + 4];

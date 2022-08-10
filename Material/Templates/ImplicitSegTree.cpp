struct ImplicitSegTree {
private:
    Node *root;
    int sz;

    void update(int l, int r, ll val, Node *x, int lx, int rx) {
        if (lx > rx || r < lx || l > rx)
            return;

        if (l <= lx && rx <= r) {
            x->sum += val;
            return;
        }

        int mid = (lx + rx) >> 1;

        if (x->l == nullptr)
            x->l = new Node();

        if (x->r == nullptr)
            x->r = new Node();

        update(l, r, val, x->l, lx, mid);
        update(l, r, val, x->r, mid + 1, rx);
    }

    ll query(int i, Node *x, int l, int r) {

        if (x == nullptr) /// no node
            return 0;

        if (l > r || i < l || i > r)
            return 0;

        if (l == r)
            return x->sum;

        int mid = (l + r) >> 1;

        return x->sum + query(i, x->l, l, mid) + query(i, x->r, mid + 1, r);
    }

public:
    ImplicitSegTree(int n) {
        root = new Node();
        sz = n;
    }

    int query(int i) {
        return query(i, root, 0, sz - 1);
    }

    void update(int l, int r, int val) {
        update(l, r, val, root, 0, sz - 1);
    }
};

typedef long long ll;

struct Node {
    ll sum;
    Node *l, *r;

    Node() : sum(0), l(nullptr), r(nullptr) {}
};

struct ImplicitSegTree {
private:
    Node *root;
    int sz;


    void update(int l, int r, ll val, Node *x, int lx, int rx) {
        if (lx > rx || r < lx || l > rx)
            return;

        if (lx == rx) { /// TODO

        }


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

    ll query(int l, int r, Node *x, int lx, int rx) {

        if (x == nullptr)
            return 0;

        if (lx > rx)return 0;

        if (r < lx || rx < l)
            return 0;

        if (l <= lx and rx <= r)
            return x->sum;

        int mid = (lx + rx) >> 1;

        return x->sum + query(l, r, x->l, lx, mid) + query(l, r, x->r, mid + 1, rx);
    }

public:
    ImplicitSegTree(int n) {
        root = new Node();
        sz = n;
    }

    ll query(int l, int r) {
        return query(l, r, root, 0, sz - 1);
    }


    void update(int l, int r, int val) {
        update(l, r, val, root, 0, sz - 1);
    }
};

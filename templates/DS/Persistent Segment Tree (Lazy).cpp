#define ll long long

struct node {
  node *l, *r;
  int v, lazy;

  node() : v(0), lazy(0), l(nullptr), r(nullptr) {}

  node(int v) : node() { this->v = v; }

  node(node *l, node *r) {
    this->l = l, this->r = r, lazy = v = 0;
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

namespace PSegTree {
#define md ((lx+rx)>>1)

  node *build(vector<int> &a, int lx, int rx) {
    if (lx == rx) return new node(a[lx]);
    return new node(build(a, lx, md), build(a, md + 1, rx));
  }

  void propagate(node *x, int lx, int rx) {
    if (!x->lazy)return;
    if (lx != rx) {
      x->l = new node(x->l);
      x->r = new node(x->r);
      x->l->lazy += x->lazy;
      x->r->lazy += x->lazy;
    }
    //// Add x->lazy to all numbers in the given range
    x->v += x->lazy * (rx - lx + 1); //////TODO
    x->lazy = 0;
  }

  node *update(int l, int r, int v, node *x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l <= lx and rx <= r) {
      node *ret = new node(x, v);
      propagate(ret, lx, rx);
      return ret;
    }
    if (r < lx or rx < l)return x;
    return new node(
        update(l, r, v, x->l, lx, md),
        update(l, r, v, x->r, md + 1, rx)
    );
  }

  int query(int l, int r, node *x, int lx, int rx) {
    if (r < lx or rx < l)return 0;
    propagate(x, lx, rx);
    if (l <= lx and rx <= r)return x->v;
    return query(l, r, x->l, lx, md) + //// TODO
           query(l, r, x->r, md + 1, rx);
  }

#undef md
}

vector<node *> roots;

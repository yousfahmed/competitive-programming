// need testing

struct Node {
  int val;
  Node *l, *r;

  Node(int x) : val(x), l(nullptr), r(nullptr) {}

  Node(Node *ll, Node *rr) {
    l = ll, r = rr;
    val = 0;
    if (l) val += l->val;
    if (r) val += r->val;
  }

  Node(Node *cp) : val(cp->val), l(cp->l), r(cp->r) {}
};

int n;
vector<Node *> roots;
vector<int> a;
#define md ((lx+rx)>>1)

Node *build(int lx = 0, int rx = n - 1) {
  if (lx == rx) {
    return new Node(a[lx]);
  }
  return new Node(build(lx, md), build(md + 1 + 1, rx));
}

Node *update(Node *node, int val, int pos, int lx = 0, int rx = n - 1) {
  if (lx == rx) {
    return new Node(val);
  }
  if (pos > md) {
    return new Node(node->l, update(node->r, val, pos, md + 1, rx));
  }
  return new Node(update(node->l, val, pos, lx, md), node->r);
}

int query(Node *node, int l, int r, int lx = 0, int rx = n - 1) {
  if (r < lx || rx < l) {
    return 0;
  }
  if (l <= lx && rx <= r) {
    return node->val;
  }
  return query(node->l, l, r, lx, md) + query(node->r, l, r, md + 1, rx);
}

#undef md
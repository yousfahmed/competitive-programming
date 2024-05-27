struct lazy_node {
  int n, a, d;

  int sum() {
    int an = a + (d * (n - 1));
    return ((a + an) * n) >> 1;
  }

  void merge(const lazy_node &to_add) {
    a += to_add.a;
    d += to_add.d;
  }
};

struct segtree {
#define md ((lx+rx)>>1)
#define LF (x<<1)
#define RT ((x<<1)|1)
  vector<int> seg;
  vector<lazy_node> lazy;
  vector<bool> lazy_status;
  int sz;

  void build(int x, int lx, int rx) {
    seg[x] = 0;
    lazy_status[x] = 0;
    lazy[x] = {rx - lx + 1, 0, 0};
    if (lx == rx)
      return;
    build(LF, lx, md);
    build(RT, md + 1, rx);
  }

  segtree(int n) {
    sz = n;
    seg.resize(4 * n);
    lazy.resize(4 * n);
    lazy_status.resize(4 * n);
    build(1, 0, n - 1);
  }

  int neutral() { return 0; }

  int merge(int a, int b) { return a + b; }

  void propagate(int x, int lx, int rx, lazy_node to_add) {
    seg[x] += to_add.sum();
    if (lx != rx) {
      lazy[LF].merge({md - lx + 1, to_add.a, to_add.d});
      int diff = md + 1 - lx, a = to_add.a, d = to_add.d;
      lazy[RT].merge({rx - md, a + (d * diff), d});
      lazy_status[LF] = 1;
      lazy_status[RT] = 1;
    }
    lazy[x] = {rx - lx + 1, 0, 0};
    lazy_status[x] = 0;
  }

  void update(int l, int r, lazy_node to_add, int x = 1, int lx = 0, int rx = -1) {
    if (rx == -1)rx = sz - 1;
    if (lazy_status[x])
      propagate(x, lx, rx, lazy[x]);
    if (lx > rx || lx > r || rx < l)
      return;
    if (l <= lx && rx <= r) {
      int diff = lx - l, a = to_add.a, d = to_add.d;
      lazy_node curr = {rx - lx + 1, a + (d * diff), d};
      propagate(x, lx, rx, curr);
      return;
    }
    int mid = (lx + rx) >> 1;
    update(l, r, to_add, LF, lx, mid);
    update(l, r, to_add, RT, mid + 1, rx);
    seg[x] = merge(seg[LF], seg[RT]);
  }

  int query(int l, int r, int x = 1, int lx = 0, int rx = -1) {
    if (rx == -1)rx = sz - 1;
    if (lazy_status[x])
      propagate(x, lx, rx, lazy[x]);
    if (r < lx or rx < l)
      return neutral();
    if (l <= lx && rx <= r)
      return seg[x];
    return merge(
        query(l, r, LF, lx, md),
        query(l, r, RT, md + 1, rx)
    );
  }

#undef md
#undef LF
#undef RT
};
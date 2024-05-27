/// need testing 
struct node {
  int val, lp, rp;

  node() {}

  node(int val) : val(val), lp(0), rp(0) {}

  node(int val, int lp, int rp) : val(val), lp(lp), rp(rp) {}

  bool operator<(const node &x) const {
    return val < x.val;
  }
};

struct SegmentTree {
#define md ((lx+rx) >> 1)
#define LF (x*2+1)
#define RT (x*2+2)
private:
  vector<vector<node>> seg;
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

  void build(vector<int> &arr, int x, int lx, int rx) {
    if (rx == lx) {
      seg[x] = {node(arr[lx])};
      return;
    }
    build(arr, LF, lx, md);
    build(arr, RT, md + 1, rx);
    merge(x);
  }

  int query(int l, int r, int v, int x, int lx, int rx, int pos) {
    if (pos == -1) {
      pos = upper_bound(seg[x].begin(), seg[x].end(), node(v)) - seg[x].begin();
    }
    if (r < lx or rx < l)return 0;
    if (l <= lx and rx <= r)return pos;
    return query(l, r, v, LF, lx, md, seg[x][pos].lp) +
           query(l, r, v, RT, md + 1, rx, seg[x][pos].rp);
  }

public:

  void build(vector<int> &arr) {
    sz = arr.size();
    seg.assign(sz * 4, {});
    build(arr, 0, 0, sz - 1);
  }

  int query(int l, int r, int val) {
    return query(l, r, val, 0, 0, sz - 1, -1);
  }

#undef md
#undef LF
#undef RT
};


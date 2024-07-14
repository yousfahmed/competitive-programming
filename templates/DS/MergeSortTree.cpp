#define all(V) V.begin(), V.end()

struct MergeSortTree {
private:
#define md ((lx+rx)>>1)
#define LF (x*2+1)
#define RT (x*2+2)
  vector<vector<int>> seg;
  int sz;

  void build(vector<int> &arr, int x, int lx, int rx) {
    if (rx == lx) {
      seg[x] = {arr[lx]};
      return;
    }
    build(arr, LF, lx, md);
    build(arr, RT, md + 1, rx);
    seg[x].resize(seg[LF].size() + seg[RT].size());
    merge(all(seg[LF]), all(seg[RT]), seg[x].begin());
  }

  int query(int l, int r, int v, int x, int lx, int rx) {
    if (r < lx or rx < l)return 0;
    if (l <= lx and rx <= r) {
      return lower_bound(all(seg[x]), v) - seg[x].begin(); //// TODO
    }
    return query(l, r, v, LF, lx, md) +
           query(l, r, v, RT, md + 1, rx);
  }

public:
  void build(vector<int> &arr) {
    sz = arr.size();
    seg.assign(sz * 4, {});
    build(arr, 0, 0, sz - 1);
  }

  int query(int l, int r, int v) {
    return query(l, r, v, 0, 0, sz - 1);
  }

#undef md
#undef LF
#undef RT
};

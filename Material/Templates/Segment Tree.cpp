
class segmentTree {
private:
    vector<int> seg;
    int sz, ignored;

    int merge(int a, int b) {
        return a + b;
    }

    void built(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size()) seg[x] = arr[lx];
            return;
        }
        int mid = (rx + lx) >> 1;
        built(arr, x * 2 + 1, lx, mid);
        built(arr, x * 2 + 2, mid, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    void set(int i, int val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = val;
            return;
        }

        int mid = (rx + lx) >> 1;
        if (i < mid) set(i, val, x * 2 + 1, lx, mid);
        else set(i, val, x * 2 + 2, mid, rx);
        seg[x] = merge(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or rx <= l) return ignored;
        if (lx >= l and rx <= r)return seg[x];
        int mid = (rx + lx) >> 1;
        return merge(query(l, r, x * 2 + 1, lx, mid), query(l, r, x * 2 + 2, mid, rx));
    }

public:
    segmentTree() : sz(0) {}

    void init(int n) {
        ignored = 0;
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz, 0);
    }

    void built(vector<int> &arr) {
        init(arr.size());
        built(arr, 0, 0, sz);
    }

    void set(int i, int val) {
        set(i, val, 0, 0, sz);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, sz);
    }

};

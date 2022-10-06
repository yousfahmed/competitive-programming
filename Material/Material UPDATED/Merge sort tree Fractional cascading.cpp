struct SegmentTree {
private:
    struct data {
        int val, lp, rp;

        data() {}

        data(int val) : val(val), lp(0), rp(0) {}

        data(int val, int lp, int rp) : val(val), lp(lp), rp(rp) {}

        bool operator<(const data &x) const {
            return val < x.val;
        }
    };

    vector<vector<data>> seg;
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

    void built(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                seg[x] = {data(arr[lx])};
            return;
        }
        int m = (rx + lx) >> 1;
        built(arr, x * 2 + 1, lx, m);
        built(arr, x * 2 + 2, m, rx);
        merge(x);
    }

    int query(int l, int r, int v, int x, int lx, int rx, int pos) {
        if (pos == -1)
            pos = upper_bound(seg[x].begin(), seg[x].end(), data(v)) - seg[x].begin();
        if (r <= lx or rx <= l)return 0;
        if (l <= lx and rx <= r)return pos;
        int m = (rx + lx) >> 1;
        return query(l, r, v, x * 2 + 1, lx, m, seg[x][pos].lp) +
               query(l, r, v, x * 2 + 2, m, rx, seg[x][pos].rp);
    }

public:

    void built(vector<int> &arr) {
        sz = 1;
        while (sz < arr.size())sz <<= 1;
        seg = vector<vector<data>>(sz << 1);
        built(arr, 0, 0, sz);
    }

    int query(int l, int r, int val) {
        return query(l, r, val, 0, 0, sz, -1);
    }

};


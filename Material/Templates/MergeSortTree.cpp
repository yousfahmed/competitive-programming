struct MergeSortTree {
    vector<vector<int>> seg;
    int sz;

    void built(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size()) {
                seg[x].resize(1);
                seg[x][0] = arr[lx];
            }
            return;
        }
        int m = (rx + lx) >> 1;
        built(arr, x * 2 + 1, lx, m);
        built(arr, x * 2 + 2, m, rx);
        seg[x].reserve(seg[x * 2 + 1].size() + seg[x * 2 + 2].size());
        merge(seg[x * 2 + 1].begin(), seg[x * 2 + 1].end(),
              seg[x * 2 + 2].begin(), seg[x * 2 + 2].end(),
              back_inserter(seg[x])
        );
    }

    void built(vector<int> &arr) {
        sz = 1;
        while (sz < sz(arr)) sz <<= 1;
        seg.resize(sz << 1);
        built(arr, 0, 0, sz);
    }

    int query(int l, int r, int v, int x, int lx, int rx) {
        if (r <= lx or rx <= l)return 0;
        if (l <= lx and rx <= r)
            return lower_bound(all(seg[x]), v) - seg[x].begin(); //// TODO
        int m = (rx + lx) >> 1;
        return query(l, r, v, x * 2 + 1, lx, m) +
               query(l, r, v, x * 2 + 2, m, rx);
    }

    int query(int l, int r, int v) {
        return query(l, r, v, 0, 0, sz);
    }

};

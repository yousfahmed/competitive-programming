/// from L to R ... count how many number strictly less than X
struct query {
    int l, r, val;

    bool operator<(const query &b) const {
        return (val != b.val ? val < b.val : l > b.l);
    }
};

struct BIT {
private:
    int *bit;

public:
    BIT(int n) {
        n += 7;
        bit = new int[n];
        memset(bit, 0, n * sizeof bit[0]);
    }

    int query(int i) {
        int ret = 0;
        i++;
        while (i > 0) {
            ret += bit[i];
            i -= (i & -i);
        }
        return ret;
    }

    void update(int v) {
        v++;
        while (v < N) {
            bit[v]++;
            v += (v & -v);
        }
    }

};

void MOs(int ret[], vector<query> queries, int n) { /// TODO mark the array element as l=-1 ,r = idx , val = arr[i]
    sort(all(queries));
    BIT bt(n);
    for (query &q: queries) {
        if (!~q.l)
            bt.update(q.r);
        else {
            int cnt = bt.query(q.r) - bt.query(q.l - 1) - 1;
            ret[q.l] = cnt;
        }
    }
}

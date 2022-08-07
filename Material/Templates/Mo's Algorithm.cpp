int SQ; /// SQ = ceil(sqrt(n))
int res; /// answer for each query

struct Query {
    int l, r, bidx, i;

    Query() {}

    Query(int l, int r, int i) : l(l), r(r), i(i), bidx(l / SQ) {}

    bool operator<(const Query &q) const {
        return bidx != q.bidx ? bidx < q.bidx : r < q.r;
    }
};

int freq[100000 + 9];

void add(int p) {
    ++freq[p];
}

void remove(int p) {
    --freq[p];
}

vector<int> MOs(vector<Query> &queries) {
    vector<int> ret(queries.size());
    sort(queries.begin(), queries.end());
    int l = 1, r = 0;
    for (auto q: queries) {
        while (l < q.l) remove(l++);
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (r > q.r) remove(r--);
        ret[q.i] = res;
    }
    return ret;
}

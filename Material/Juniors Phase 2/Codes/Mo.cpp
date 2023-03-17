#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int arr[N], ret[N];
int SQ, cur;

struct Query {
    int l, r, i, b;

    Query() {}

    Query(int l, int r, int i) : l(l), r(r), i(i), b(l / SQ) {}

    bool operator<(const Query &x) const {
        //// division is much slower than other arithmetical operations
        ///return make_pair(l / SQ, r) < make_pair(x.l / SQ, x.r);

        return b != x.b ? b < x.b : r < x.r;
    }
};

void add(int i) {
    cur += arr[i];
}

void remove(int i) {
    cur -= arr[i];
}

void solve(vector<Query> &queries) {
    sort(queries.begin(), queries.end());
    int l = 0, r = 0;
    add(0);
    for (auto &q: queries) { ////  call add() before remove()
        while (r < q.r)
            add(++r);
        while (q.l < l)
            add(--l);
        while (q.r < r)
            remove(r--);
        while (l < q.l)
            remove(l++);
        ret[q.i] = cur;
    }


}

signed main() {
    int n, q;
    cin >> n >> q;

    SQ = ceil(sqrt(n)); //// set the SQ


    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<Query> queris;
    queris.reserve(q); ///// https://cplusplus.com/reference/vector/vector/reserve
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r;
        queris.emplace_back(--l, --r, i); /// zero or 1 based ? 
    }
    solve(queris);
    for (int i = 0; i < q; ++i) {
        cout << ret[i] << '\n';
    }
}

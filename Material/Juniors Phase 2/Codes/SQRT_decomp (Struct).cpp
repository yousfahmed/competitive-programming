#include <bits/stdc++.h>

using namespace std;
#define int long long
const int inf = 1e9 + 1;
int SQ;

struct Block {
    vector<int> arr;
    long long sum;
    int mx, mn;

    Block() : sum(0), mx(-inf), mn(inf) {}

    int operator[](int i) const {
        i %= SQ;
        assert(i < arr.size());
        return arr[i];
    }

    void push(int a) {
        arr.push_back(a);
        mx = max(mx, a);
        mn = min(mn, a);
        sum += a;
    }

    void update(int i, int v) {
        sum += arr[i] - v;
        if (arr[i] == v and v == mx or arr[i] == v and v == mn) {
            arr[i] = v;
            mx = mn = v;
            for (int &x: arr)
                mx = max(mx, x), mn = min(mn, x);
        } else {
            arr[i] = v;
            mn = min(mn, v);
            mx = min(mx, v);
        }
    }
};

vector<Block> block;


Block query(int l, int r) {
    Block b;
    while (l <= r) {
        int i = l / SQ;
        if (l % SQ == 0 and l + SQ <= r) {
            b.mx = max(b.mx, block[i].mx);
            b.mn = min(b.mn, block[i].mn);
            b.sum += block[i].sum;
            l += SQ;
        } else {
            b.mx = max(b.mx, block[i][l]);
            b.mn = min(b.mn, block[i][l]);
            b.sum += block[i][l];
            ++l;
        }
    }
    return b;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    SQ = ceil(sqrt(a.size()));
    block = vector<Block>(SQ);
    for (int i = 0; i < a.size(); ++i)
        block[i / SQ].push(a[i]);
    int t, l, r, i, v;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> i >> v;
             --i;
            block[i / SQ].update(i, v);
        } else if (t == 2) { /// for max
            cin >> l >> r;
            cout << query(--l, --r).mx << '\n';
        } else if (t == 3) { /// for min
            cin >> l >> r;
            cout << query(--l, --r).mn << '\n';
        } else { /// for sum
            cin >> l >> r;
            cout << query(--l, --r).sum << '\n';
        }
    }
}

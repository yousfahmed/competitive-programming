#include <bits/stdc++.h>

using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) (x).begin(),(x).end()
#define double long double
#define int double
int num[5004];

#define t second.first
#define idx second.second
#define p first
#define mp(x, y, z) make_pair(x,make_pair(y,z))

void solve() {
    int n, L;
    cin >> n >> L;
    set<pair<int, pair<int, int>>> l, r;
    for (int i = 0, x, dir; i < n; ++i) {
        cin >> x >> dir;
        if (dir) r.emplace(mp(x, 0, i + 1));
        else l.emplace(mp(x, 0, i + 1));
    }
    vector<pair<int, int>> ans;
    while (l.size() and r.size()) {
        auto x = l.begin();
        auto y = r.lower_bound(mp(x->p, 0, 0));
        if (y == r.begin() or (--y)->p >= x->p) {
            ans.emplace_back((x->p + x->t), x->idx);
            l.erase(x);
        } else {
            int lPos = x->p;
            int rPos = y->p;
            if (x->t < y->t) lPos -= y->t - x->t;
            else if (x->t > y->t) rPos += x->t - y->t;
            assert(lPos >= rPos);
            int mid = (lPos - rPos) / 2;
            r.emplace(mp(lPos - mid, max(x->t, y->t) + mid, x->idx));
            l.emplace(mp(rPos + mid, max(x->t, y->t) + mid, y->idx));
            l.erase(x);
            r.erase(y);
        }
    }
    while (l.size()) {
        auto x = l.begin();
        ans.emplace_back(x->t + x->p, x->idx);
        l.erase(x);
    }
    while (r.size()) {
        auto x = r.begin();
        ans.emplace_back(x->t + (L - x->p), x->idx);
        r.erase(x);
    }

    sort(all(ans));
    for (auto i: ans)
        cout << i.second << ' ';
}


signed main() {
    NeedForSpeed;
    iota(num, num + 5007, 1);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}

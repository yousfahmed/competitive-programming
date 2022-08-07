#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;

vector<int> colors[N], adj[N];
int arr[N];
int tree[N], in[N], out[N], timer;

int *bit, *vis;

void DFS(int u, int p) {
    in[u] = timer;
    tree[timer++] = u;
    for (int &v: adj[u])
        if (v != p) DFS(v, u);
    out[u] = timer;
}

void update(int i, int v) {
    i++;
    while (i < timer) {
        bit[i] += v;
        i += (i & -i);
    }
}

int query(int l, int r) {
    int ret = 0;
    r++;
    while (r > 0) {
        ret += bit[r];
        r -= (r & -r);
    }
    while (l > 0) {
        ret -= bit[l];
        l -= (l & -l);
    }
    return ret;
}

void init() {
    bit = new int[timer + 7];
    vis = new int[timer + 7];
    memset(bit, 0, (timer + 7) << 2);
    memset(vis, 0, (timer + 7) << 2);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }
    vector<pair<int, pair<int, int>>> queries(m); // L , R , query_idx
    DFS(0, 0);
    init();
    for (int i = 0; i < timer; ++i) {
        if (colors[arr[tree[i]]].empty()) {
            update(i, 1);
            vis[i] = 1;
        } else {
            colors[arr[tree[i]]].emplace_back(i);
        }
    }
    for (auto &i: colors)
        reverse(i.begin(), i.end());
    v = 0;
    for (auto &i: queries) {
        cin >> u;
        i.first = in[--u];
        i.second.first = out[u];
        i.second.second = v++;
    }
    sort(queries.begin(), queries.end());
    vector<int> ret(m);
    int l = 0;
    for (auto &q: queries) {
        while (l < q.first) {
            if (vis[l]) {
                update(l, -1);
                if (colors[arr[tree[l]]].size()) {
                    int &nxt = colors[arr[tree[l]]].back();
                    vis[nxt] = 1;
                    update(nxt, 1);
                    colors[arr[tree[l]]].pop_back();
                }
            }
            l++;
        }
        ret[q.second.second] = query(q.first, q.second.first);
    }
    for (int &i: ret) cout << i << ' ';


}

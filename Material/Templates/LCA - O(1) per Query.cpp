#define sz(X) ((int)(X.size()))
struct LCA {
private:
   
    vector<int> in, lvl, euler, LOG;
    vector<vector<pair<int, int>>> table;

    void DFS(vector<vector<int>> &adj, int u, int f, int h) {
        in[u] = sz(euler);
        lvl.emplace_back(h);
        euler.emplace_back(u);
        for (auto &v: adj[u]) {
            if (f == v)continue;
            DFS(adj, v, u, h + 1);
            euler.emplace_back(u);
            lvl.emplace_back(h);
        }
        if (sz(adj[u]) == 1) {
            euler.emplace_back(u);
            lvl.emplace_back(h);
        }
    }

    void builtTable(int n) {
        table.assign(n, vector<pair<int, int>>(ceil(log2(n)) + 7));
        for (int i = 0; i < n; ++i)
            table[i][0] = {lvl[i], euler[i]};
        for (int msk = 1; (1 << msk) <= n; ++msk) {
            for (int j = 0; j + (1 << msk) <= n; ++j) {
                table[j][msk] = min(
                        table[j][msk - 1],
                        table[j + (1 << (msk - 1))][msk - 1]
                );
            }
        }
    }

    void pre(int n) {
        LOG.resize(n);
        LOG[1] = 0;
        for (int i = 2; i < n; ++i)
            LOG[i] = LOG[i / 2] + 1;
    }

public:
    LCA(vector<vector<int>> &adj) {
        in.resize(sz(adj) + 7);
        lvl.reserve(sz(adj) << 1);
        euler.reserve(sz(adj) << 1);
        DFS(adj, 1, -1, 0);
        pre(sz(euler) + 7);
        builtTable(sz(euler));
    }

    int query(int u, int v) {
        u = in[u], v = in[v];
        if (u > v)swap(u, v);
        int msk = LOG[v - u + 1];
        return min(
                table[u][msk],
                table[v - (1 << msk) + 1][msk]
        ).second;
    }

};

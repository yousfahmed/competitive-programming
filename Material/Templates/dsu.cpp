
struct DSU {
private:
    int *par, *save, *sz;
    int cnt, num_comp;
    stack<array<int, 4>> st;

    void rolling_back() {
        auto &t = st.top();
        par[t[0]] = t[1];
        if (~t[2]) {
            num_comp++;
            sz[t[2]] = t[3];
        }
        st.pop();
    }

public:

    void init(int n_v, int n_edges) { /// number of vertices, number of edges
        save = new int[n_edges + 1];
        cnt = 0;
        st = stack<array<int, 4>>();
        num_comp = n_v++;
        par = new int[n_v];
        sz = new int[n_v];
        fill(sz, sz + n_v, 1);
        iota(par, par + n_v, 0);
    }

    int find(int u) {
        if (par[u] == u)return u;
        st.push({u, par[u], -1, -1});
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        save[cnt++] = st.size();
        u = find(u), v = find(v);
        if (u == v)return false;
        if (sz[u] < sz[v])swap(u, v);
        num_comp--;
        st.push({v, par[v], u, sz[u]});
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }

    void rolling_back(int time) { /// roll back to add only the first v edges
        while (cnt > time) {
            int x = save[--cnt];
            while (st.size() > save[x])
                rolling_back();
        }
    }

};

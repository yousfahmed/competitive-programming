const int N = 1e5 + 7;
int arr[N], in[N], out[N], tree[N]; 
vector<int> adj[N];

int flatting(int u, int f) {
    static int cnt = 0;
    tree[cnt] = arr[u];
    in[u] = cnt++;
    for (int &v: adj[u])
        if (v != f)
            flatting(v, u);
    out[u] = cnt;
    return cnt;
}

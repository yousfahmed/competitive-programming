void solve(){
  int n, m;
  cin >> n >> m;
  const int SQ = ceil(sqrt(m));
  vector<pair<int, int>> edges(m);
  for (auto &[u, v]: edges) {
    cin >> u >> v, --u, --v;
  }
  DSU dsu;
  dsu.init(n);
  vector<vector<array<int, 3>>> queries(SQ);
  int q;
  cin >> q;
  int ans[q];
  for (int i = 0, l, r; i < q; ++i) {
    cin >> l >> r;
    --l, --r;
    if (r - l + 1 <= SQ) {
      dsu.snapshot();
      while (l <= r) {
        dsu.merge(edges[l].first, edges[l].second);
        ++l;
      }
      ans[i] = dsu.comp;
      dsu.rollback();
    } else {
      queries[l / SQ].push_back({r, l, i});
    }
  }
  for (auto &x: queries) {
    sort(x.begin(), x.end());
  }
  for (int b = 1; b <= SQ; ++b) {
    if (queries[b - 1].empty())continue;
    dsu.snapshot();
    int R = min(b * SQ, m) - 1;
    dsu.merge(edges[R].first, edges[R].second);
    for (const auto [rq, lq, iq]: queries[b - 1]) {
      while (R < rq) {
        ++R;
        dsu.merge(edges[R].first, edges[R].second);
      }
      dsu.snapshot();
      int L = min(m, b * SQ) - 1;
      while (lq < L) {
        --L;
        dsu.merge(edges[L].first, edges[L].second);
      }
      ans[iq] = dsu.comp;
      dsu.rollback();
    }
    dsu.rollback();
  }
  for (int &x: ans) {
    cout << x << '\n';
  }
}

/// O(n^(5 / 3))
namespace mo {
  struct query {
    int idx, l, r, t;
  };
  struct update {
    int i, prevx, x;
  };
  const int SQ = 3153; // (2 * n) ^ 0.666
  vector<query> queries;
  vector<update> updates;
  vector<int> arr;
  vector<ll> ans;

  bool cmp(const query &x, const query &y) {
    if (x.l / SQ != y.l / SQ)
      return x.l / SQ < y.l / SQ;
    if (x.r / SQ != y.r / SQ)
      return x.r / SQ < y.r / SQ;
    return x.t < y.t;
  }

  void run(const vector<int> &initial_arr) {
    sort(queries.begin(), queries.end(), cmp);
    ans.resize(queries.size());
    arr = initial_arr;
    int l = 0, r = 0, t = 0;
    ll sum = 0;
    auto add = [&](int x) {
      sum += x;
    };
    auto rem = [&](int x) {
      sum -= x;
    };
    add(arr[0]);
    for (const auto &q: queries) {
      while (r < q.r) add(arr[++r]);
      while (l > q.l) add(arr[--l]);
      while (r > q.r) rem(arr[r--]);
      while (l < q.l) rem(arr[l++]);

      while (t > q.t) {
        t--;
        if (q.l <= updates[t].i && q.r >= updates[t].i) {
          rem(updates[t].x);
          add(updates[t].prevx);
        }
        arr[updates[t].i] = updates[t].prevx;
      }
      while (t < q.t) {
        if (q.l <= updates[t].i && q.r >= updates[t].i) {
          rem(updates[t].prevx);
          add(updates[t].x);
        }
        arr[updates[t].i] = updates[t].x;
        t++;
      }
      ans[q.idx] = sum;
    }
  }

  void init(const vector<int> &initial_arr) { arr = initial_arr; }

  void add_query(int l, int r) {
    query cur{};
    cur.l = l;
    cur.r = r;
    cur.idx = queries.size();
    cur.t = updates.size();
    queries.emplace_back(cur);
  }

  void add_update(int idx, int val) {
    mo::update cur{};
    cur.i = idx;
    cur.x = val;
    cur.prevx = arr[idx];
    arr[idx] = val;
    updates.emplace_back(cur);
  }
}

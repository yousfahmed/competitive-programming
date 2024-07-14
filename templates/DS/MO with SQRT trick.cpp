const int SQ, N;
int blk[SQ + 1], frq[N + 1];

struct Query {
  int l, r, iq;

  bool operator<(const Query &other) const {
    return make_pair(l / SQ, r) < make_pair(other.l / SQ, other.r);
  }
};

void update(int val) {
  if (frq[val] == 1) {
    blk[val / SQ] += 1;
  } else if (frq[val] == 0) {
    blk[val / SQ] -= 1;
  }
}

void add(int i) {
  i = arr[i];
  frq[i]++;
  update(i);
}

void rem(int i) {
  i = arr[i];
  frq[i]--;
  update(i);
}

int getMax() {
  int idx = SQ - 1;
  while (~idx && !blk[idx])--idx;
  if (idx == -1) return 0; /// empty subarray
  idx = (idx + 1) * SQ - 1;
  while (!frq[idx])--idx;
  return idx;
}

int getMin() {
  int idx = 0;
  while (!blk[idx]) ++idx;
  idx *= SQ;
  while (!frq[idx])++idx;
  return idx;
}

int getMex() {
  int idx = 0;
  while (blk[idx] == SQ) ++idx;
  idx *= SQ;
  while (frq[idx])++idx;
  return idx;
}

vector<int> MO(vector<Query> &queries) {
  sort(queries.begin(), queries.end());
  vector<int> res(queries.size());
  int l = queries[0].l, r = queries[0].l;
  add(l);
  for (const auto &[lq, rq, iq]: queries) {
    while (r < rq) add(++r);
    while (l > lq) add(--l);
    while (r > rq) rem(r--);
    while (l < lq) rem(l++);
    res[iq] = getMex();
  }
  return res;
}

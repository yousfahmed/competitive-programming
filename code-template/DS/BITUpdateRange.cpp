struct BIT {
private:
  int n;
  vector<int> B1, B2;

  void add(vector<int> &b, int idx, int x) {
    ++idx;
    while (idx <= n) {
      b[idx] += x;
      idx += idx & -idx;
    }
  }

  int sum(vector<int> &b, int idx) {
    idx++;
    int total = 0;
    while (idx > 0) {
      total += b[idx];
      idx -= idx & -idx;
    }
    return total;
  }

  int prefix(int idx) {
    return sum(B1, idx) * idx - sum(B2, idx);
  }

public:

  BIT(int n) : n(n) {
    B1.assign(n + 1, {});
    B2.assign(n + 1, {});
  }

  void update(int l, int r, int x) {
    add(B1, l, x);
    add(B1, r + 1, -x);
    add(B2, l, x * (l - 1));
    add(B2, r + 1, -x * r);
  }

  int query(int i) {
    return prefix(i) - prefix(i - 1);
  }

  int query(int l, int r) {
    return prefix(r) - prefix(l - 1);
  }

};
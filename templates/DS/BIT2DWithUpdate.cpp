#define vi vector<ll>
#define vvi vector<vi>
#define vvvi vector<vvi>

struct BIT2D {
private:
  vvvi M, A;

  void upd2(vvvi &t, int x, int y, ll mul, ll add) {
    for (int i = x; i < t.size(); i += i & -i) {
      for (int j = y; j < t[0].size(); j += j & -j) {
        t[i][j][0] += mul;
        t[i][j][1] += add;
      }
    }
  }

  void upd1(int x, int y1, int y2, ll mul, ll add) {
    upd2(M, x, y1, mul, -mul * (y1 - 1));
    upd2(M, x, y2, -mul, mul * y2);
    upd2(A, x, y1, add, -add * (y1 - 1));
    upd2(A, x, y2, -add, add * y2);
  }


  ll query2(vvvi &t, int x, int y) {
    ll mul = 0, add = 0;
    for (int i = y; i > 0; i -= i & -i) {
      mul += t[x][i][0];
      add += t[x][i][1];
    }
    return mul * y + add;
  }

  ll query1(int x, int y) {
    ll mul = 0, add = 0;
    for (int i = x; i > 0; i -= i & -i) {
      mul += query2(M, i, y);
      add += query2(A, i, y);
    }
    return mul * x + add;
  }

public:
  BIT2D(int n, int m) {
    M.assign(n + 1, vvi(m + 1, vi(2, 0)));
    A = M;
  }

  ll query(int x1, int y1, int x2, int y2) {
    return query1(x2, y2) -
           query1(x1 - 1, y2) -
           query1(x2, y1 - 1) +
           query1(x1 - 1, y1 - 1);
  }

  void update(int x1, int y1, int x2, int y2, ll val) {
    upd1(x1, y1, y2, val, -val * (x1 - 1));
    upd1(x2, y1, y2, -val, val * x2);
  }

};

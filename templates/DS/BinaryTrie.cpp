struct node {
  int ch[2]{}, sz = 0;

  int &operator[](int x) {
    return ch[x];
  }
};

template<int M = 30>
struct BT {
  vector<node> nodes;

  int newNode() { return nodes.emplace_back(), nodes.size() - 1; }

  void init() { nodes.clear(), newNode(); }

  BT() { init(); }

  /// +1 to add, -1 to delete
  void update(ll val, int op) {
    int u = 0;
    for (int i = M - 1; i >= 0; --i) {
      int v = val >> i & 1;
      if (!nodes[u][v]) {
        nodes[u][v] = newNode();
      }
      u = nodes[u][v];
      nodes[u].sz += op;
    }
  }

  /// Count the number of integers such that a[i] XOR num >= l
  ll query(ll num, ll l) {
    int u = 0;
    ll ans = 0;
    for (int i = M - 1; i >= 0; i--) {
      int btP = num >> i & 1, btL = l >> i & 1;
      if (btL) {
        u = nodes[u][!btP];
      } else {
        ans += nodes[nodes[u][!btP]].sz;
        u = nodes[u][btP];
      }
      if (!u)return ans;
    }
    return ans + nodes[u].sz;
  }

  /// maximum value of a[i] XOR x
  ll query(int x) {
    ll ans = 0;
    int u = 0;
    for (int i = M - 1; i >= 0; --i) {
      int bt = x >> i & 1;
      if (nodes[nodes[u][!bt]].sz) {
        ans |= (1ll << i);
        u = nodes[u][!bt];
      } else {
        u = nodes[u][bt];
      }
    }
    return ans;
  }

};

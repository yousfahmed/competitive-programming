struct node {
  int ch[2]{-1, -1}, frq[2]{}, sz = 0;

  int &operator[](int x) {
    return ch[x];
  }
};

struct BT {
  static const int M = 20;
  vector<node> nodes;

  int newNode() {
    return nodes.emplace_back(), nodes.size() - 1;
  }

  void init() { nodes.clear(), newNode(); }

  BT() { init(); }

  /// +1 to add, -1 to delete
  void update(int val, int op) {
    int u = 0;
    for (int i = M - 1; i >= 0; --i) {
      int v = val >> i & 1;
      if (!~nodes[u][v]) {
        nodes[u][v] = newNode();
      }
      nodes[u].frq[v] += op;
      nodes[u].sz += op;
      u = nodes[u][v];
    }
  }

  /// Helper function to match nodes in the trie
  int match(int x, int y, int dep, int K) {
    if (!~x or !~y or !nodes[x].sz or !nodes[y].sz)
      return 0;
    if (K >> dep & 1) {
      if (dep == 0)
        return 0;
      return match(nodes[x][0], nodes[y][1], dep - 1, K) +
             match(nodes[x][1], nodes[y][0], dep - 1, K);
    } else {
      int n0 = match(nodes[x][0], nodes[y][0], dep - 1, K);
      int n1 = match(nodes[x][1], nodes[y][1], dep - 1, K);
      int l0 = nodes[x].frq[0] - n0, r0 = nodes[y].frq[0] - n0;
      int l1 = nodes[x].frq[1] - n1, r1 = nodes[y].frq[1] - n1;

      int ans = n0 + n1;
      {
        int cc = min(l0, r1);
        ans += cc;
        l0 -= cc;
        r1 -= cc;
      }
      {
        int cc = min(l1, r0);
        ans += cc;
        l1 -= cc;
        r0 -= cc;
      }
      ans += min({n0, l1, r1}) + min({n1, l0, r0});
      return ans;
    }
  }

  /// Maximum subsequence where a[i] XOR a[j] <= k
  int calc(int K, int x = 0, int dep = M - 1) {
    if (x == -1 or !nodes[x].sz) return 0;
    if (K >> dep & 1) {
      return nodes[x].frq[0] + nodes[x].frq[1] - match(nodes[x][0], nodes[x][1], dep - 1, K);
    }
    return max(
        calc(K, nodes[x][0], dep - 1),
        calc(K, nodes[x][1], dep - 1)
    );
  }

  /// Count the number of integers such that a[i] XOR num >= l
  int query(int num, int l) {
    int u = 0, ans = 0;
    for (int i = M - 1; i >= 0; i--) {
      int btP = num >> i & 1;
      int btL = l >> i & 1;
      if (btL) {
        u = nodes[u][!btP];
      } else {
        ans += nodes[u].frq[!btP];
        u = nodes[u][btP];
      }
      if (u == -1)return ans;
    }
    return ans + nodes[u].sz;
  }

  /// Maximum value of a[i] XOR x
  int qusery(int x) {
    int ans = 0, cur = 0;
    for (int i = M - 1; i >= 0 && cur >= 0; --i) {
      int bt = x >> i & 1;
      if (nodes[cur].frq[!bt]) {
        cur = nodes[cur][!bt];
        ans |= (1ll << i);
      } else {
        cur = nodes[cur][bt];
      }
    }
    return ans;
  }

};

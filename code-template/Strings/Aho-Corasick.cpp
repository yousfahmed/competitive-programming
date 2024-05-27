struct Node {
  unordered_map<char, int> ch;
  int fail{}, nxt{}, id = -1;
};

struct Aho {

  static const int ALPHA = 128;
  vector<Node> Trie;

  int addNode() {
    Trie.emplace_back();
    return Trie.size() - 1;
  }

  void init() {
    Trie.clear();
    addNode();
  }

  Aho() { init(); }

  /// If the same string appears before, return its index
  int insert(const string &pat, int ID) {
    int u = 0;
    for (char c: pat) {
      int &nd = Trie[u].ch[c];
      if (!nd) nd = addNode();
      u = nd;
    }
    int &id = Trie[u].id;
    return ~id ? id : (id = ID);
  }

  int nxtF(int u, char c) {
    while (!Trie[u].ch.count(c))
      u = Trie[u].fail;
    u = Trie[u].ch[c];
    return u;
  }

  int Nxt(int u) {
    if (!u) return u;
    int &v = Trie[u].nxt;
    return ~Trie[v].id ? v : v = Nxt(v);
  }

  void computeFail() {
    queue<int> q;
    for (int i = 0; i < ALPHA; i++) {
      int &nd = Trie[0].ch[i];
      if (nd)
        q.push(nd);
    }
    while (q.size()) {
      int u = q.front();
      q.pop();
      int f = Trie[u].fail;
      for (auto [ch, v]: Trie[u].ch) {
        Trie[v].fail = Trie[v].nxt = nxtF(f, ch);
        q.push(v);
      }
    }
  }

  vector<vector<int>> match(string &s, int numPat) {
    vector<vector<int>> ret(numPat);
    int cur = 0, i = 0;
    for (char c: s) {
      cur = nxtF(cur, c);
      for (int p = cur; p; p = Nxt(p)) {
        int &x = Trie[p].id;
        if (~x) ret[x].push_back(i);
      }
      ++i;
    }
    return ret;
  }
    
};
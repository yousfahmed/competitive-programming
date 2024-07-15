struct Node {
  unordered_map<char, int> nxt;
  int isEnd = 0, sz = 0;//subTree size
  int &operator[](char x) {
    return nxt[x];
  }
};

struct Trie {
  vector<Node> tr;

  int newNode() {
    tr.emplace_back();
    return tr.size() - 1;
  }

  Trie() { tr.clear(), newNode(); }

  void insert(const string &s) {
    int u = 0;
    for (char c: s) {
      if (!tr[u][c])
        tr[u][c] = newNode();
      tr[u].sz++;
      u = tr[u][c];
    }
    tr[u].sz++;
    tr[u].isEnd++;
  }

};

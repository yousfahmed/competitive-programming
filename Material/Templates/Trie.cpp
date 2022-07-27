
struct Trie {
private:
    struct Node {
        Node *nxt[26];
        int cnt;
        
        Node() : cnt(0) {}
    } *root;

    void insert(char *ch, Node *cur) {
        if (!(*ch))return;
        if (cur->nxt[(*ch) - 'a'] == nullptr)
            cur->nxt[(*ch) - 'a'] = new Node();
        cur = cur->nxt[(*ch) - 'a'];
        cur->cnt++;
        insert(++ch, cur);
    }

    int count(char *ch, Node *cur) {
        /// count how many strings have that string as a prefix
        if (!(*ch))return cur->cnt;
        if (cur->nxt[(*ch) - 'a'] == nullptr)
            return 0;
        cur = cur->nxt[(*ch) - 'a'];
        return count(++ch, cur);
    }

public:
    Trie() : root(new Node()) {}

    void insert(char *ch) {
        insert(ch, root);
    }

    int count(char *ch) {
        return count(ch, root);
    }
};

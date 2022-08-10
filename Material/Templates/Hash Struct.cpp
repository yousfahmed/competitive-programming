struct hsh {
private:
    long long p1 = 1e9 + 7, p2 = 1e9 + 9;
    int len;

    long long h1, h2, x;
    long long inv1, inv2;
    long long *pw1, *pw2;
    deque<char> q;

    int power(int n, int p, int md) {
        if (!p)return 1;
        long long t = power(n, p / 2, md);
        t = t * t % md;
        if (p & 1) t = t * n % md;
        return t;
    }

public:
    hsh(int sz, int x = 128) : x(x) {
        h1 = h2 = 0;
        len = 0;
        inv1 = power(x, p1 - 2, p1);
        inv2 = power(x, p2 - 2, p2);
        pw1 = new int[sz + 1];
        pw2 = new int[sz + 1];
        pw1[0] = pw2[0] = 1;
        for (int i = 1; i <= sz; ++i) {
            pw1[i] = x * pw1[i - 1] % p1;
            pw2[i] = x * pw2[i - 1] % p2;
        }
    }

    void clear() {
        h1 = h2 = 0;
        len = 0;
        q.clear();
    }

    void push_back(char ch) {
        h1 = (h1 * x) % p1;
        h1 = (h1 + ch) % p1;
        h2 = (h2 * x) % p2;
        h2 = (h2 + ch) % p2;
        len++;
        q.emplace_back(ch);
    }

    void from_string(string &s) {
        for (char i: s)
            push_back(i);
    }

    void pop_front() {
        if (!len)return;
        char ch = q.front();
        q.pop_front();
        len--;
        h1 = ((h1 - ch * pw1[len] % p1) + p1) % p1;
        h2 = ((h2 - ch * pw2[len] % p2) + p2) % p2;
    }

    string get() { return string(q.begin(), q.end()); }

    bool empty() {
        return q.empty();
    }

    void pop_back() {
        if (!len)return;
        char ch = q.back();
        q.pop_back();
        h1 = ((h1 - ch) + p1) % p1;
        h2 = ((h2 - ch) + p2) % p2;
        h1 = h1 * inv1 % p1;
        h2 = h2 * inv2 % p2;
        len--;
    }

    void push_front(int ch) {
        h1 = (h1 + ch * pw1[len] % p1) % p1;
        h2 = (h2 + ch * pw2[len] % p2) % p2;
        len++;
        q.emplace_front(ch);
    }

    bool operator==(const hsh &X) const {
        return (X.h1 == h1 and X.h2 == h2);
    }
};

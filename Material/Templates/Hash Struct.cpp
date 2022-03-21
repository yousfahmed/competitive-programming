#define ll long long
struct hsh {
private:
    ll h1, h2, p1 = 1e9 + 7, p2 = 1e9 + 9, x;
    ll *pw1, *pw2;
    int len;
    deque<int> q;
public:
    hsh(int sz, int x = 128) {
        h1 = h2 = 0;
        len = 0;
        this->x = x;
        pw1 = new ll[sz + 1];
        pw2 = new ll[sz + 1];
        pw1[0] = pw2[0] = 1;
        for (int i = 1; i <= sz; ++i) {
            pw1[i] = pw1[i - 1] * x % p1;
            pw2[i] = pw2[i - 1] * x % p2;
        }
    }

    void push_back(int ch) {
        h1 = (h1 * x % p1 + ch) % p1;
        h2 = (h2 * x % p2 + ch) % p2;
        len++;
        q.emplace_back(ch);
    }

    void from_string(string s) {
        for (int i = 0; i < s.length(); ++i)
            push_back(s[i]);
    }

    void pop_front() {
        h1 = ((h1 - q.front() * pw1[len - 1] % p1) + p1) % p1;
        h2 = ((h2 - q.front() * pw2[len - 1] % p2) + p2) % p2;
        q.pop_front();
        len--;
    }

    string get() { return string(q.begin(), q.end()); }

    ll power(ll X, ll y, ll p) {
        if (y == 0) return 1;
        ll temp = power(X, y / 2, p) % p;
        if (y % 2 == 0)
            return (temp * temp) % p;
        return (((X * temp) % p) * temp) % p;
    }

    void pop_back() {
        int t = q.back();
        q.pop_back();
        h1 = ((h1 - t) + p1) % p1;
        h2 = ((h2 - t) + p2) % p2;
        h1 = h1 * power(x, p1 - 2, p1) % p1;
        h2 = h2 * power(x, p2 - 2, p2) % p2;
        len--;
    }

    void push_front(int ch) {
        h1 = (h1 + ch * pw1[len] % p1) % p1;
        h2 = (h2 + ch * pw2[len] % p2) % p2;
        len++;
        q.emplace_front(ch);
    }

    bool operator==(hsh &X) const {
        return (X.h1 == h1 and X.h2 == h2);
    }

};


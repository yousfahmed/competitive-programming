///mark at i what is the max length of palindrome string start at i - NOT Included the inner palindromic substrings-
vector<int> markPalindromic(const string &s) {
    string t = "#";
    for (auto &ch: s)t.push_back(ch), t.push_back('#');
    int n = t.size();
    vector<int> ans(n);
    int C = 0, R = 0;
    int idx = 0;
    vector<int> ret(s.length(), -1);
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * C - i;
        int rad = (i < R) ? min(ans[mirror], R - i) : 0;
        while (i + 1 + rad < n && i + 1 + rad > -1 && t[i + 1 + rad] == t[i - rad - 1])
            rad++;
        ans[i] = rad;
        if (rad) {
            if (i & 1) {
                rad = (rad - 1) >> 1;
                int l = idx - rad;
                int r = idx + rad;
                ret[l] = max(ret[l], r - l + 1);
            } else {
                rad >>= 1;
                int l = idx - rad;
                int r = idx + rad - 1;
                ret[l] = max(ret[l], r - l + 1);
            }
        }
        if (i & 1)idx++;
        if (i + ans[i] > R) {
            C = i;
            R = i + ans[i];
        }
    }
    return ret;
}

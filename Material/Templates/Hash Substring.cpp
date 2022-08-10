#define fr first
#define sc second

const int B1 = 256, B2 = 128;
const int MOD1 = 2e9 + 11, MOD2 = 1e9 + 7;

const int N = 1e5 + 6;
pair<int, int> prefix[N];
pair<int, int> suffix[N];

int p1[N], p2[N];
int strLen;

void hash_prefix(string &str) {
    int h1 = 0, h2 = 0;
    for (int i = 0; i < str.size(); i++) {
        h1 = (1LL * h1 * B1) % MOD1;
        h1 = (h1 + str[i]) % MOD1;
        h2 = (1LL * h2 * B2) % MOD2;
        h2 = (h2 + str[i]) % MOD2;
        prefix[i] = {h1, h2};
    }
}

void hash_suffix(string &str) {
    int h1 = 0, h2 = 0;
    int sz = str.length();
    for (int i = sz - 1; i >= 0; i--) {
        h1 = (1LL * h1 * B1) % MOD1;
        h1 = (h1 + str[i]) % MOD1;
        h2 = (1LL * h2 * B2) % MOD2;
        h2 = (h2 + str[i]) % MOD2;
        suffix[i] = {h1, h2};
    }
}

void pre() {
    p1[0] = p2[0] = 1;
    for (int i = 1; i < N; ++i) {
        p1[i] = 1LL * p1[i - 1] * B1 % MOD1;
        p2[i] = 1LL * p2[i - 1] * B2 % MOD2;
    }
}

pair<int, int> getSuffix(int l, int r) {
    auto ret = suffix[l];
    int len = r - l + 1;
    r++;
    if (r < strLen) {

        ret.fr -= 1LL * suffix[r].fr * p1[len] % MOD1;
        if (ret.fr < 0)ret.fr += MOD1;

        ret.sc -= 1LL * suffix[r].sc * p2[len] % MOD2;
        if (ret.sc < 0)ret.sc += MOD2;

    }
    return ret;
}


pair<int, int> getPrefix(int r, int l) {
    auto ret = prefix[r];
    int sz = r - l + 1;
    l--;
    if (l >= 0) {
        
        ret.fr -= 1LL * prefix[l].fr * p1[sz] % MOD1;
        if (ret.fr < 0)ret.fr += MOD1;
        
        ret.sc -= 1LL * prefix[l].sc * p2[sz] % MOD2;
        if (ret.sc < 0)ret.sc += MOD2;
    }
    return ret;
}

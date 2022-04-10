#include <bits/stdc++.h>

const int N = 1e6 + 7;
char str[N];
int KMP[N], Z[N];

void builtKMP() {
    int idx = 0;
    for (int i = 1; str[i]; ++i) {
        while (idx and str[idx] != str[i]) idx = KMP[idx - 1];
        if (str[idx] == str[i])idx++;
        KMP[i] = idx;
    }
}

void builtZ() {
    int l = 0, r = 0;
    for (int i = 1; str[i]; ++i) {
        if (i >= r or i + Z[i - l] >= r) {
            l = i;
            r = std::max(r, i);
            while (str[r] and str[r] == str[r - l])r++;
            Z[i] = r - l;
        } else
            Z[i] = Z[i - l];
    }
}


signed main() {

}


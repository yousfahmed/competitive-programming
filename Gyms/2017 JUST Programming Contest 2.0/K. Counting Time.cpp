/*
   Author : Abdelaleem Ahmed
   Codeforces Handle  : [Abdelaleem](https://codeforces.com/profile/Abdelaleem)
   Link To problem : https://codeforces.com/gym/101343/problem/K
*/
#include <bits/stdc++.h>

using namespace std;
int g[3][3];
int a[3][3];

void get(const int x[]) {
    for (int i = 0; i < 9; ++i)
        g[i % 3][i / 3] = x[i];
}

const vector<pair<int, int>> adj = {
        {-1, -1},
        {-1, 0},
        {-1, +1},
        {0,  +1},
        {+1, +1},
        {+1, 0},
        {+1, -1},
        {0,  -1}
};

bool in(int i, int j) {
    return i >= 0 and i < 3 and j >= 0 and j < 3;
}

bool prolog() {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (g[i][j] == 1)continue;
            bool f = false;
            for (auto k: adj) {
                int x = i + k.first, y = j + k.second;
                if (in(x, y) and g[x][y] == g[i][j] - 1) {
                    f = true;
                    break;
                }
            }
            if (!f)return f;
        }
    }
    return true;
}

bool isOkay() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (a[i][j] and a[i][j] != g[i][j])
                return false;

    return prolog();
}


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i: a) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; ++j) i[j] = s[j] - '0';
    }
    int cnt = 0;
    do {
        get(arr);
        cnt += isOkay();
    } while (next_permutation(arr, arr + 9));
    cout << cnt;
}

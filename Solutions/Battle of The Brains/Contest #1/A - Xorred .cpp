#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> pref(n + 1);
    vector<int> cur(30);
    pref[0] = cur;
    vector<int> a(n + 1);
    int Xor{};
    map<int, vector<int>> mp;
    mp[0].emplace_back(0);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      Xor ^= a[i];
      mp[Xor].emplace_back(i);
      for (int j = 0; j < 30; ++j) {
        if (a[i] >> j & 1) {
          cur[j]++;
        }
      }
      pref[i] = cur;
    }

    auto andRange = [&](int l, int r) {
      auto cur = pref[r];
      if (l > 1) {
        for (int i = 0; i < 30; ++i) cur[i] -= pref[l - 1][i];
      }
      int res{};
      for (int i = 0; i < 30; ++i) {
        if (cur[i] == r - l + 1) {
          res |= 1 << i;
        }
      }
      return res;
    };

    auto countXor = [&](int l, int r, int val) -> int {
      if (r < l)return 0;
      if (!mp.count(val))return 0;
      auto &v = mp[val];
      return upper_bound(v.begin(), v.end(), r) -
             lower_bound(v.begin(), v.end(), l);
    };

    Xor = 0;
    int ans{};
    for (int i = 1; i <= n; ++i) {
      int curAnd = a[i];
      Xor ^= a[i];
      int l = i;
      while (l > 0) {
        int s = 1, e = l, md, L;
        while (s <= e) {
          md = (e + s) / 2;
          if (andRange(md, i) == curAnd) {
            L = md, e = md - 1;
          } else {
            s = md + 1;
          }
        }

        int needToDelete = Xor ^ curAnd;
        int v = countXor(L - 1, l - 1, needToDelete);
        ans += v;
        l = L - 1;
        curAnd &= a[l];
      }
    }
    cout << ans << '\n';
  }
}


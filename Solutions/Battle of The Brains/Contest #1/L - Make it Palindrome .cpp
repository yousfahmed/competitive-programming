#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int res = 0;
  map<int, vector<int>> mp;
  vector<int> calc(n + 1);
  for (int i = 1; i <= n; ++i) {
    calc[i] = i / 2;
  }
  partial_sum(calc.begin(), calc.end(), calc.begin());
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    res += calc[n - i];
    mp[x].emplace_back(i);
  }
  for (auto &[_, arr]: mp) {
    int sum = 0, cnt = 0;
    multiset<int> sz;
    for (int i: arr) {
      int x = n - i;
      while (sz.size() && *sz.rbegin() >= x) {
        sum -= *sz.rbegin();
        ++cnt;
        sz.erase(--sz.end());
      }
      res -= sum + cnt * x;
      sz.insert(i + 1);
      sum += i + 1;
    }
  }
  cout << res;
}


#include <bits/stdc++.h>

#define int long long
using namespace std;
const int mod = 1e9 + 7, N = 1e5 + 5;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  set<int> arr;
  cin >> n >> k;
  while (n--) {
    int x;
    cin >> x;
    arr.insert(x);
  }
  int mex = 0;
  while (arr.count(mex))++mex;
  cout << min(k, mex);
}

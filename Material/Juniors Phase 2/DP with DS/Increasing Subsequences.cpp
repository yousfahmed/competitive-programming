#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 100007, mod = 5'000'000;

int add(int a, int b) {
  a += b;
  if (a >= mod)a -= mod;
  return a;
}

int bit[80][N + 7];
int sz;

void update(int i, int v) {
  while (i <= N) {
    bit[sz][i] = add(bit[sz][i], v);
    i += (i & -i);
  }
}

int query(int i) {
  int ret = 0;
  while (i > 0) {
    ret = add(ret, bit[sz][i]);
    i -= (i & -i);
  }
  return ret;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr), cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int &i: arr) {
    cin >> i, i += 2;
  }
  int a[n];
  for (int i = 0; i < n; ++i) {
    a[i] = query(arr[i] - 1);
    update(arr[i], 1);
  }
  for (sz = 1; sz < k - 1; ++sz) {
    for (int j = 0; j < n; ++j) {
      int x = a[j];
      a[j] = query(arr[j] - 1);
      update(arr[j], x);
    }
  }
  cout << accumulate(a, a + n, 0LL, add) << '\n';
}

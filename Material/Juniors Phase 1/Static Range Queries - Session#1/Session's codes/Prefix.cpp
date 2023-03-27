#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  string s;
  int n, q, l, r;
  char ch;
  cin >> n >> s >> q;

  int arr[28][n];
  for (int i = 0; i < 28; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      arr[i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i)
  {
    //// s[i] = 'c' - 'a'
    /// arr[0][i] = 1
    ch = s[i] - 'a';
    arr[ch][i] = 1;
  }

  for (int i = 0; i < 28; ++i)
  {
    for (int j = 1; j < n; ++j)
    {
      arr[i][j] += arr[i][j - 1];
    }
  }

  while (q--)
  {
    cin >> l >> r >> ch;
    int res = arr[ch - 'a'][r] - arr[ch - 'a'][l - 1];
    cout << res << '\n';
  }
}
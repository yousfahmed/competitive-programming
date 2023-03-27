#include <iostream>
using namespace std;

int min(int a, int b)
{
  if (a < b)
    return a;
  return b;
}

const int N = 1e5 + 5;
int arr[N], prefix[N], suffix[N];

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  prefix[0] = arr[0];
  suffix[n - 1] = arr[n - 1];
  for (int i = 1; i < n; ++i)
  {
    prefix[i] = min(arr[i], prefix[i - 1]);
  }
  for (int i = n - 2; i >= 0; --i)
  {
    suffix[i] = min(arr[i], suffix[i + 1]);
  }

  int q;
  cin >> q;
  int l, r;
  while (q--)
  {
    cin >> l >> r;
    int res = n + 1;
    if (l > 0)
    {
      res = prefix[l - 1];
    }
    if (r + 1 < n)
    {
      res = min(res, suffix[r + 1]);
    }
    cout << res << '\n';
  }
}
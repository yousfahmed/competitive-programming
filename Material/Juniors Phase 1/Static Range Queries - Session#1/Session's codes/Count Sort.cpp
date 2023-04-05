#include <iostream>

using namespace std;

void count_sort(string &str)
{
  int frq[26] = {0};
  for (int i = 0; i < str.size(); ++i)
  {
    frq[str[i] - 'a']++;
  }
  int idx = 0;
  char cur = 'a';
  for (int i = 0; i < 26; i++, cur++)
  {
    for (int j = 0; j < frq[i]; j++)
    {
      str[idx] = cur;
      ++idx;
    }
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  string str;
  cin >> str;
  count_sort(str);
  cout << str << '\n';
}

/*
  Link : https://codeforces.com/gym/102035/problem/I
  Author : Abdelaleleem
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n];
    for (int &i: arr) cin >> i;
    int i = 0, j = n - 1;
    vector<int> ret;
    while (i < j) ret.emplace_back(abs(arr[i++] - arr[j--]));
    int ans = 0;
    for (int &ele: ret) ans = __gcd(ans, ele);
    cout << (ans ? ans : -1) << '\n';
}

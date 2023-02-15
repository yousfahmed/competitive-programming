
/*
 *      101343H Solution
 *      Link : https://codeforces.com/gym/101343/problem/H
 *      H. Give Me This Pizza Solution 
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    NeedForSpeed

    int len;
    cin >> len;

    int arr[len];
    for (int i = 0; i < len; i++)
        cin >> arr[i];

    int ans[len];
    ans[len - 1] = -1;

    stack<int> s;
    s.push(arr[len - 1]);

    for (int i = len - 2; i >= 0; i--) {

        while (!s.empty() && arr[i] >= s.top())
            s.pop();

        ans[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < len; i++)
        cout << ans[i] << " ";
}
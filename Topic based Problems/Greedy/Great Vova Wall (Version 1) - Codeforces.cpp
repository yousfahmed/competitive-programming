/*
 *      Greedy
 *      D1. Great Vova Wall (Version 1)
 *      Link : https://codeforces.com/contest/1092/problem/D1
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main() {
    NeedForSpeed;
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i]&=1;
    }
    stack<bool> st;
    for (int i = 0; i < n; ++i)
        if(st.size() and arr[i]==st.top())  st.pop();
        else    st.push(arr[i]);
    cout << (st.size() <= 1 ? "YES" : "NO");
}

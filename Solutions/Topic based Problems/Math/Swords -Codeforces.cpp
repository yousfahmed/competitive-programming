/*
 *      Math
 *      D. Swords
 *      Link : https://codeforces.com/contest/1216/problem/D
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define gcd(a,b)    __gcd(a,b)
int main(){
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int n;  cin>>n;
    int arr[n];
    for(int&i:arr)  cin>>i;

    ll sum= accumulate(arr,arr+n,0ll);
    sort(arr,arr+n);
    int mx=arr[n-1];

    int N= unique(arr,arr+n)-arr;

    int mn=arr[1]-arr[0];

    for (int i = 2; i < N; ++i)
        mn=min(mn,gcd(mn,arr[i]-arr[i-1]));

    cout<< ((1ll*mx*n-sum)/mn) << " " << mn;
}

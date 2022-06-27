/*
 *      Math
 *     E. Two Arrays and Sum of Functions
 *      Link : https://codeforces.com/contest/1165/problem/E
 *      By Abdelaleem Ahmed
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
const ll MOD=998244353;

int main(){
  
    NeedForSpeed;
  
    ll n,ans=0;
    cin>>n;

    ll arr[n],b[n];
    for (ll i = 0; i < n; ++i) {
        cin>>arr[i];
        arr[i] *= (i+1) * (n-i);
    }

    for(ll&i:b)
        cin >> i;


    sort(arr,arr+n);
    sort(b,b+n,greater<>());

    for (int i = 0; i < n; ++i) {
        ans = (ans+(((arr[i]%MOD)*(b[i]%MOD))%MOD));
        ans%=MOD;
    }
    cout<<ans;

}

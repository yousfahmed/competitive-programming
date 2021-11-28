/*
 *      Bitmasks 
 *      C. Divan and bitwise operations
 *      Link : https://codeforces.com/contest/1614/problem/C
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll MOD=1e9+7;

inline void solve(){

    ll n,m,l,r,x,ans=0;
    cin>>n>>m;
    while (m--){
        cin>>l>>r>>x;
        ans|=x;
    }
    ll pow=1;
    for (ll i = 1; i < n; ++i) {
        pow*=2;
        pow%=MOD;
    }

    cout<< (ans * pow)%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while (t--){
        solve();
        if(t)   cout<<"\n";
    }
}

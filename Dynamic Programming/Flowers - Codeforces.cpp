/*
 *      Dynamic Programming
 *      D. Flowers
 *      Link : https://codeforces.com/contest/474/problem/D
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
const ll N=1e5 ,MOD=1e9+7;
int k;
vector<ll> mem;
ll dp(ll rem){
    if(rem<=0)    return rem==0;
    ll&ans=mem[rem];
    if(~ans)    return ans;
    ll op1= dp(rem-k)%MOD;
    ll op2= dp(rem-1)%MOD;
    return ans=((op1+op2)%MOD);
}
int main(){
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
#endif
    int t,a,b;
    cin>>t>>k;
    mem.assign(N+10,-1);
    for (int i = 1; i <=N ; ++i)   dp(i);
    mem[0]=0;
    for (int i = 1; i <=N ; ++i)   mem[i]+=mem[i-1];
    while (t--){
        cin>>a>>b;
        cout<<(mem[b]-mem[a-1])%MOD<<"\n";
    }
}

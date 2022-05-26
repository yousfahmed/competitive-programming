/*
 *      Dynamic Programming
 *      B. Mashmokh and ACM
 *      Link : https://codeforces.com/contest/414/problem/B
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
const int N=2002 ,MOD=1e9+7;
int n,k;
ll mem[N][N];
ll dp(int i,int d){
    if(d>=k)    return d==k;
    ll&ans=mem[i][d];
    if(~ans)    return ans;
    ans=0;
    for (int j = i; j <= n; j+=i)
        ans= (ans+dp(j, d + 1))%MOD;
    return ans;
}
int main(){
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
#endif

    cin>>n>>k;
    memset(mem,-1,sizeof mem);
    ll ans=0;
    for (int i = 1; i <= n; ++i)
        ans=(ans+dp(i,1))%MOD;

    cout<<ans;
}

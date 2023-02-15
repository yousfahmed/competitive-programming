/*
 *      Dynamic Programming
 *      B. Let Me Count The Ways    UVA-357 
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
const int N=30007;
ll mem[5][N];
const int coins[]={1,5,10,25,50};
ll dp(int i,int rem){
    if(rem==0)    return 1;
    if(i==5)return 0;
    ll&ans=mem[i][rem];
    if(~ans)return ans;
    ll op1=0,op2=0;
    if(rem>=coins[i])   op1=dp(i,rem-coins[i]);
    op2=dp(i+1,rem);
    return ans=op1+op2;
}
int main(){
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
#endif
    memset(mem,-1,sizeof mem);
    int n;
    while (cin>>n){
        ll ans=dp(0,n);
        if(ans!=1) cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change.\n";
        else cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
    }

}

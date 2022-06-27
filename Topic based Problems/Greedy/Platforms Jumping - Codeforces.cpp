/*
 *      Greedy
 *      C. Platforms Jumping
 *      Link : https://codeforces.com/contest/1256/problem/C
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
inline void solve(){

    int n,m,d;  cin>>n>>m>>d;

    vector<int> w(m+1) ,suf(m+15);
    vector<int> ans(n+1,0);

    for (int i = 1; i <= m; ++i)
        cin>>w[i];

    suf[m]=w[m];
    for (int i = m-1; i > 0 ; --i)
        suf[i]=w[i]+suf[i+1];




    int cur=0 ,idx=1;

    while (idx<=m){

        int mn=cur+d;

        int st=min(mn,n-suf[idx]+1);

        if(st<cur){
            cout<<"NO";return;
        }

        ans[st++]=idx;
        for (int i = 1; i < w[idx]; ++i)
            ans[st++]=idx;

        idx++;
        cur=st-1;
    }

    if(cur==n or cur+d>n ){
        cout<<"YES\n";
        for (int i = 1; i <=n ; ++i)
            cout<<ans[i]<< " " ;
    }else
        cout<<"NO";

}
int main(){
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while (t--){
        solve();
        if(t)   cout<<"\n";
    }
}

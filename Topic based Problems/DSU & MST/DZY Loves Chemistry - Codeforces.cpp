/*
 *      DSU
 *      B. DZY Loves Chemistry Solution
 *      Link : https://codeforces.com/contest/445/problem/B
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=57;
int par[N],sz[N];

int findPar(int u){
    if(par[u]==u)   return u;
    return par[u]= findPar(par[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif
    iota(par,par+N,0);
    fill(sz,sz+N,1);

    int n,m,u,v;
    cin>>n>>m;
    while (m--){
        cin>>u>>v;
        u= findPar(u);
        v= findPar(v);
        if(u!=v){

            if(sz[u]>sz[v])
                swap(u,v);

            par[u]=v;
            sz[v]+=sz[u];
        }
    }
    ll ans=1;
    for (u = 1; u <= n; ++u) {
        if (findPar(u) == u)
            ans <<= (sz[u] - 1);
    }

    cout<<ans;

}

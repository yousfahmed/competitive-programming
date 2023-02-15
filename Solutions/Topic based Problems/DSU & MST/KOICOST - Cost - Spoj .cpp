/*
 *      DSU And minimum spanning tree
 *      KOICOST - Cost  Solution
 *      Link : https://www.spoj.com/problems/KOICOST/en/
 *      By Abdelaleem Ahmed
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9,N=1e5;
int par[N+9],sz[N+9];
int findPar(int i){
    if(par[i]==i)   return i;
    return par[i]= findPar(par[i]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif

    iota(par,par+N,0);
    fill(sz,sz+N,1);

    int n,m,u,v,c;
    cin>>n>>m;
    priority_queue<pair<int,pair<int,int>>>q;
    while (m--){
        cin>>u>>v>>c;
        q.emplace(c, make_pair(u,v));
    }
    ll sum=0,cnt=0;
    while (q.size()){
        c=q.top().first;u= findPar( q.top().second.first);v=findPar(q.top().second.second);
        q.pop();

        if(u!=v){
            cnt += 1LL * sz[u] * sz[v];
            if(sz[u] < sz[v])
                swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        }
        sum= (sum+ ((cnt * c) % MOD)) % MOD;
    }
    cout<<sum;
}

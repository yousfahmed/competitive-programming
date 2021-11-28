/*
 *      DSU
 *      E. Graph Destruction
 *      Link : https://atcoder.jp/contests/abc229/tasks/abc229_e
 *      By Abdelaleem Ahmed
 *
 */
#include <bits/stdc++.h>
using namespace std ;

const int MAX = 2e5 + 10 ;
int n , m;

vector<int>adj[MAX] ;

int par[MAX] , sz[MAX], ans[MAX];
int cnt = 0;

int findPar(int node){
    if(par[node] == node)
        return node ;
    return (par[node] = findPar(par[node])) ;
}

void Union(int u , int v){
    u = findPar(u) ;
    v = findPar(v) ;
    if(u == v)  return;

    if(sz[u]<sz[v])
        swap(u,v);

    par[v] = u;
    sz[u] += sz[v];
    cnt--;
}

int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;
    cin>>n>>m ;
    for(int i = 0 ; i < m ; ++i){
        int x , y ;
        cin>>x>>y ;
        if(x>y)
            swap(x,y);

        adj[x].push_back(y) ;
    }
    iota(par,par+MAX,0);
    fill(sz,sz+MAX,1);

    for(int i = n ; i >= 1 ; --i){
        ans[i] = cnt++;
        for(auto &child : adj[i])
            Union(i , child);
    }
    for(int i = 1 ; i <= n ; ++i)
        cout<<ans[i]<<"\n" ;

}

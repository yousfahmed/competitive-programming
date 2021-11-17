/*
 *      DSU And minimum spanning tree
 *      MST - Minimum Spanning Tree  Solution
 *      Link : https://www.spoj.com/problems/MST/en/
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10009;
int par[N];
int cnt[N]={1};
#define u second.first
#define v second.second

int FindPar(int i){
    if(par[i]==i) return i;
    return par[i]= FindPar(par[i]);
}

ll MST(vector<pair<int,pair<int,int>>>&adj){
    ll ans=0;
    int n=adj.size();
    for (int i = 0; i < n; ++i) {
        int p1=FindPar(adj[i].u);
        int p2=FindPar(adj[i].v);
        int cost=adj[i].first;
        if( p1 != p2 ){
            ans+=cost;
            if(cnt[p1]<cnt[p2])
                swap(p1,p2);
            cnt[p1]+=cnt[p2];
            par[p2]=p1;

        }
    }

    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
#endif

    int n,m;

    cin>>n>>m;

    iota(par,par+n+1,0);

    vector<pair<int,pair<int,int>>> adjEdge(m);
    for (int i = 0; i < m; ++i)
        cin >> adjEdge[i].u >> adjEdge[i].v >> adjEdge[i].first;


    sort(adjEdge.begin(),adjEdge.end());


    cout<<MST(adjEdge);

}
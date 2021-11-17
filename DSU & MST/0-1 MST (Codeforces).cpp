/*
 *      DSU And minimum spanning tree
 *      B. 0-1 MST  Solution
 *      Link : https://codeforces.com/contest/1242/problem/B
 *      By Abdelaleem Ahmed
 */

#include<bits\stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()

const int N=1e5+7;
vector<int> adj[N];
int par[N];

int findPar(int x){
    if(par[x]==x) return x;
    return par[x]= findPar(par[x]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef    ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif
    int n,m;
    cin>>n>>m;

    for (int i = 0,u,v; i < m; ++i) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<int> s;
    for (int i = 1; i <=n ; ++i) {
        s.insert(i);
        par[i]=i;
    }
    for (int i = 1; i <= n; ++i) {

        for(auto j:adj[i])
            s.erase(j);

        for (auto j:s)
            par[findPar(i)]=findPar(j);

        s.clear();
        s.insert(i);
        for(auto j:adj[i])
            s.insert(j);
    }
    set<int> p;
    for(int i=1;i<=n;i++)
        p.insert(findPar(par[i]));
    cout<< p.size()-1;

}
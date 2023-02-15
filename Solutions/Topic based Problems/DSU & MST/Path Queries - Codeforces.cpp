/*
 *      DSU
 *      G. Path Queries
 *      Link : https://codeforces.com/contest/1213/problem/G
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define all(v)  (v).begin(),(v).end()

#define pairs(v) (((v)*((v)-1))>>1)
priority_queue< pair<int,pair<int,int>>> adj;
ll res;

struct DSU{
    int*par,*sz;
    DSU(int n){
        par=new int[n+1];
        sz=new int[n+1];
        fill(sz,sz+n+1,1);
        iota(par,par+n+1,0);
    }

public:

    int getPar(int u){
        if(par[u]==u)return u;
        return par[u]= getPar(par[u]);
    }

    bool join(int u,int v){
        u= getPar(u),v= getPar(v);

        if(u==v)
            return false;

        if(sz[u]>sz[v])
            swap(u,v);

        res-= pairs(sz[u]);
        res-= pairs(sz[v]);

        par[u]=v;
        sz[v]+=sz[u];

        res+=pairs(sz[v]);
        return true;
    }
};

int main(){
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int n ,q ,u ,v ,c;
    cin >> n >> q;

    DSU graphs(n);

    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> c;
        adj.push(make_pair(-c, make_pair(u, v)));
    }

    ll ans[q];
    vector<pair<int,int>> queries (q);
    for (int i = 0 ; i < q ; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(all(queries));
    for (auto i:queries) {
        while (adj.size() and (-adj.top().first)<=i.first){
            u = adj.top().second.first;
            v = adj.top().second.second;
            adj.pop();
            graphs.join(u,v);
        }
        ans[i.second] = res;
    }

    for(ll i:ans)
        cout << i << " ";
    return 0;
}

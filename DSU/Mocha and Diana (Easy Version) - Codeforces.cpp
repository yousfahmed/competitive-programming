/*
 *      DSU
 *      D1 - Mocha and Diana (Easy Version) Solution
 *      Link (Easy Version) : https://codeforces.com/contest/1559/problem/D1
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
class DSU{

private:
    int*par;
    int*sz;
public:
    DSU(){
        int MAX=1e5+7;
        par= new int[MAX];
        sz =new int[MAX];
        iota(par,par+MAX,0);
        fill(sz,sz+MAX,1);
    }
    DSU(int n){
        n++;
        par= new int[n];
        sz =new int[n];
        iota(par,par+n,0);
        fill(sz,sz+n,1);
    }

    int findPar(int u){
        if(par[u]==u) return u;
        return par[u]= findPar(par[u]);
    }

    bool join(int u,int v){
        u= findPar(u);
        v= findPar(v);
        if(u==v)return false;
        if(sz[u]>sz[v]) swap(u,v);
        par[u]=v;
        sz[v]+=sz[u];
        return true;
    }
};
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif

    int n,m1,m2,u,v;
    cin>>n>>m1>>m2;

    DSU mocha(n),diana(n);

    while (m1--){
        cin>>u>>v;
        mocha.join(u,v);
    }

    while (m2--){
        cin>>u>>v;
        diana.join(u,v);
    }

    vector<pair<int,int>> ans;
    for (u = 1; u <= n; ++u) {
        for (v = u+1; v <= n; ++v) {
            if( mocha.findPar(u)!= mocha.findPar(v) and diana.findPar(u)!=diana.findPar(v))
                ans.emplace_back(u,v),mocha.join(u,v),diana.join(u,v);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans)
        cout<<i.first<<" "<<i.second<<"\n";

}

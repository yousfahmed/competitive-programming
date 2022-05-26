/*
 *      DSU
 *     A. Ice Skating Solution
 *      Link : https://codeforces.com/contest/217/problem/A
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define all(x)  x.begin(),x.end()

map<pair<int,int>,pair<int,int>> par;

pair<int,int> findPar(pair<int, int> u){
    if(par[u]==u)  return u;
    return par[u]= findPar(par[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif
    int n;
    cin>>n;

    vector<pair<int,int>> x(n), y(n);
    pair<int,int> tmp;
    for (int i = 0; i < n; ++i) {
        cin>>x[i].first>>x[i].second;
        y[i]= make_pair(x[i].second,x[i].first);
    }
    sort(all(x));
    sort(all(y));

    for (int i = 0; i < n; ++i) {
        if(i+1<n and x[i].first==x[i+1].first)
            par[x[i]]=x[i+1];
        else
            par[x[i]]=x[i];
    }


    for (int i = 0,len=n-1; i < len; ++i) {
        if(y[i].first==y[i+1].first)
            par[findPar( {y[i].second, y[i].first})]= findPar({y[i+1].second,y[i+1].first});
    }

    set<pair<int,int>> comp;
    for (auto i = par.begin(); i !=par.end() ; ++i) {
        comp.insert( findPar(make_pair(i->second.first,i->second.second)));
    }
    cout<<comp.size()-1;




}

/*
 *      DSU And minimum spanning tree
 *      D. Love Rescue Solution
 *      Link : https://codeforces.com/contest/939/problem/D
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;

char par[210];

char FindParent(char x){
    if(par[x]==x) return x;
    return par[x]= FindParent(par[x]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif
    iota(par,par+210,0);

    int n;   cin>>n;
    char v[n+1],t[n+1];
    cin>>v>>t;
    set<pair<char,char>> cnt;
    for (int i = 0; i < n; ++i) {
        if(v[i]!=t[i] ){
            char p1= FindParent(v[i]);
            char p2= FindParent(t[i]);
            if(p1!=p2){
                par[p1]=p2;
                cnt.insert({v[i],t[i]});
            }
        }
    }

    cout<<cnt.size()<<"\n";
    for(auto i:cnt){
        cout<<i.first <<" "<<i.second <<"\n";
    }
}
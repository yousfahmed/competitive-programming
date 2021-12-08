/*
 *      Greedy
 *      B. Minimize the Permutation
 *      Link : https://codeforces.com/contest/1256/problem/B
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
inline void solve(){

    int n;  cin>>n;
    set<pair<int,int>> arr;
    vector<int> ans;

    for (int i = 0,in; i < n; ++i) {
        cin>>in;
        arr.insert({i,in});
    }
    
    int t=n,idx,j;

    while ( t and arr.size() ){

        idx=0,j=0;
        auto mn=arr.begin();
        for(auto i=arr.begin(); idx<t and i!=arr.end() and idx<t;i++){
            if( i->second <mn->second)
                mn = i,j=idx;
            idx++;
        }

        ans.push_back(mn->second);
        arr.erase(mn);
        for (int i = 1; i <j ; ++i) {
            ans.push_back(arr.begin()->second);
            arr.erase(arr.begin());
        }
        t-=j;
    }
    for(int i:ans)
        cout<<i<<" ";
    for(auto i:arr)
        cout<<i.second<<" ";
    
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

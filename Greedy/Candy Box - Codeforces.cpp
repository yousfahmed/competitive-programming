/*
 *      Greedy
 *      D. Candy Box
 *      Link : https://codeforces.com/contest/1183/problem/D
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void doWork(){
    int n,in;  cin>>n;
    map<int,int> mp;
    while (n--){
        cin>>in;
        mp[in]++;
    }
    vector<int> ans;
    for (auto i:mp)
        ans.emplace_back(i.second);
    sort(ans.rbegin(),ans.rend());
 
    int p=ans.front();
    ll a=0;
    for (int i : ans) {
 
        a+=min(i,p);
        p=min(p,i)-1;
        if(p<=0)break;
    }
    cout<<a;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif
    int t=1;
    cin>>t;
    while (t--){
        doWork();
        if(t)   cout<<"\n";
    }
}

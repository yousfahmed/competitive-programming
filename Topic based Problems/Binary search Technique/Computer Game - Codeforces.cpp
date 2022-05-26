/*
 *      Binary search Technique
 *      C. Computer Game
 *      Link : https://codeforces.com/contest/1183/problem/C
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void doWork(){

    ll k ,n ,a ,b;

    cin >> k >> n >> a >> b;
    auto okay=[&](ll i) ->bool {
        ll T=k;
        T-=i*a;
        if(T<=0)    return false;
        if((n-i)*b<T)   return true;
        return false;
    };

    ll ans=-1,st=0,end=n;
    while (st<=end){
        ll mid=(end-st)/2+st;
        if(okay(mid)){
            ans=mid;
            st=mid+1;
        }else
            end=mid-1;
    }

    cout<<ans;
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

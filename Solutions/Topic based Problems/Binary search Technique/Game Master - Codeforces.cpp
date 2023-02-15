/*
 *      Binary search Technique
 *      C. Game Master
 *      Link : https://codeforces.com/contest/1608/problem/C
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(X) (X).begin(),(X).end()

inline void doWork(){

    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>>arr(n);
    vector<int> preMx(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second.second=i;
    }

    for (auto&i:arr)
        cin>>i.second.first;

    sort(all(arr));


    preMx[0]=arr[0].second.first;
    for (int i = 1; i < n; ++i)
        preMx[i]=max(preMx[i-1],arr[i].second.first);


    auto okay=[&](int idx) -> bool{
        int mx=preMx[idx];
        for (int i = idx+1; i < n; ++i)
            if( mx >= arr[i].second.first)
                mx=preMx[i],idx=i;
        return (idx==n-1);
    };

    int st=0 ,end=n-1 ,mid ,idx=0;

    while (st<=end){
        mid=(end-st)/2+st;
        if(okay(mid))
            idx=mid,end=mid-1;
        else
            st=mid+1;
    }

    string ans(n,'0');

    for (int i = idx; i < n; ++i)
        ans[arr[i].second.second]++;

    cout<<ans;
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
        doWork();
        if(t)   cout<<"\n";
    }
}

/*
 *      Binary search Technique
 *      Coffee and Coursework (D1 - Easy Version) & (D2 - hard version)
 *      Link (Easy Version) : https://codeforces.com/contest/1118/problem/D1
 *      Link (hard version) : https://codeforces.com/contest/1118/problem/D2
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);

    for(int&i:arr)
        cin>>i;

    sort(arr.rbegin(),arr.rend());

    auto okay=[&](int d){
        ll sum=0;
        for (int i = 0; i < n; ++i)
           sum+=max(arr[i]-i/d,0);

        return sum>=m;
    };

    int st=1,end=n,mid,ans=-1;

    while (st<=end){

        mid=(end-st)/2+st;

        if(okay(mid))
            ans=mid,end=mid-1;
        else
            st=mid+1;
    }
    cout<<ans;
}

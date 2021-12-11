/*
 *      Math
 *      D1. Equalizing by Division (easy version) | D2. Equalizing by Division (hard version)
 *      Link (easy version): https://codeforces.com/contest/1213/problem/D1
 *      Link (hard version): https://codeforces.com/contest/1213/problem/D2
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int inf=1e9+7,N=2e5;
int pre[N+1];
vector<priority_queue<int>> ans(N+1);
int main(){
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int n,k;  cin>>n>>k;
    int arr[n];

    for(int&i:arr)  cin >> i;
        

    for (int i = 0; i < n; ++i) {
        int op=0,x=arr[i];
        while (x>0){
            if(ans[x].empty() or ans[x].size()<k ){
                ans[x].push(op);
                pre[x]+=op;
            }else if (ans[x].top()>op){
                pre[x]-=ans[x].top();
                ans[x].pop();
                ans[x].push(op);
                pre[x]+=op;
            }
            x>>=1;
            op++;
        }
    }


    int len= *max_element(arr,arr+n) ,p=inf;
    
    for (int i = 1; i <= len; ++i)
        if(ans[i].size()==k)
            p=min(p,pre[i]);
        
    cout<<p;
}

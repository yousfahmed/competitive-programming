/*
 *      Dynamic Programming
 *      WACHOVIA - Wachovia Bank
 *      Link : https://www.spoj.com/problems/WACHOVIA/en
 *      By Abdelaleem Ahmed
 *
 */
#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[52];
int k ,n;
vector<vector<int>> mem;
int solve(int i,int rem){

    if(i>=n or rem==0)
        return 0;

    if(mem[i][rem]!=-1)
        return mem[i][rem];

    int op1=0;

    if(arr[i].first<=rem)
        op1=solve(i+1,rem-arr[i].first)+arr[i].second;

    int op2=solve(i+1,rem);

    return mem[i][rem] = max(op1,op2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif
    int t;  cin>>t;
    while (t--){

        cin>>k>>n;

        /// the weight , the value of the bag,
        for (int i = 0; i < n; ++i)
            cin>>arr[i].first>>arr[i].second;

        mem.assign(n,vector<int>(k+1,-1));

        cout<<"Hey stupid robber, you can get "<< solve(0,k) << ".";

        if(t)   cout<<"\n";
    }

}

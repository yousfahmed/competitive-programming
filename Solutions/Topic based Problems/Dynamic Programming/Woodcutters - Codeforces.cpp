/*
 *      Dynamic programming
 *      C. Woodcutters
 *      Link : https://codeforces.com/problemset/problem/545/C
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
int n;
pair<int,int> arr[N];
vector<vector<int>> mem;
int dp(int i, bool j){

    if(i>=n)    return 0;
    int &ans=mem[i][j];

    if(~ans)    return ans;

    int op1=dp(i+1, (i+1==n or arr[i+1].first-arr[i+1].second>arr[i].first) );

    int op2=0;

    if(j)
        
        op2=1+dp(i+1,(i+1==n or arr[i+1].first-arr[i+1].second>arr[i].first));
    
    else if (i+1==n or arr[i].first+arr[i].second<arr[i+1].first)
        
        op2=1+dp(i+1,(i+1==n or arr[i].first+arr[i].second<arr[i+1].first-arr[i+1].second ));
    

    return ans = max(op1,op2);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif

    cin>>n;


    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    
    mem.assign(n,vector<int>(2,-1));
    
    cout<<dp(0,1 );

}

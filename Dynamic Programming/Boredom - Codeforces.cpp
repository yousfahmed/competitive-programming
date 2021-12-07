/*
 *      Dynamic Programming
 *      A. Boredom
 *      Link : https://codeforces.com/contest/455/problem/A
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+7;
int freq[N], arr[N], sz;
ll mem[N];

ll dp(int i){

    if(i>=sz)
        return 0;
    ll &ans=mem[i];
    if(~ans)
        return ans;

    ll op1=dp(i+1);

    ll op2=1ll*freq[arr[i]]*arr[i];

    if(i+1!=sz)
        op2 += dp(i + ( (arr[i+1] == arr[i] + 1) ? 2 : 1));

    return (ans = max(op1,op2));

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif

    int n,in;
    cin>>n;
    while (n--){
        cin>>in;
        if(!freq[in])   arr[sz++]=in;
        freq[in]++;
    }
    memset(mem,-1,8*(sz+2));

    sort(arr,arr+sz);

    cout<<dp(0);

}

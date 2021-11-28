/*
 *      Bitmasks
 *      E. Binary Numbers AND Sum
 *      Link : https://codeforces.com/contest/1066/problem/E
 *      By Abdelaleem Ahmed
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(s) s.begin(),s.end()

const ll N = 2e5+7 , MOD = 998244353;
int freq[N];


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m;
    ll ans=0,res=1;
    string a,b;

    cin>>n>>m>>a>>b;

    reverse(all(a));
    reverse(all(b));

    for (int i = m-1; i >=0 ; --i)
        freq[i]=freq[i+1]+(b[i]=='1');

    for (int i = 0; i < n; ++i) {
        if (a[i] == '1')
            ans = (ans + (freq[i] * res) % MOD) % MOD;
        res*=2;
        res%=MOD;
    }

    cout<<ans;
}

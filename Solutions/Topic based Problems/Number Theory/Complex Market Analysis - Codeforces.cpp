/*
 *      Number Theory - Sieve Algorithm
 *      C. Complex Market Analysis Solution
 *      Link : https://codeforces.com/contest/1609/problem/C
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N= 1e6;
bool primes[N+7];

void sieve(){
    primes[1]= true;
    for (ll i = 2; i*i <= N; ++i) {
        if (!primes[i]) {
            for (ll j = i * 2; j <= N; j += i)
                primes[j] = true;
        }
    }

}

inline void solve(){
    int n,k;
    cin>>n>>k;
    ll p[k],ones[k] ,ans = 0;

    memset(p,0,sizeof p);
    memset(ones,0, sizeof ones);

    for (int i = 0,in; i < n; ++i) {

        cin>>in;
        if(!primes[in]){

            ans+=ones[i%k];
            p[i%k]=ones[i%k]+1;
            ones[i%k]=0;

        }else if(in==1){

            ans+=p[i%k];
            ones[i%k]++;

        }else {
            ones[i % k] = p[i % k] = 0;
        }

    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    sieve();
    int t=1;    cin>>t;
    while (t--){
        solve();
         if(t)   cout<<"\n";
    }
}

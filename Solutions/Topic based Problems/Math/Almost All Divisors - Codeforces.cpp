/*
 *      Math
 *     D. Almost All Divisors
 *      Link : https://codeforces.com/contest/1165/problem/D
 *      By Abdelaleem Ahmed
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
map<ll,int> freq;
int main(){
    NeedForSpeed;
    int tt=1;
    cin>>tt;
    for (int t = 1; t <=tt ; ++t) {

        int n;
        cin>>n;
        ll arr[n];

        for(ll&i:arr){
            cin>>i;
            freq[i]=t;
        }
        sort(arr,arr+n);

        ll ans=arr[0]*arr[n-1];

        for(ll&i:arr){
            if(ans%i!=0){
                cout<<-1;
                goto label;
            }
        }

        for (ll i = 2; i * i <= ans; ++i) {
            if ((ans % i == 0) and (freq[i] != t or freq[ans / i] != t)) {
                cout<<-1;
                goto label;
            }
        }

        cout<< ans << "\n";
        label:;
    }

}

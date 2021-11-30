/*
 *      Math
 *      M. Winning Cells
 *      Link : https://codeforces.com/gym/101608/problem/M
 *      By Abdelaleem Ahmed
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define Ceil(A,B)   ( ((A)+(B)-1) / (B) )
ll sum(ll end,ll k){ // summation = (First+Last) / number of numbers ...
    
    ll st=end%k;
    ll N= Ceil(end,k);
    if(st==0)   N++;
    return (st+end)*N;
}
void doWork(){
    ll n,k;
    cin>>n>>k;
    cout<< n*(n-1) - sum(n-k,k+1);
}
int main(){
    NeedForSpeed;
    freopen("chess.in", "r", stdin);
    int t=1;
    cin>>t;
    while (t--){
        doWork();
        cout << "\n";
    }
}

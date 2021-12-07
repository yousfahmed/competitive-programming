/*
 *      Dynamic Programming
 *      674 - Coin Change  UVA-674
 *      Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=615
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int coins[]={1, 5, 10, 25, 50} ;
int n;
vector<vector<ll>> mem(5,vector<ll>(7491,-1));

ll solve(int i,ll rem){

    if(rem==0)
        return 1;

    if(i==5)
        return 0;

    if(mem[i][rem]!=-1)
        return mem[i][rem];

    ll op1=0;

    if(coins[i]<=rem)
        op1= solve(i,rem-coins[i]);

    ll op2= solve(i+1,rem);

    return mem[i][rem]=op1+op2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif

    while (cin>>n)

        cout<<solve(0,n)<< '\n';

}

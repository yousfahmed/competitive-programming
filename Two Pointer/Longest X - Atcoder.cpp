/*
 *      Two Pointer
 *      D - Longest X
 *      Link : https://atcoder.jp/contests/abc229/tasks/abc229_d
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main(){
    NeedForSpeed;
    int k, i,j,cnt,ans;
    string s;
    cin>>s>>k;
    int n=s.length();
    while (i<n){
        cnt+=(s[i++]=='.');
        while (j<=i and cnt>k)
            cnt-=s[j++]=='.';
        ans=max(ans,i-j);
    }
    cout<<ans;
}

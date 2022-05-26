/*
 *      Dynamic Programming
 *      Make Palindrome    UVA-10453 
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int N=1007;
string s ,ans;
int mem[N][N],idx1,idx2;

int dp(int i,int j){
    if(i>=j)    return 0;
    int&ans=mem[i][j];
    if(~ans)    return ans;
    if(s[i]==s[j])  return ans=dp(i+1,j-1);
    int op1=1+dp(i+1,j); ///insert the i-th char after j-th char
    int op2=1+dp(i,j-1);
    return ans=min(op1,op2);
}
void print(int i,int j){
    if(i>j)    return;
    if(i==j){
        ans[idx1++]=s[i];
        return;
    }
    if(s[i]==s[j]) {
        ans[idx1++]=ans[idx2--]=s[i];
        print(i+1,j-1);
        return;
    }
    int op1=1+dp(i+1,j); ///insert the i-th char after j-th char
    int op2=1+dp(i,j-1);

    if(op1<op2){
        ans[idx2--]=ans[idx1++]=s[i];
        print(i+1,j);
        return;
    }
    ans[idx1++]=ans[idx2--]=s[j];
    print(i,j-1);
}
int main(){
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
#endif
    while (cin>>s){
        memset(mem,-1,sizeof mem);
        int add=dp(0,s.length()-1);
        ans.resize(s.length()+add);
        idx1=0,idx2=ans.size()-1;
        print(0,s.length()-1);
        cout << add << ' ' << ans << "\n";
    }

}

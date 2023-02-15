/*
 *      1144C Solution
 *      Link : https://codeforces.com/contest/1144/problem/C
 *      C. Two Shuffled Sequences Solution
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool checkA[200001];
bool checkB[200001];
int n,in;
set <int>a ,b;

int main() {
    NeedForSpeed
    cin>>n;
    while(n--){
        cin>>in;
        if(!checkA[in]){
            a.insert(in);
            checkA[in]= true;
        }else if(!checkB[in]){
            b.insert(in);
            checkB[in]= true;
        }else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    
    cout<<b.size()<<"\n";
    for(auto it=b.begin();it!=b.end();it++)
        cout<<*it<<" ";

    cout<<"\n"<<a.size()<<"\n";
    for(auto it=a.rbegin();it!=a.rend();it++)
        cout<<*it<<" ";
    
}
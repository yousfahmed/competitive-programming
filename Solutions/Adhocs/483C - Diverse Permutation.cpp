/*
 *      483C Solution
 *      Link : https://codeforces.com/problemset/problem/483/c
 *      C. Diverse Permutation Solution
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool check[100001];
int main() {
    NeedForSpeed
    int n,k;
    cin>>n>>k;
    queue<int> q;
    int num=1;
    q.push(1);
    check[1]= true;
    while (k) {
        num +=  (num-k > 0 && !check[num-k]) ? -k : k ;
        q.push(num);
        check[num] = true;
        k--;
    }
    int i=2;
    while(q.size()<n){
        if(!check[i])
            q.push(i);
        i++;
    }
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

}
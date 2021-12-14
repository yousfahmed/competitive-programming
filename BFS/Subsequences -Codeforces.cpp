/*
 *      BFS - Shortest paths
 *      E. Subsequences (easy version)
 *      Link : https://codeforces.com/contest/1183/problem/E
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif
    int n,k; string s;
    set<string> st;
    queue<string> q;
    ll ans=0,cnt=0;

    cin >> n >> k >> s;

    st.insert(s);
    q.emplace(s);

    while ( st.size()<k and q.size() ){
        int t=q.size();
        cnt++;
        while ( st.size()<k and t-- ) {
            string cur = q.front();
            q.pop();
            for (int i = 0; st.size() < k and i < cur.size(); ++i) {
                string child = cur;
                child.erase(child.begin() + i);
                if (st.count(child) == 0) {
                    st.insert(child);
                    q.emplace(child);
                    ans+=cnt;
                }
            }
        }
    }

    if(st.size()<k)
        return cout<<-1,0;
    cout<< ans;
}

/*
 *      BFS
 *      E1. Escape The Maze (easy version)
 *      Link : https://codeforces.com/contest/1611/problem/E1
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n , k, u, v;
    cin >> n >> k;
    vector<int>tree(n+1,-1);
    vector<vector<int>> adj(n+1);
    queue<int> bfs;
    while (k--){
        cin >> u;
        tree[u] = 1;
        bfs.push(u);
    }

    for (int i = 1; i < n ; ++i) {
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    bfs.push(1);
    tree[1] = 0;
    vector<int> leaves;
    while (bfs.size()){
        u=bfs.front();
        bfs.pop();
        for(int child:adj[u]){
            if(tree[child] == -1 ){
                tree[child] = tree[u];
                if(adj[child].size() == 1 and tree[u] == 0) {
                    cout << "YES";
                    return;
                }
                bfs.emplace(child);
            }
        }
    }
    cout<<"NO";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("ans.txt","r",stdin);
#endif
    int t;  cin>>t;
    while (t--){
        solve();
        if(t)   cout<<"\n";
    }

}

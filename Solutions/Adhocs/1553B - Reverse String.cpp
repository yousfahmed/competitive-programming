/*
 *      1553B Solution
 *      Link : https://codeforces.com/contest/1553/problem/B
 *      B. Reverse String
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);
inline void solve() {
    string s,t;
    cin>>s>>t;

    if(t.length()==1){
        if(find(s.begin(),s.end(),t[0])!=s.end())
            cout<<"YES";
        else
            cout<<"NO";
        return;
    }


    for (int j = 0; j < s.length()-1; ++j) {
        if(t[0]==s[j]&&  t[1]==s[j+1]){
            int tt=1,ss=j+1,cnt=-1;

            vector<pair<int,int>> pp;

            while(tt<t.length() && ss<s.length() && t[tt]==s[ss]){
                if(tt+1<t.length()&& ss>0 &&t[tt+1]==s[ss-1]){
                    cnt++;
                    pp.emplace_back(tt,ss);
                }
                tt++,ss++;
            }

            ss-=2;
            label:

            while(tt<t.length() && ss>=0 && t[tt]==s[ss])
                tt++,ss--;

            if(tt==t.length()){
                cout<<"YES";
                return;
            }
            if(cnt>=0){
                tt=pp[cnt].first;
                ss=pp[cnt].second;
                cnt--;
                pp.pop_back();
                goto label;
            }
        }

    }
    cout<<"NO";

}


int main() {
    NeedForSpeed
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
}
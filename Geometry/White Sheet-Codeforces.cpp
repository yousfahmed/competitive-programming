/*
 *      Geometry
 *      C. White Sheet
 *      Link : https://codeforces.com/contest/1216/problem/C
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define x   first
#define y second

pair<ll,ll> interSection(ll x1,ll y1,ll x2,ll y2){
    if(y2<x1 or x2>y1)
        return {-1,-1};
    ll temp[4] = {x1, x2, y1, y2};
    sort(temp, temp + 4);
    return { temp[1], temp[2] };
}
int main(){
    NeedForSpeed;
#ifndef ONLINE_JUDGE
    freopen("ans.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    pair<ll,ll> p[6];

    for (ll i = 0; i < 6; ++i)
        cin>>p[i].x>>p[i].y;


    auto x1=interSection(p[0].x,p[1].x,p[2].x,p[3].x);
    auto y1=interSection(p[0].y,p[1].y,p[2].y,p[3].y);
    auto x2=interSection(p[0].x,p[1].x,p[4].x,p[5].x);
    auto y2=interSection(p[0].y,p[1].y,p[4].y,p[5].y);
    ll total=0;
    if(x1.x!=-1 and y1.x!=-1)
        total+=(x1.y-x1.x) * (y1.y-y1.x);

    if(x2.x!=-1 and y2.x!=-1)
        total+=(x2.y-x2.x) * (y2.y-y2.x);


    ll sub=0;
    if(x1.x!=-1 and y1.x!=-1 and x2.x!=-1 and y2.x!=-1) {
        auto x3 = interSection(x1.x,x1.y,x2.x,x2.y);
        auto y3= interSection(y1.x,y1.y,y2.x,y2.y);
        if(x3.x!=-1 and y3.x!=-1)
            sub+=(x3.y-x3.x) * (y3.y-y3.x);

    }

    ll T=(p[1].x-p[0].x)*(p[1].y-p[0].y);
    cout<<(T==(total-sub)?"NO":"YES");
}

/*
 *      1214C Solution
 *      Link : https://codeforces.com/problemset/problem/1214/C
 *      C. Bad Sequence
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    NeedForSpeed

    char pr;
    int n,invalid = 0, valid = 0;

    cin >> n;
   
    while (n--) {
        cin >> pr;
        if (pr == '(') {
            valid++;
        } else {
            if (valid > 0)
                valid--;
            else if(invalid==0)
                invalid++;
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    if (valid == invalid) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}
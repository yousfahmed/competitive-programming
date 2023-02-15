/*
 *     1428C Solution
 *      Link : https://codeforces.com/problemset/problem/1428/C
 *      C. ABBB
 *      By Abdelaleem Ahmed
 */

#include <bits/stdc++.h>
using namespace std;

char in;
int t = 1, ans;

inline void ReadIn(int &n) {
    for (in = getchar(); in > '9' || in < '0'; in = getchar());
    n = in - '0';
    for (in = getchar(); in >= '0' && in <= '9';in=getchar())
        n = n * 10 + (in - '0');
}

int main() {
    ReadIn(t);
    while (t--) {
        ans = 0;
        while (true) {
            in = getchar();
            if (in != 'A' && in != 'B')
                break;
            if (in == 'A')
                ans++;
            else if (ans > 0)
                ans--;
            else
                ans++;
        }
        printf("%d \n",ans);
    }
}
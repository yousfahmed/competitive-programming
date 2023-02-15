/*
 *      11239 - Open Source Solution
 *      Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2180
 *      11239 - Open Source
 *      By Abdelaleem Ahmed
 */
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed ios_base::sync_with_stdio(0);cin.tie(0);

inline bool cmp(pair<int, string>& a,pair<int, string>& b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first    ;
}

int main() {
    NeedForSpeed

    string in, proj;

    while (getline(cin, proj) && !isdigit(proj[0])) {

        unordered_map<string, int> projects;
        unordered_map<string, unordered_set<string>> stu;

        label1 :
        projects[proj];
        while (getline(cin, in) && !isdigit(in[0])) {
            if (islower(in[0])) {
                stu[in].insert(proj);
            } else {
                proj = in;
                goto label1;
            }
        }
        for (auto it:stu) {
            if (it.second.size() > 1)
                continue;
            projects[*it.second.begin()]++;
        }
        vector<pair<int, string>> ans;
        for (auto it : projects)
            ans.emplace_back(it.second, it.first);

        sort(ans.rbegin(), ans.rend(), cmp);

        for (auto it : ans)
            cout << it.second << " " << it.first << "\n";
    }
}

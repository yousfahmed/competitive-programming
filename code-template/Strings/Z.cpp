/* the max number of characters starting from the position  
i that coincide with the first characters of s  */
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vector<int> search(string& S, string &pat) {
  int N = S.size(), M = pat.size();
  string combined = pat + S;
  vector<int> Z = z_function(combined);
  vector<int> matches;
  for (int i = 0; i < N; i++) {
    if (Z[M + i] >= M) {
      matches.push_back(i);
    }
  }
  return matches;
}
struct SuffixArray {
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
  static const int lim = 128;
  int n;
  vi sa, lcp;
  vvi c, lcpQ;

  SuffixArray(string s) {
    constructSA(s);
    constructLCP(s);
  }

  void constructSA(string s) {
    // a sorted permutation suffixes
    // the equivalence classes of each suffix
    // cnt of each equivalence class
    // the permutation and equivalence classes of new iteration
    vi p, cnt, pn;
    s += '$';
    n = (int) s.size();
    int LG = __lg(n) + 2;
    c = vvi(LG, vi(n));
    p.resize(n);
    pn.resize(n);
    cnt.resize(max(lim, n));

    //perform counting sort on suffixes based on one character
    for (int i = 0; i < n; i++)
      cnt[s[i]]++;
    for (int i = 1; i < lim; i++)
      cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--)
      p[--cnt[s[i]]] = i;

    //calculate equivalence classes
    int classes = 1;
    c[0][p[0]] = classes - 1;
    for (int i = 1; i < n; i++) {
      if (s[p[i]] != s[p[i - 1]])
        ++classes;
      c[0][p[i]] = classes - 1;
    }

    //repeat above procedure but for substrings of length (1 << (h+1))
    for (int h = 0; (1 << h) < n; ++h) {
      //sort based on the second part
      for (int i = 0; i < n; i++) {
        pn[i] = p[i] - (1 << h);
        if (pn[i] < 0)
          pn[i] += n;
      }

      fill(cnt.begin(), cnt.begin() + classes, 0);
      //sort based on the first part
      for (int i = 0; i < n; i++)
        cnt[c[h][pn[i]]]++;
      for (int i = 1; i < classes; i++)
        cnt[i] += cnt[i - 1];
      for (int i = n - 1; i >= 0; i--)
        p[--cnt[c[h][pn[i]]]] = pn[i];

      classes = 1;
      c[h + 1][p[0]] = classes - 1;
      for (int i = 1; i < n; i++) {
        pair<int, int> cur = {c[h][p[i]], c[h][(p[i] + (1 << h)) % n]};
        pair<int, int> prev = {c[h][p[i - 1]], c[h][(p[i - 1] + (1 << h)) % n]};

        if (cur != prev)
          ++classes;
        c[h + 1][p[i]] = classes - 1;
      }
    }
    sa = p;
  }

  void constructLCP(string s) {
    //lcp between two adjacent suffixes in the suffix array
    lcp.resize(n, 0);
    // rank of the i-th suffix (by length)
    vi rnk(n);
    for (int i = 0; i < n; i++)
      rnk[sa[i]] = i;

    int k = 0;
    //iterating over suffixes by length
    for (int i = 0; i < n; i++) {
      if (rnk[i] == n - 1) {
        k = 0;
        continue;
      }

      int j = sa[rnk[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k])
        ++k;
      lcp[rnk[i]] = k;
      if (k)
        --k;
    }

    int K = __lg(n) + 1;
    lcpQ.resize(K, vi(n));
    for (int l = 0; l < K; l++) {
      for (int i = 0; i + (1 << l) - 1 < n; i++)
        if (l == 0)lcpQ[l][i] = lcp[i];
        else lcpQ[l][i] = min(lcpQ[l - 1][i], lcpQ[l - 1][i + (1 << (l - 1))]);
    }
  }

  int queryLCP(int l, int r) {
    if (l == r)return n - sa[l] - 1;
    --r;
    int len = r - l + 1;
    int k = __lg(len);
    return min(lcpQ[k][l], lcpQ[k][r - (1 << k) + 1]);
  }

  int compare(int i, int j, int len) {
    int lg = __lg(len);
    pii a = {c[lg][i], c[lg][(i + len - (1 << lg)) % n]};
    pii b = {c[lg][j], c[lg][(j + len - (1 << lg)) % n]};

    if (a < b)
      return -1;
    else if (a > b)
      return 1;
    else
      return 0;
  }

  int getLCP(int i, int j) {
    int ans = 0;
    for (int k = __lg(n); k >= 0; k--) {
      if (c[k][i] == c[k][j]) {
        ans += (1 << k);
        i = (i + (1 << k)) % n;
        j = (j + (1 << k)) % n;
      }
    }
    return ans;
  }

  bool subStringSearch(string &s, string &pat) {
    const int m = pat.size();
    int l = 0, r = sa.size() - 1;
    while (l <= r) {
      int md = (l + r) / 2;
      string t = s.substr(sa[md], min(n - sa[md], m));
      if (t == pat)return true;
      else if (t < pat) l = md + 1;
      else r = md - 1;
    }
    return false;
  }


#undef pii
#undef vvi
#undef vi
};

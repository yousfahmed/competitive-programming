// Longest plaindromic substring in O(n) time complexity
string manacher(string s) {
  // Preprocess the input so it can handle even length palindromes
  string arr;
  for (char i: s) {
    arr.push_back('#');
    arr.push_back(i);
  }
  arr.push_back('#');
  // dp[i] = palindrome's maximum diameter centered at i
  vector<int> dp(arr.size());
  int left = 0;
  int right = 0;
  int lg_max = 0;
  int idx = 0;
  for (int i = 0; i < arr.size();) {
    // Expand the palindrome around i
    while (left > 0 && right < arr.size() - 1 &&
           arr[left - 1] == arr[right + 1]) {
      left--;
      right++;
    }

    // Update the diameter
    dp[i] = right - left + 1;

    if (lg_max < dp[i]) {
      lg_max = dp[i];
      idx = i;
    }

    /*
     * We've already computed the values for [left, i] interval.
     * The values on the right side of the palindrome [i+1, right] will
     * be the same as the ones on the left side execpt when some palindromes
     * go beyond the current [left, right] palindrome.
     */
    int new_center = right + (i % 2 == 0 ? 1 : 0);
    for (int j = i + 1; j <= right; j++) {
      /*
       * i - (j - i) represents the mirror of j on the left side of the
       * palindrome. It's possible that the left mirror of j might go
       * beyond the current palindrome - it crosses the left border. To
       * avoid taking the wrong answer, take the minimum of the left
       * mirror of j and the diameter of palindrome centered at j ending
       * at right.
       */
      dp[j] = min(dp[i - (j - i)], 2 * (right - j) + 1);

      // Update the max diameter
      if (lg_max < dp[i]) {
        lg_max = dp[i];
        idx = i;
      }

      /*
       * If the palindrome centered at j reaches the right border of the
       * current palindrome it might go even beyond.
       * Considering this make the new_center = j.
       */
      if (j + dp[i - (j - i)] / 2 == right) {
        new_center = j;
        break;
      }
    }

    // Move to the new_center and update the left and right borders.
    i = new_center;
    right = i + dp[i] / 2;
    left = i - dp[i] / 2;
  }
  string ans = "";
  for (int j = idx - dp[idx] / 2; j <= idx + dp[idx] / 2; j++) {
    if (arr[j] != '#') { ans.push_back(arr[j]); }
  }
  return ans;
}
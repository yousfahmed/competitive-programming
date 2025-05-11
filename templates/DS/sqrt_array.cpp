/// Check this: https://atcoder.jp/contests/abc403/tasks/abc403_g

struct sqrt_array {
    const int B = 450;
  
    struct BLOCK {
    private:
      deque<int> q;
    public:
      /// Only related to the mentioned problem
      ll odd_sum = 0, even_sum = 0;
  
      void push_front(int x) {
        swap(odd_sum, even_sum);
        odd_sum += x;
        q.push_front(x);
      }
  
      void push_back(int x) {
        q.emplace_back(x);
        if (q.size() & 1) odd_sum += x;
        else even_sum += x;
      }
  
      int pop_front() {
        odd_sum -= q.front();
        swap(odd_sum, even_sum);
        int x = q.front();
        q.pop_front();
        return x;
      }
  
      int pop_back() {
        if (q.size() & 1) odd_sum -= q.back();
        else even_sum -= q.back();
        int x = q.back();
        q.pop_back();
        return x;
      }
  
      int back() { return q.back(); }
  
      int front() { return q.front(); }
  
      int size() { return q.size(); }
  
      void insert(int x) {
        static int inf = 1e9 + 5;
        vector<int> arr(q.begin(), q.end());
        q.clear();
        for (int i = 0; i < arr.size(); ++i) {
          if (x <= arr[i]) {
            q.emplace_back(x);
            --i, x = inf;
          } else {
            q.emplace_back(arr[i]);
          }
        }
        if (x != inf) q.emplace_back(x);
        odd_sum = even_sum = 0;
        for (int i = 0; i < q.size(); ++i) {
          if (i & 1) even_sum += q[i];
          else odd_sum += q[i];
        }
      }
  
      void erase(int x) {
        static int inf = 1e9 + 5;
        vector<int> arr(q.begin(), q.end());
        q.clear();
        for (int &i: arr) {
          if (x == i) {
            x = inf;
          } else {
            q.emplace_back(i);
          }
        }
        odd_sum = even_sum = 0;
        for (int i = 0; i < q.size(); ++i) {
          if (i & 1) even_sum += q[i];
          else odd_sum += q[i];
        }
      }
  
      int operator[](int i) { return q[i]; }
    };
  
    BLOCK blocks[10000];
  
    /// insert value on it's position to keep the values sorted
    void insert(int val) {
      for (int i = 0;; ++i) {
        if (blocks[i].size() < B or val <= blocks[i].back()) {
          blocks[i].insert(val);
          if (blocks[i].size() <= B)break;
          val = blocks[i].pop_back();
          for (++i;; ++i) {
            blocks[i].push_front(val);
            if (blocks[i].size() <= B)break;
            val = blocks[i].pop_back();
          }
          break;
        }
      }
    }
  
    /// zero-based array
    int operator[](int i) {
      ++i;
      for (int j = 0;; ++j) {
        if (blocks[j].size() >= i) {
          return blocks[j][i - 1];
        }
        i -= blocks[j].size();
      }
      assert(0);
      return 0;
    }
  
    /// erase one occurrence of `val`
    void erase(int val) {
      for (int i = 0; blocks[i].size(); ++i) {
        if (val <= blocks[i].back()) {
          blocks[i].erase(val);
          if (!blocks[i + 1].size())break;
          blocks[i].push_back(blocks[i + 1].pop_front());
          for (++i; blocks[i + 1].size(); ++i) {
            blocks[i].push_back(blocks[i + 1].pop_front());
          }
          break;
        }
      }
    }
  
  
    /// Only related to the mentioned problem
    ll ans() {
      ll ans = 0;
      int i = 0;
      for (auto &b: blocks) {
        if (!b.size())break;
        else if (~i & 1) ans += b.odd_sum;
        else ans += b.even_sum;
        i += b.size();
      }
      return ans;
    }
  
  };
  
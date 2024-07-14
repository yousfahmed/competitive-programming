#define ll long long
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

//Beware!!!here treap is 0-indexed
struct node {
  int val, sz, prior, lazy, mx, mn, repl;
  ll sum;
  bool repl_flag, rev;
  node *l, *r, *par;

  node() {
    lazy = 0;
    rev = 0;
    sum = 0;
    val = 0;
    sz = 0;
    mx = 0;
    mn = 0;
    repl = 0;
    repl_flag = 0;
    prior = 0;
    l = NULL;
    r = NULL;
    par = NULL;
  }

  node(int _val) {
    val = _val;
    sum = _val;
    mx = _val;
    mn = _val;
    repl = 0;
    repl_flag = 0;
    rev = 0;
    lazy = 0;
    sz = 1;
    prior = rnd();
    l = NULL;
    r = NULL;
    par = NULL;
  }
};

typedef node *pnode;

struct Treap {

  pnode root;
  map<int, pnode> position;//positions of all the values
  //clearing the treap
  void clear() {
    root = NULL;
    position.clear();
  }

  Treap() { clear(); }

  int size(pnode t) { return t ? t->sz : 0; }

  void update_size(pnode &t) { if (t) t->sz = size(t->l) + size(t->r) + 1; }

  void update_parent(pnode &t) {
    if (!t) return;
    if (t->l) t->l->par = t;
    if (t->r) t->r->par = t;
  }

  void lazy_sum_upd(pnode &t) {
    if (!t or !t->lazy) return;
    t->sum += t->lazy * size(t);
    t->val += t->lazy;
    t->mx += t->lazy;
    t->mn += t->lazy;
    if (t->l) t->l->lazy += t->lazy;
    if (t->r) t->r->lazy += t->lazy;
    t->lazy = 0;
  }

  //replace update
  void lazy_repl_upd(pnode &t) {
    if (!t or !t->repl_flag) return;
    t->val = t->mx = t->mn = t->repl;
    t->sum = t->val * size(t);
    if (t->l) {
      t->l->repl = t->repl;
      t->l->repl_flag = true;
    }
    if (t->r) {
      t->r->repl = t->repl;
      t->r->repl_flag = true;
    }
    t->repl_flag = false;
    t->repl = 0;
  }

  //reverse update
  void lazy_rev_upd(pnode &t) {
    if (!t or !t->rev) return;
    t->rev = false;
    swap(t->l, t->r);
    if (t->l) t->l->rev ^= true;
    if (t->r) t->r->rev ^= true;
  }

  //reset the value of current node assuming it now
  //represents a single element of the array
  void reset(pnode &t) {
    if (!t) return;
    t->sum = t->val;
    t->mx = t->val;
    t->mn = t->val;
  }

  //combine node l and r to form t by updating corresponding queries
  void combine(pnode &t, pnode l, pnode r) {
    if (!l) {
      t = r;
      return;
    }
    if (!r) {
      t = l;
      return;
    }
    //Beware!!!Here t can be equal to l or r anytime
    //i.e. t and (l or r) is representing same node
    //so operation is needed to be done carefully
    //e.g. if t and r are same then after t->sum=l->sum+r->sum operation,
    //r->sum will be the same as t->sum
    //so BE CAREFUL
    t->sum = l->sum + r->sum;
    t->mx = max(l->mx, r->mx);
    t->mn = min(l->mn, r->mn);
  }

  //perform all operations
  void operation(pnode &t) {
    if (!t) return;
    reset(t);
    lazy_rev_upd(t->l);
    lazy_rev_upd(t->r);
    lazy_repl_upd(t->l);
    lazy_repl_upd(t->r);
    lazy_sum_upd(t->l);
    lazy_sum_upd(t->r);
    combine(t, t->l, t);
    combine(t, t, t->r);
  }

  //split node t in l and r by key k
  //so first k+1 elements(0,1,2,...k) of the array from node t
  //will be split in left node and rest will be in right node
  void split(pnode t, pnode &l, pnode &r, int k, int add = 0) {
    if (t == NULL) {
      l = NULL;
      r = NULL;
      return;
    }
    lazy_rev_upd(t);
    lazy_repl_upd(t);
    lazy_sum_upd(t);
    int idx = add + size(t->l);
    if (t->l) t->l->par = NULL;
    if (t->r) t->r->par = NULL;
    if (idx <= k)
      split(t->r, t->r, r, k, idx + 1), l = t;
    else
      split(t->l, l, t->l, k, add), r = t;

    update_parent(t);
    update_size(t);
    operation(t);
  }

  //merge node l with r in t
  void merge(pnode &t, pnode l, pnode r) {
    lazy_rev_upd(l);
    lazy_rev_upd(r);
    lazy_repl_upd(l);
    lazy_repl_upd(r);
    lazy_sum_upd(l);
    lazy_sum_upd(r);
    if (!l) {
      t = r;
      return;
    }
    if (!r) {
      t = l;
      return;
    }

    if (l->prior > r->prior)
      merge(l->r, l->r, r), t = l;
    else
      merge(r->l, l, r->l), t = r;

    update_parent(t);
    update_size(t);
    operation(t);
  }


  bool exist;

  ///returns index of node curr
  int get_pos(pnode curr, pnode son = nullptr) {
    if (exist == 0) return 0;
    if (curr == NULL) {
      exist = 0;
      return 0;
    }
    if (!son) {
      if (curr == root) return size(curr->l);
      else return size(curr->l) + get_pos(curr->par, curr);
    }

    if (curr == root) {
      if (son == curr->l) return 0;
      else return size(curr->l) + 1;
    }

    if (curr->l == son) return get_pos(curr->par, curr);
    else return get_pos(curr->par, curr) + size(curr->l) + 1;
  }

  ///insert val in position a[pos]
  ///so all previous values from pos to last will be right shifted
  void insert(int pos, int val) {
    if (root == NULL) {
      pnode to_add = new node(val);
      root = to_add;
      position[val] = root;
      return;
    }

    pnode l, r, mid;
    mid = new node(val);
    position[val] = mid;

    split(root, l, r, pos - 1);
    merge(l, l, mid);
    merge(root, l, r);
  }

  ///erase from qL to qR indexes
  //so all previous indexes from qR+1 to last will be left shifted qR-qL+1 times
  void erase(int qL, int qR) {
    pnode l, r, mid;

    split(root, l, r, qL - 1);
    split(r, mid, r, qR - qL);
    merge(root, l, r);
  }

  ///returns answer for corresponding types of query [sum, max, min]
  int query(int qL, int qR) {
    pnode l, r, mid;

    split(root, l, r, qL - 1);
    split(r, mid, r, qR - qL);

    int answer = mid->sum; /// max,min ?
    merge(r, mid, r);
    merge(root, l, r);

    return answer;
  }

  ///add val in all the values from a[qL] to a[qR] positions
  void update(int qL, int qR, int val) {
    pnode l, r, mid;

    split(root, l, r, qL - 1);
    split(r, mid, r, qR - qL);
    lazy_repl_upd(mid);
    mid->lazy += val;

    merge(r, mid, r);
    merge(root, l, r);
  }

  ///reverse all the values from qL to qR
  void reverse(int qL, int qR) {
    pnode l, r, mid;

    split(root, l, r, qL - 1);
    split(r, mid, r, qR - qL);

    mid->rev ^= 1;
    merge(r, mid, r);
    merge(root, l, r);
  }

  ///replace all the values from a[qL] to a[qR] by v
  void replace(int qL, int qR, int v) {
    pnode l, r, mid;

    split(root, l, r, qL - 1);
    split(r, mid, r, qR - qL);
    lazy_sum_upd(mid);
    mid->repl_flag = 1;
    mid->repl = v;
    merge(r, mid, r);
    merge(root, l, r);
  }

  ///it will cyclic right shift the array k times
  ///so for k=1, a[qL]=a[qR] and all positions from ql+1 to qR will
  ///have values from previous a[qL] to a[qR-1]
  ///if you make left_shift=1 then it will to the opposite
  void cyclic_shift(int qL, int qR, int k, bool left_shift = 0) {
    if (qL == qR) return;
    k %= (qR - qL + 1);

    pnode l, r, mid, fh, sh;
    split(root, l, r, qL - 1);
    split(r, mid, r, qR - qL);

    if (left_shift == 0) split(mid, fh, sh, (qR - qL + 1) - k - 1);
    else split(mid, fh, sh, k - 1);
    merge(mid, sh, fh);

    merge(r, mid, r);
    merge(root, l, r);
  }

  ///returns index of the value
  ///if the value has multiple positions then it will
  ///return the last index where it was added last time
  ///returns -1 if it doesn't exist in the array
  int get_pos(int value) {
    if (position.find(value) == position.end()) return -1;
    exist = 1;
    int x = get_pos(position[value]);
    if (exist == 0) return -1;
    else return x;
  }

  /// access index in the array
  int get_val(int pos) {
    return query(pos, pos);
  }

  int size() {
    return size(root);
  }

  bool find(int val) {
    if (get_pos(val) == -1) return 0;
    else return 1;
  }

};

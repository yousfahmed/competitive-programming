#define all(s) s.begin(),s.end()
vector<int> moves; /// all possible moves
int mx, preSize, firstNode, cycleSize, start_node;

int nxt(int u) {
  int isWinning = 0;
  for (int m: moves) {
    if (u >> (mx - m) & 1)continue;
    isWinning = 1 << (mx - 1);
    break;
  }
  return (u >> 1) | isWinning;
}

int cycle_size(int mp) { //// meeting point
  int sz = 0, st = mp;
  do {
    sz++;
    mp = nxt(mp);
  } while (st != mp);
  return sz;
}

int detect_cycle(int st) {
  int h = st, t = st;
  do {
    t = nxt(t);
    h = nxt(nxt(h));
  } while (h != t);
  return h;
}

int first_node(int st, int mp) {
  preSize = 0;
  while (st != mp) {
    st = nxt(st);
    mp = nxt(mp);
    ++preSize;
  }
  return mp;
}

void floyd_cycle_finding(int st) {
  int mp = detect_cycle(st);
  cycleSize = cycle_size(mp);
  firstNode = first_node(st, mp);
}

void pre(vector<int> movs) {
  moves = movs;
  start_node = 0;
  mx = *max_element(all(moves));
  for (int i = 0; i < mx; ++i) {
    for (int m: moves) {
      int bit = i - m;
      if (bit < 0 || (start_node >> bit & 1)) continue;
      start_node |= (1 << i);
      break;
    }
  }
  floyd_cycle_finding(start_node);
}

int n_th_tile(int n) {
  if (n < mx) { //// inside the start node
    return start_node >> n & 1;
  }
  n -= mx - 1;
  int cur = start_node;
  for (int i = 0; n > 0 && i < preSize; ++i, --n) {
    cur = nxt(cur);
  }
  int rem = n % cycleSize;
  if (rem == 0) rem = cycleSize - 1;
  for (int i = 0; n > 0 && i < rem; ++i, --n) {
    cur = nxt(cur);
  }
  return cur >> (mx - 1) & 1;
}

int count_win_pos_up_to(int n) {
  ++n;
  int cnt = 0;
  for (int i = 0, cur = firstNode; i < cycleSize; ++i) {
    cnt += cur >> (mx - 1);
    cur = nxt(cur);
  }
  int res = 0;
  for (int i = 0; i < mx - 1 && n > 0; ++i, --n) {
    res += start_node >> i & 1;
  }
  for (int i = 0, cur = start_node; i < preSize && n > 0; ++i, --n) {
    res += cur >> (mx - 1);
    cur = nxt(cur);
  }
  res += n / cycleSize * cnt;
  int postCycle = n % cycleSize;
  for (int i = 0, cur = firstNode; i < postCycle; ++i) {
    res += cur >> (mx - 1);
    cur = nxt(cur);
  }
  return res;
}

struct mono_queue {
private:
  queue<int> main_queue;
  deque<int> min_queue;
public:
  void push(int x) {
    main_queue.push(x);
    while (!min_queue.empty() && x < min_queue.back()) {
      min_queue.pop_back();
    }
    min_queue.push_back(x);
  }

  int pop() {
    int n = main_queue.front();
    if (n == min_queue.front()) {
      min_queue.pop_front();
    }
    main_queue.pop();
    return n;
  }

  int get_min() { return min_queue.front(); }

  int front() { return main_queue.front(); }

  int size() { return main_queue.size(); }
};

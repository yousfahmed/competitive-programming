struct Line {
	mutable int k, m, p;

	bool operator<(const Line &o) const { return k < o.k; }

	bool operator<(int x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const int inf = LLONG_MAX;

	int div(int a, int b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b);
	}

	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}


	/// y = a(k) * x + b(m)
	void add(int k, int m) {
		/// to get the minimum k *= -1 , m *= -1; 
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	/// y = a(k) * x + b(m) => max y
	/// !! DON'T call it with negative (x)
	int query(int x) {
		assert(!empty());
		auto l = *lower_bound(x);
		/// to get the minimum return - answer;
		return l.k * x + l.m;
	}
};

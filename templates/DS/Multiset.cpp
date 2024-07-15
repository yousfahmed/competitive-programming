class Multiset {
private:
	//use with the positive number only and limited
	// so if you have a big or non-positive number you have to compress them
	vector<int> Bit;
	int SZ, size_set;

	void add(int pos, int val) {
		for (++pos; pos <= SZ; pos += pos & -pos)
			Bit[pos - 1] += val;
	}

	int get(int pos) {
		int ret = 0;
		for (++pos; pos; pos -= pos & -pos)
			ret += Bit[pos - 1];
		return ret;
	}

	int BS(int val) {
		int s = 0;
		for (int sz = SZ >> 1; sz; sz >>= 1) {
			if (Bit[s + sz - 1] < val)
				val -= Bit[(s += sz) - 1];
		}
		return s;
	}

public:
	Multiset() : size_set(0), SZ(1 << 20) {
		Bit.resize(SZ);
		add(0, -1);
	}

	void insert(int val) {
		++size_set;
		add(val, 1);
	}

	int count(int val) {
		return get(val) - get(val - 1);
	}

	/// erase all occurrence of val in the multiset
	void erase_all(int val) {
		int c = count(val);
		size_set -= c;
		add(val, -c);
	}

	void erase_idx(int index) {
		--size_set;
		add(BS(index), -1);
	}

	int order_of_key(int val) {//get_val_idx //freq(numbers)<val
		return get(val) - count(val) + 1;
	}

	int operator[](int index) { return BS(index); }

	int size() const { return size_set; }

};

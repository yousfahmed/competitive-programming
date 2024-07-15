const int LG = 11;

template<typename T, class CMP = function<T(const T &, const T &)>>
struct SP2d {
	CMP func;
	int m, n;
	vector<vector<int>> sp[LG][LG];

	SP2d(const vector<vector<T>> &arr, const CMP &f) : func(f) {
		n = arr.size(), m = arr[0].size();
		for (int i = 0; i < LG; ++i) {
			for (int j = 0; j < LG; ++j) {
				sp[i][j].assign(n, vector<int>(m));
			}
		}
		for (int ir = 0; ir < n; ++ir) {
			for (int ic = 0; ic < m; ++ic)
				sp[0][0][ir][ic] = arr[ir][ic];
		}
		for (int a = 0; a < LG; a++) {
			for (int b = 0; b < LG; b++) {
				if (a + b == 0) continue;
				for (int i = 0; i + (1 << a) <= n; i++) {
					for (int j = 0; j + (1 << b) <= m; j++) {
						if (!a) {
							sp[a][b][i][j] = func(
									sp[a][b - 1][i][j],
									sp[a][b - 1][i][j + (1 << (b - 1))]
							);
						} else {
							sp[a][b][i][j] = func(
									sp[a - 1][b][i][j],
									sp[a - 1][b][i + (1 << (a - 1))][j]
							);
						}
					}
				}
			}
		}
	}

	T query(int x1, int y1, int x2, int y2) {
		int lgX = __lg(x2 - x1 + 1);
		int lgY = __lg(y2 - y1 + 1);
		T val1 = func(
				sp[lgX][lgY][x1][y1],
				sp[lgX][lgY][x1][y2 - (1 << lgY) + 1]
		);
		T val2 = func(
				sp[lgX][lgY][x2 - (1 << lgX) + 1][y1],
				sp[lgX][lgY][x2 - (1 << lgX) + 1][y2 - (1 << lgY) + 1]
		);
		return func(val1, val2);
	}
};

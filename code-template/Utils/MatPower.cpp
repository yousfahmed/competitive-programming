
/*
 * steps to solve matrix power problems
 * write iterative dp with memory reduction
 * lets say i want to write
 * new_dp[x] = 3*dp[i-1]
 * int the transition matrix this is equal to
 * trans[i-1][x] =3;
 *
 * to keep old value of a number make a cycle for example let
 * we want to get sum of all number at most k
 * we add extra row let it's index be n and answer of f(n) at row(n-1)
 * so we want each time increase dp[n] by dp[n-1]
 * new_dp[n] = dp[n-1] +dp[n]
 * so we can write it like this
 * trans[n][n] =1 ,this mean add the old of dp[n],
 * trans[n-1][n]= 1 --> new_dp[n]+=dp[n-1]
 *
 *
 * to add constant number p to dp[n-1]
 * answer is at dp[n-1] and p is at n
 * trans[n][n] = 1;//dp[n]=1
 * trans[n][n - 1] = p;//dp[n-1]+=p
 *
 * to add i*q for loop in matrix
 * trans[n + 1][n + 1] = 1;//new_dp[n+1]=dp[n+1]
 * trans[n][n] = 1;//dp[n]=1
 * trans[n][n + 1] = 1;//new_dp[n+1]+=1
 * trans[n + 1][n - 1] = q;//new_dp[n-1]+=i*q
 *
 * //i*i*r
 * trans[n + 2][n + 2] = 1;
 * trans[n + 1][n + 2] = 2;
 * trans[n][n + 2] = 1;
 * trans[n + 2][n - 1] = r;
 */
typedef vector<ll> row;
typedef vector<row> mat;

mat operator*(const mat &a, const mat &b) {
 int r1 = a.size(), r2 = b.size(), c2 = b[0].size();
 mat ret(r1, row(c2));
 for (int i = 0; i < r1; i++)
 for (int j = 0; j < c2; j++)
 for (int k = 0; k < r2; k++)
 ret[i][j] += a[i][k] * b[k][j], ret[i][j] %= mod;
 return ret;
}

mat operator^(const mat &a, ll k) {
 mat ret(a.size(), row(a.size()));
 for (int i = 0; i < a.size(); i++)ret[i][i] = 1;
 for (mat tmp = a; k; tmp = tmp * tmp, k /= 2)if (k & 1)ret = ret * tmp;
 return ret;
}
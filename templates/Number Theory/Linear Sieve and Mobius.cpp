vi prime;
bool isComp[N];
int mob[N];
 
void sieve(int n = N) {
    fill(isComp, isComp + n, false);
    mob[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!isComp[i]) {
            prime.push_back(i);
            mob[i] = -1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] < n; ++j) {
            isComp[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mob[i * prime[j]] = 0;
                break;
            } else
                mob[i * prime[j]] = mob[i] * mob[prime[j]];
        }
    }
}
 

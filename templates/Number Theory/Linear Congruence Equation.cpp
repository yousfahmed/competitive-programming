
//from kactl, if a and b are co-prime, x is a inv % b
ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

//solves (a * x = b) % m
//returns x in range [0, m-1] if sol exists or -1 if it doesn't
//returns what to increment to get other answers
void congruence_equation(ll a, ll b, ll m, ll& x, ll& inc){
    ll g = __gcd(a, m);
    // no solution
    if(b % g){
        x = -1; inc = m;
        return;
    }

    //not co-prime
    if(g == 1){
        ll aInv, y;
        euclid(a, m, aInv, y);
        aInv = (aInv + m) % m;
        x = aInv * b % m;
        inc = m;
        return;
    }

    //not co-prime but sol exists
    congruence_equation(a/g, b/g, m/g, x, inc);
}

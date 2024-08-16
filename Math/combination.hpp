struct CMB {  // must素数
    using vl = vec<ll>;
    vl fac;
    vl ifac;
    vl inv;
    ll mb = 0;
    int N;

    CMB(int r, ll _mod)
        : mb(_mod), N(r + 1), fac(r + 1, 1), ifac(r + 1, 1), inv(r + 1, 1) {
        rep(i, 2, N) {
            fac[i] = fac[i - 1] * i % mb;
            inv[i] = mb - inv[mb % i] * (mb / i) % mb;
            ifac[i] = ifac[i - 1] * inv[i] % mb;
        }
    }

    ll C(int n, int k) {
        if (n < k) return 0LL;
        if (n < 0 || k < 0) return 0LL;
        return fac[n] * (ifac[k] * ifac[n - k] % mb) % mb;
    }

    ll B(int n) { return fac[n]; }

    ll invB(int n) { return ifac[n]; }

    ll H(int n, int k) { return C(n + k - 1, k); }

    ll Cn(int n) { return C(2 * n, n) * inv[n + 1] % mb; }
};
/*
@brief コンビネーション
@docs doc/cmb.md
*/
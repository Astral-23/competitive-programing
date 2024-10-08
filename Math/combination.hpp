TT struct CMB {  // must素数
    ll mb;
    vec<ll> fac, ifac, inv;

    CMB(ll MAX_N, ll mod)
        :  mb(mod), fac(MAX_N + 1, 1), ifac(MAX_N + 1, 1), inv(MAX_N + 1, 1) {
        for (ll i = 2; i <= MAX_N; i++) {
            fac[i] = fac[i - 1] * i % mb;
            inv[i] = mb - inv[mb % i] * (mb / i) % mb;
            ifac[i] = ifac[i - 1] * inv[i] % mb;
        }
    }

    T P(int n, int k) {
        if(n < k) return 0LL;
        if(n < 0 || k < 0) return 0LL;
        return fac[n] * ifac[n - k] % mb;
    }

    T C(int n, int k) {
        if (n < k) return 0LL;
        if (n < 0 || k < 0) return 0LL;
        return fac[n] * (ifac[k] * ifac[n - k] % mb) % mb;
    }

    T B(int n) { return (n < 0 ? 0 : fac[n]); }

    T invB(int n) { return (n < 0 ? 0 : ifac[n]); }

    T H(int n, int k) { return C(n + k - 1, k); }

    T Cn(int n) { return C(2 * n, n) * inv[n + 1] % mb; }
};
/*
@brief コンビネーション
@docs doc/cmb.md
*/
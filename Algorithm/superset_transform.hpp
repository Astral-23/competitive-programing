template<class S, S (*op)(S, S)> vector<S> superset_zeta_transform (vector<S> f, int n) {
    rep(i, 0, n) {
        rep(s, 0, 1LL << n) {
            if((s & (1 << i)) == 0) { // if i in s
                f[s] = op(f[s], f[s ^ (1 << i)]);
            }
        }
    }
    return f;
}

template<class S, S (*op)(S, S), S (*inv)(S)> vector<S> superset_mobius_transform (vector<S> f, int n) {
    rrep(i, 0, n) {
        rep(s, 0, 1LL << n) {
            if((s & (1 << i)) == 0) { // if i in s
                f[s] = op(f[s], inv(f[s ^ (1 << i)]));
                //f[s] = f[s] -  f[s ^ (1 << i)];
            }
        }
    }
    return f;
}
struct RNG {
    mt19937_64 mt;
    RNG() {mt = mt19937_64(clock());}

    int rndint(int l, int r) { return mt()%(r-l+1)+l; }
    ll rndll(ll l, ll r) { return mt()%(r-l+1)+l; }
    TT vec<T> rvec(int n, T l, T r) {
        vec<T> res(n);
        for(T& x : res) x = rndll(l, r);
        return res;
    }

    string rstr(int n, char l, char r) {
        string res;
        rep(i, 0, n) res += l + rndint(0, r-l);
        return res;
    }
    
};

TT struct static1dsum {
    int n;
    vec<T> dat;
    bool f = false;

    static1dsum(int N) : n(N) {
        dat = vec<T>(n, 0);
    }

    void add(int i, T x) {
        assert(!f);
        dat[i] += x;
    }

    void imos_add(int i, T x) {
        add(i, x);
    }

    void imos_add(int l, int r, T x) {
        assert(!f);
        chmax(l, 0); 
        chmin(r, n);
        if(l >= r) return;
        dat[l] += x;
        if(r < n) dat[r] -= x;
        return;
    }

    void build() {
        rep(i, 0, n-1) dat[i+1] += dat[i];
        f = true;
    }

    T get(int i) {
        assert(f);
        assert(0 <= i && i < n);
        return dat[i];
    }

    T imos_get(int i) {
        return prod(0, i+1);
    }

    T prod(int l, int r) {
        assert(f);
        assert(l >= 0);
        assert(r <= n);
        assert(l <= r);
        T res = dat[r-1];
        if(l) res -= dat[l-1];
        return res;
    }

};

/*
@brief 1次元累積和
@doc docs/static1dsum.md


*/

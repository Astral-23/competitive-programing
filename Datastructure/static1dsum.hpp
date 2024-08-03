TT struct static1dsum {
    int n;
    vec<T> dat;
    bool built = false;

    static1dsum(int n = 0) : static1dsum(vec<T>(n, T())) {}

    static1dsum(vec<T> dat) : n(dat.size()), dat(dat) {}

    void add(int i, T x) {
        assert(!built);
        dat[i] += x;
    }

    void build() {
        rep(i, 0, n - 1) dat[i + 1] += dat[i];
        built = true;
    }

    T operator[](int i) const {
        assert(built == true);
        assert(0 <= i && i < n);
        return prod(i, i + 1);
    }

    T prod(int l, int r) {
        assert(built);
        assert(0 <= l && r <= n);
        assert(l <= r);
        T res = dat[r - 1];
        if (l) res -= dat[l - 1];
        return res;
    }
};



/*
@brief 1次元累積和
@docs doc/static1dsum.md
*/
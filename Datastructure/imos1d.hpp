TT struct imos1d {
    int n;
    vec<T> dat;
    bool built = false;

    imos1d(int n = 0) : n(n) { dat.resize(n, T()); }

    void imos_add(int i, T x) {
        assert(built == false);
        assert(0 <= i && i < n);
        dat[i] += x;
        if(i + 1 < n) dat[i + 1] -= x;
    }

    void imos_add(int l, int r, T x) {
        assert(0 <= l && r <= n && l <= r);
        dat[l] += x;
        if (r < n) dat[r] -= x;
    }

    void build() {
        rep(i, 0, n - 1) dat[i + 1] += dat[i];
        built = true;
    }

    T operator[](int i) const {
        assert(built == true);
        assert(0 <= i && i < n);
        return dat[i];
    }
};

/*
@bried 1次元imos法
*/
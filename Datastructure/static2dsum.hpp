TT struct static2dsum {
    int h, w;
    vec<vec<T>> dat;
    bool f = false;

    static2dsum(int h = 0, int w = 0)
        : static2dsum(vec<vec<T>>(h, vec<T>(w, T()))) {}

    static2dsum(vec<vec<T>> dat) : dat(dat) {
        h = dat.size();
        if (h)
            w = dat[0].size();
        else
            w = 0;
    }

    void add(int i, int j, T x) {
        assert(!f);
        dat[i][j] += x;
    }


    void build() {
        rep(i, 0, h) {
            rep(j, 0, w - 1) { dat[i][j + 1] += dat[i][j]; }
        }

        rep(j, 0, w) {
            rep(i, 0, h - 1) { dat[i + 1][j] += dat[i][j]; }
        }

        f = true;
    }

    T prod(int sy, int ty, int sx, int tx) {
        assert(f);
        assert(0 <= sy && ty <= h);
        assert(0 <= sx && tx <= w);
        assert(sy <= ty);
        assert(sx <= tx);
        tx--, ty--;
        T res = dat[ty][tx];
        if (sx > 0) res -= dat[ty][sx - 1];
        if (sy > 0) res -= dat[sy - 1][tx];
        if (sx > 0 && sy > 0) res += dat[sy - 1][sx - 1];
        return res;
    }
};
/*
@brief 2次元累積和
@docs doc/static2dsum.md
*/
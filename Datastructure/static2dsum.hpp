TT struct static2dsum {
    int h, w;
    vec<vec<T>> dat;
    bool f = false;

    static2dsum(int H, int W) : h(H), w(W) {
        dat = vec<vec<T>>(h, vec<T>(w, 0));
    }

    void add(int i, int j, T x) {
        assert(!f);
        dat[i][j] += x;
    }

    void imos_add(int i, int j, T x) {
        add(i, j, x);
    }

    void imos_add(int sy, int ty,  int sx, int tx, T x) {
        assert(!f);
        chmax(sx, 0); chmax(sy, 0);
        chmin(tx, w); chmin(ty, h);
        if(sx >= tx || sy >= ty) return;
        dat[sy][sx] += x;
        if(ty < h) dat[ty][sx] -= x;
        if(tx < w) dat[sy][tx] -= x;
        if(tx < w && ty < h) dat[ty][tx] += x;
        return;
    }

    void build() {
        rep(i, 0, h) {
            rep(j, 0, w-1) {
                dat[i][j+1] += dat[i][j];
            }
        }

        rep(j, 0, w) {
            rep(i, 0, h-1) {
                dat[i+1][j] += dat[i][j];
            }
        }

        f = true;
    }

    T imos_get(int i, int j) {
        return prod(0, i+1, 0, j+1);
    }

    T get(int i, int j) {
        assert(f);
        assert(0 <= i && i < h);
        assert(0 <= j && j < w);
        return dat[i][j];
    }

    T prod(int sy, int ty, int sx, int tx) {
        assert(f);
        assert(sy >= 0); assert(ty <= h);
        assert(sx >= 0); assert(tx <= w);
        assert(sy <= ty); assert(sx <= tx);
        if(sx >= tx || sy >= ty) return 0;
        tx--, ty--;
        T res = dat[ty][tx];
        if(sx > 0) res -= dat[ty][sx-1];
        if(sy > 0) res -= dat[sy-1][tx];
        if(sx > 0 && sy > 0) res += dat[sy-1][sx-1];
        return res;
    }
};
/*
@brief 2次元累積和
@doc docs/static2dsum.md
*/
TT struct imos2d {
    int h, w;
    vec<vec<T>> dat;
    bool f = false;

    imos2d(int h = 0, int w = 0) : h(h), w(w) {
        dat = vec<vec<T>>(h, vec<T>(w, T()));
    }

    void imos_add(int i, int j, T x) {
        assert(f == false);
        imos_add(i, i + 1, j, j + 1, x);
    }

    void imos_add(int sy, int ty, int sx, int tx, T x) {
        assert(f == false);
        if (sx >= tx || sy >= ty) return;
        dat[sy][sx] += x;
        if (ty < h) dat[ty][sx] -= x;
        if (tx < w) dat[sy][tx] -= x;
        if (tx < w && ty < h) dat[ty][tx] += x;
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

    T imos_get(int i, int j) { return dat[i][j]; }
};
/*
@brief 2次元imos法

*/
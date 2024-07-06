TT struct bit2d {
    int h, w;
    vec<vec<T>> dat;

    bit2d(int H, int W) : h(H), w(W) {
        dat = vec<vec<T>>(h, vec<T>(w, 0));
    }

    void add(int y, int x, T v) {
        assert(0 <= y && y < h);
        assert(0 <= x && x < w);
        for( ; y < h; y |= y + 1) {
            for(int b = x; b < w; b |= b + 1) {
                dat[y][b] += v;
            }
        }
    }

    void imos_add(int y, int x, T v) {
        add(y, x, v);
    }

    void imos_add(int sy, int ty, int sx, int tx, T v) {
        chmax(sy, 0);
        chmax(sx, 0); chmax(sy, 0);
        chmin(tx, w); chmin(ty, h);
        if(sx >= tx || sy >= ty) return;
        add(sy, sx, v);
        if(ty < h && tx < w) add(ty, tx, v);
        if(ty < h) add(ty, sx, -v);
        if(tx < w) add(sy, tx, -v);
    }

    T prod(int y, int x) {
        T res = 0;
        y--, x--;
        for( ; y >= 0; y = (y & (y + 1)) - 1) {
            for(int b = x; b >= 0; b = (b & (b + 1)) - 1) {
                res += dat[y][b];
            }
        }
        return res;
    }

    T prod(int sy, int ty, int sx, int tx) {
        assert(sy >= 0); assert(sx >= 0);
        assert(ty <= h); assert(tx <= w);
        T res = prod(ty, tx);
        res -= prod(sy, tx);
        res -= prod(ty, sx);
        res += prod(sy, sx);
        return res;
    }

    T imos_get(int y, int x) {
        return prod(0, y+1, 0, x+1);
    }
};
/*
@brief 2dbit
@docs doc/2dbit.md
*/
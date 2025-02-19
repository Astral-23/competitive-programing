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

    T prod(int y, int x) const {
        T res = 0;
        y--, x--;
        for( ; y >= 0; y = (y & (y + 1)) - 1) {
            for(int b = x; b >= 0; b = (b & (b + 1)) - 1) {
                res += dat[y][b];
            }
        }
        return res;
    }

    T prod(int sy, int ty, int sx, int tx) const {
        assert(0 <= sy && sy <= ty && ty <= h);
        assert(0 <= sx && sx <= tx && tx <= w);

        T res = prod(ty, tx);
        res -= prod(sy, tx);
        res -= prod(ty, sx);
        res += prod(sy, sx);
        return res;
    }
};
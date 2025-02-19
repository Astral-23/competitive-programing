TT struct static2dsum {
    int id(int i, int j) const {
        return i * (w + 1) + j;
    }
    int h, w;
    vector<T> d;
    bool built = false;

    static2dsum(int h = 0, int w = 0)
        : static2dsum(vector<vector<T>>(h, vector<T>(w, T()))) {
    }

    static2dsum(vec<vec<T>> const &dat) {
        h = dat.size();
        if (h)
            w = dat[0].size();
        else
            w = 0;
        d.resize((h + 1) * (w + 1), 0);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                d[id(i + 1, j + 1)] = dat[i][j];
            }
        }
    }
    void add(int i, int j, T x) {
        assert(built == false);
        d[id(i + 1, j + 1)] += x;
    }

    void build() {
        assert(built == false);
        for (int i = 0; i <= h; ++i) {
            for (int j = 0; j < w; ++j) {
                d[id(i, j + 1)] += d[id(i, j)];
            }
        }

        for (int j = 0; j <= w; ++j) {
            for (int i = 0; i < h; ++i) {
                d[id(i + 1, j)] += d[id(i, j)];
            }
        }

        built = true;
    }

    T get(int y, int x) const {
        assert(built);
        assert(0 <= y && y < h);
        assert(0 <= x && x < w);
        return prod(x, x + 1, y, y + 1);
    }

    T prod(int sx, int tx, int sy, int ty) const {
        assert(built);
        assert(0 <= sy && sy <= ty && ty <= h);
        assert(0 <= sx && sx <= tx && tx <= w);

        T res = d[id(ty, tx)];
        res -= d[id(sy, tx)];
        res -= d[id(ty, sx)];
        res += d[id(sy, sx)];
        return res;
    }
};
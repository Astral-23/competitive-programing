template <class S, S (*op)(S, S), S (*e)()> struct segtree2d {
    int id(int y, int x) {return y * 2 * W + x;} //= y番目のセグ木の、ノードxに対応する添字
    int H, W;
    vec<S> dat;
    bool f;

    segtree2d(int h, int w) {
        f = true;
        H = W = 1;
        while(H < h) H <<= 1;
        while(W < w) W <<= 1;
        dat.resize(4 * H * W, e());
    }

    void preset(int y, int x, S v) {f = false,  dat[id(y + H, x + W)] = v; }

    void build() {
        f = true;
        rep(h, H, 2 * H) {
            rrep(w, 1, W) {
                dat[id(h, w)] = op(dat[id(h, 2 * w)], dat[id(h, 2 * w + 1)]);
            }
        }
        
        rrep(h, 0, H) {
            rrep(w, 1, 2 * W) {
                dat[id(h, w)] = op(dat[id(h * 2, w)], dat[id(h * 2 + 1, w)]);
            } 
        }
    }

    void set(int y, int x, S v) {
        assert(f);

        y += H, x += W;
        dat[id(y, x)] = v;
        rrep(w, 1, W) {
            dat[id(y, w)] = op(dat[id(y, 2 * w)], dat[id(y, 2 * w + 1)]);
        }

        while(y > 1) {
            y >>= 1;
            for(int j = x; j >= 1; j >>= 1) {
                dat[id(y, j)] = op(dat[id(y * 2, j)] , dat[id(y * 2 + 1, j)]);
            }
        }
    }

    S inner(int h, int l, int r) {
        S sml = e(), smr = e();
        l += W, r += W;
        while(l < r) {
            if(l & 1) sml = op(sml, dat[id(h, l++)]);
            if(r & 1) smr = op(dat[id(h, --r)], smr);
            l >>= 1, r >>= 1;
        }
        return op(sml, smr);
    }

    S prod(int sy, int ty, int sx, int tx) {
        assert(f);

        S sml = e(), smr = e();
        sy += H, ty += H;
        while(sy < ty) {
            if(sy & 1) sml = op(sml, inner(sy++, sx, tx));
            if(ty & 1) smr = op(inner(--ty, sx, tx), smr);
            sy >>= 1, ty >>= 1;
        }
        return op(sml, smr);
    }

    S get(int y, int x) {
        return dat[id(y + H, x + W)];
    }
};
/*
@brief 2次元セグメント木
@docs doc/2dseg_small.md
*/
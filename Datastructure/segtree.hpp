template <class S, S (*op)(S, S), S (*e)()> struct segtree {
    int n;
    int sz;
    vector<S> d;

    segtree(int n) : segtree(vector<S>(n, e())) {}

    segtree(const vector<S> &v) : n((int)v.size()), sz(1) {
        while(sz < n) sz <<= 1;
        d.resize(2*sz, e());
        rep(i, 0, n) {
            d[sz+i] = v[i];
        }
        rrep(i, 1, sz) d[i] = op(d[i<<1], d[i<<1|1]);
    }

    void set(int p, S x) {
        assert(0 <= p && p < n);
        p += sz;
        d[p] = x;
        while(p > 1) {
            p >>= 1;
            d[p] = op(d[p<<1], d[p<<1|1]);
        }
    }

    S get(int p) const {
        assert(0 <= p && p < n);
        return d[p + sz];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        S sml = e(), smr = e();
        l += sz;
        r += sz;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if (l == n) return n;
        l += sz;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < sz) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= n);
        assert(f(e()));
        if (r == 0) return 0;
        r += sz;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < sz) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
    
};
/*
@brief segtree
@docs doc/segtree.md
*/
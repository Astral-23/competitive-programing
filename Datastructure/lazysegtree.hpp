template<class S, S (*op)(S, S), S (*e)(), class F, S (*mp)(F, S), F (*cm)(F, F), F (*id)()>
struct lazysegtree {
    int n;
    int sz;
    int log;
    vec<S> d;
    vec<F> lz;
    lazysegtree(int n) : lazysegtree(vec<S>(n, e())) {}
    lazysegtree(const vec<S> &v) : n((int)(v.size())) {
        log = 1;
        while((1 << log) < n) log++;
        sz = 1 << log;
        d.resize(2*sz, e());
        lz.resize(2*sz, id());
        rep(i, 0, n) d[sz+i] = v[i];
        rrep(i, 1, sz) update(i);
    }

    void update(int i) {
        d[i] = op(d[i<<1], d[i<<1|1]);
    }

    void all_apply(int i, F f) {
        d[i] = mp(f, d[i]);
        if(i < sz) lz[i] = cm(f, lz[i]);
    }

    void push(int k) {
        all_apply(k * 2, lz[k]);
        all_apply(k * 2 + 1, lz[k]);
        lz[k] = id();
    }

    S prod(int l, int r, int k = 1, int L = 0, int R = -1) {
        if(R == -1) R = sz;
        if(r <= L || R <= l) return e();
        if(l <= L && R <= r) return d[k];
        push(k);
        int M = (L + R) / 2;
        return op(prod(l, r, k * 2, L, M), prod(l, r, k * 2 + 1, M, R));
    }

    void apply(int l, int r, F f, int k = 1, int L = 0, int R = -1) {
        if(R == -1) R = sz;
        if(r <= L || R <= l) return;
        if(l <= L && R <= r) {
            all_apply(k, f);
            return;
        }
        push(k);
        int M = (L + R) / 2;
        apply(l, r, f, k * 2, L, M); apply(l, r, f, k * 2 + 1, M, R);
        update(k);
    }
    
    //以下、必要になったら書く（全て独立)

    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= n);
        assert(g(e()));
        if (l == n) return n;
        l += sz;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < sz) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

   
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= n);
        assert(g(e()));
        if (r == 0) return 0;
        r += sz;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < sz) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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


    void set(int p, S x) {
        assert(0 <= p && p < n);
        p += sz;
        rrep(i, 1, log+1) push(p >> i);
        d[p] = x;
        rep(i, 1, log+1) update(p >> i);
    }

    S all_prod() { return d[1]; }

    S get(int p) {
        assert(0 <= p && p < n);
        p += sz;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    void apply(int p, F f) {
        assert(0 <= p && p < n);
        p += sz;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    
};
    
/*
@brief lazysegtree
@docs doc/lazysegtree.md
*/
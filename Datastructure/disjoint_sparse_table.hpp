template <class S, S (*op)(S, S), S (*e)()> struct disjoint_sparse_table {
    vector<vector<S>> d;
    bool built = false;
    int n, lg;
    vector<S> v;

  private:
    int msb(int x) const { return x == 0 ? -1 : 32 - __builtin_clz(x) - 1; }

    // 潰れた区間もダメ
    S prod_assertless(int l, int r) const {
        if (r - l == 1) return v[l];
        r--;
        int k = msb(l ^ r);
        return op(d[k][l], d[k][r]);
    }

  public:
    disjoint_sparse_table(){}
    disjoint_sparse_table(int n) : disjoint_sparse_table(vector<S>(n, e())) {}
    disjoint_sparse_table(vector<S> const &dat)
        : n(int(dat.size())), lg(0), v(dat) {
        while ((1 << lg) < n) {
            lg++;
        }
        v.resize(1 << lg, e());
    }

    void build() {
        built = true;
        int sz = 1 << lg;
        d.resize(lg, vector<S>(sz, e()));
        for (int k = 0; k < lg; k++) {
            int b = 1 << k;
            for (int mid = b; mid + b <= sz; mid += 2 * b) {
                S sml = e(), smr = e();
                for (int l = mid - 1; l >= mid - b; l--) {
                    sml = op(v[l], sml);
                    d[k][l] = sml;
                }
                for (int r = mid; r < mid + b; r++) {
                    smr = op(smr, v[r]);
                    d[k][r] = smr;
                }
            }
        }
    }

    void set(int i, S const &value) {
        assert(built == false);
        assert(0 <= i && i < n);
        v[i] = value;
    }

    S get(int i) const {
        assert(built);
        return v[i];
    }
    S prod(int l, int r) const {
        assert(built);
        assert(0 <= l && l <= r && r <= n);
        if (r == l) return e();
        if (r - l == 1) return v[l];
        r--;
        int k = msb(l ^ r);
        return op(d[k][l], d[k][r]);
    }

    template <class F> int max_right(int l, F f) const {
        assert(built);
        assert(f(e()));
        if (l == n) return n;
        int ok = l;
        int ng = n;
        while ((ng - ok) > 1) {
            int mi = (ok + ng) / 2;
            if (f(prod_assertless(l, mi))) {
                ok = mi;
            } else {
                ng = mi;
            }
        }
        return ok;
    };

    template <class F> int min_left(int r, F f) const {
        assert(built == true);
        assert(f(e()));
        if (r == 0) return 0;
        int ok = r;
        int ng = -1;
        while ((ok - ng) > 1) {
            int mi = (ok + ng) / 2;
            if (f(prod_assertless(mi, r))) {
                ok = mi;
            } else {
                ng = mi;
            }
        }
        return ok;
    }
};
/*
@brief disjoint_sparse_table
*/
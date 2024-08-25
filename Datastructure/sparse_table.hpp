template <class S, S (*op)(S, S), S (*e)()> struct sparse_table {
    vector<vector<S>> d;
    vector<int> lookup;
    bool built = false;
    int n, lg;
    vector<S> v;

    sparse_table(int n) : n(n), v(n, e()) {}

    sparse_table(const vector<S> &v) : n(v.size()), v(v) {}

    void set(int i, S x) {
        assert(0 <= i && i < n);
        assert(built == false);
        v[i] = x;
    }

    void build() {
        n = v.size();
        lg = 0;
        while ((1LL << lg) <= n) lg++;
        d.resize(lg, vector<S>(1LL << lg, e()));
        for (int i = 0; i < n; i++) {
            d[0][i] = v[i];
        }
        for (int i = 1; i < lg; i++) {
            for (int j = 0; j + (1LL << i) <= (1LL << lg); j++) {
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1LL << (i - 1))]);
            }
        }
        lookup.resize(n + 1);
        for (int i = 2; i < int(lookup.size()); i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
        built = true;
    }

    S get(int i) {
        assert(0 <= i && i < n);
        return v[i];
    }

    S prod(int l, int r) {
        assert(built == true);
        assert(0 <= l && r <= n);
        if (l >= r) return e();
        int LG = lookup[r - l];
        return op(d[LG][l], d[LG][r - (1LL << LG)]);
    }
};

/*
@brief sparse_table
*/
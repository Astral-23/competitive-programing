template <class S, S (*op)(S, S), S (*e)()> struct sparse_table {
    vector<vector<S>> d;
    vector<int> lookup;
    bool built = true;

    sparse_table() {}

    sparse_table(const vector<S> &v) {
        int n = v.size();
        int lg = 0;
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
    }

    S prod(int l, int r) {
        assert(l <= r);
        if (l == r) return e();
        int lg = lookup[r - l];
        return op(d[lg][l], d[lg][r - (1LL << lg)]);
    }
};
/*
@brief sprase_table
*/
template <typename T> struct Matrix {
    int h, w;
    vector<vector<T>> d;
    Matrix() {}
    Matrix(int h, int w, T val = 0) : h(h), w(w), d(h, vector<T>(w, val)) {}
    Matrix(vector<vector<T>> const &dat) : h(dat.size()), w(0), d(dat) {
        if (h > 0) w = d[0].size();
    }

    static Matrix unit(int n) {
        Matrix uni(n, n, 0);
        for (int i = 0; i < n; i++) {
            uni[i][i] = 1;
        }
        return uni;
    }
    const vector<T> &operator[](int i) const { return d[i]; }
    vector<T> &operator[](int i) { return d[i]; }
    Matrix &operator*=(const Matrix &a) { return *this = (*this) * a; }
    Matrix operator*(const Matrix &a) const {
        assert(w == a.h);
        Matrix r(h, a.w);
        for (int i = 0; i < h; i++)
            for (int k = 0; k < w; k++)
                for (int j = 0; j < a.w; j++) {
                    r[i][j] += d[i][k] * a[k][j];
                }

        return r;
    }

    Matrix pow(ll t) const {
        assert(h == w);
        Matrix res = Matrix::unit(h);
        Matrix x = (*this);
        while (t > 0) {
            if (t & 1) res = res * x;
            x = x * x;
            t >>= 1;
        }
        return res;
    }

    tuple<Matrix, T, ll> gaussian_elimination(int w_limit = -1) const {
        if (w_limit == -1) w_limit = w;
        T k = 1;
        Matrix A = *this;
        int i1 = 0;
        for (int j = 0; j < w_limit; j++) {
            if (i1 >= h) break;
            for (int i2 = i1; i2 < h; i2++) {
                if (A[i2][j] != 0) {
                    swap(A[i1], A[i2]);
                    if (i1 != i2) k = -k;
                    break;
                }
            }
            if (A[i1][j] == 0) {
                continue;
            }
            T inv = 1 / A[i1][j];
            k *= A[i1][j];
            for (int jj = 0; jj < w; jj++) {
                A[i1][jj] *= inv;
            }
            for (int i = 0; i < h; i++)
                if (A[i][j] != 0 && i != i1) {
                    T c = -A[i][j];
                    for (int jj = 0; jj < w; jj++) {
                        A[i][jj] += A[i1][jj] * c;
                    }
                }
            i1++;
        }
        return make_tuple(A, k, i1);
    }

    ll rank() const {
        auto [dat, k, rnk] = (*this).gaussian_elimination();
        return rnk;
    }

    pair<vector<T>, bool> linear_equations() const {
        assert(h == w - 1);
        vector<T> ret(w - 1);
        auto [dat, p, rnk] = (*this).gaussian_elimination(w - 1);
        if (rnk != w - 1) return make_pair(ret, false);
        for (int i = 0; i < h; i++) {
            ret[i] = dat[i][w - 1];
        }
        return make_pair(ret, true);
    }

    pair<Matrix, bool> inv() const {
        assert(h == w);
        Matrix slv(h, w * 2);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                slv[i][j] = (*this)[i][j];
            }
        for (int i = 0; i < h; i++) {
            slv[i][i + w] = 1;
        }

        auto [dat, p, rnk] = slv.gaussian_elimination(w);
        auto ret = Matrix::unit(h);
        if (rnk != h) return make_pair(ret, false);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                ret[i][j] = dat[i][j + w];
            }
        }
        return make_pair(ret, true);
    }

    T det() const {
        assert(h == w);
        auto [A, p, rnk] = (*this).gaussian_elimination();
        for (int i = 0; i < h; i++) p *= A[i][i];
        return p;
    }

    friend ostream &operator<<(ostream &os, Matrix a) {
        for (int i = 0; i < a.h; i++) {
            for (int j = 0; j < a.w; j++) {
                os << a[i][j] << (j != a.w - 1 ? " " : "");
            }
            os << (i != a.h - 1 ? "\n" : "");
        }
        return os;
    }
};

template <typename T> struct Matrix {
    int h, w;
    vector<vector<T>> d;
    Matrix() {}
    Matrix(int h, int w, T val = 0) : h(h), w(w), d(h, vector<T>(w, val)) {}
    Matrix &unit() {
        assert(h == w);
        rep(i, 0, h) { d[i][i] = 1; }
        return *this;
    }
    const vector<T> &operator[](int i) const { return d[i]; }
    vector<T> &operator[](int i) { return d[i]; }
    Matrix operator*(const Matrix &a) const {
        assert(w == a.h);
        Matrix r(h, a.w);
        rep(i, 0, h) {
            rep(k, 0, w) {
                rep(j, 0, a.w) { r[i][j] += d[i][k] * a[k][j]; }
            }
        }
        return r;
    }
    Matrix pow(ll t) const {
        assert(h == w);
        Matrix res = Matrix(h, h).unit();
        Matrix x = (*this);
        while (t > 0) {
            if (t & 1) res = res * x;
            x = x * x;
            t >>= 1;
        }
        return res;
    }

    pair<Matrix, T> gaussian_elimination() {
        T k = 1;
        Matrix A = *this;
        rep(j, 0, min(h, w)) {
            rep(i, j, h) {
                if (A[i][j] != 0) {
                    swap(A[i], A[j]);
                    if (i != j) k = -k;
                    break;
                }
            }

            if (A[j][j] == 0) break;
            T inv = 1 / A[j][j];
            k *= A[j][j];
            rep(jj, 0, w) A[j][jj] *= inv;

            rep(i, 0, h) if (A[i][j] != 0 && i != j) {
                T c = -A[i][j];
                rep(jj, 0, w) { A[i][jj] += A[j][jj] * c; }
            }
        }
        return make_pair(A, k);
    }

    T det() {
        assert(h == w);
        auto [A, p] = (*this).gaussian_elimination();
        rep(i, 0, h) p *= A[i][i];
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
/*
@brief matrix
@docs doc/matrix.md
*/
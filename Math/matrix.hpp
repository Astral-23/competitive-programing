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

    friend ostream& operator<<(ostream& os, Matrix a) {
        for(int i = 0; i < a.h; i++) {
            for(int j = 0; j < a.w; j++) {
                os << a[i][j] << (j != a.w - 1? " " : "");
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
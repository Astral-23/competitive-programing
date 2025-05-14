---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: example/matrix.example.cpp
    title: example/matrix.example.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Math_matrix_det.test.cpp
    title: verify/Math_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Math_matrix_inv.test.cpp
    title: verify/Math_matrix_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Math_matrix_pow.test.cpp
    title: verify/Math_matrix_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Math_matrix_rank.test.cpp
    title: verify/Math_matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/mat_det.test.cpp
    title: verify/mat_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/matrix.test.cpp
    title: verify/matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/matrix.hpp\"\ntemplate <typename T> struct Matrix {\n\
    \    int h, w;\n    vector<vector<T>> d;\n    Matrix() {}\n    Matrix(int h, int\
    \ w, T val = 0) : h(h), w(w), d(h, vector<T>(w, val)) {}\n    Matrix(vector<vector<T>>\
    \ const &dat) : h(dat.size()), w(0), d(dat) {\n        if (h > 0) w = d[0].size();\n\
    \    }\n\n    static Matrix unit(int n) {\n        Matrix uni(n, n, 0);\n    \
    \    for (int i = 0; i < n; i++) {\n            uni[i][i] = 1;\n        }\n  \
    \      return uni;\n    }\n    const vector<T> &operator[](int i) const { return\
    \ d[i]; }\n    vector<T> &operator[](int i) { return d[i]; }\n    Matrix &operator*=(const\
    \ Matrix &a) { return *this = (*this) * a; }\n    Matrix operator*(const Matrix\
    \ &a) const {\n        assert(w == a.h);\n        Matrix r(h, a.w);\n        for\
    \ (int i = 0; i < h; i++)\n            for (int k = 0; k < w; k++)\n         \
    \       for (int j = 0; j < a.w; j++) {\n                    r[i][j] += d[i][k]\
    \ * a[k][j];\n                }\n\n        return r;\n    }\n\n    Matrix pow(ll\
    \ t) const {\n        assert(h == w);\n        Matrix res = Matrix::unit(h);\n\
    \        Matrix x = (*this);\n        while (t > 0) {\n            if (t & 1)\
    \ res = res * x;\n            x = x * x;\n            t >>= 1;\n        }\n  \
    \      return res;\n    }\n\n    tuple<Matrix, T, ll> gaussian_elimination(int\
    \ w_limit = -1) const {\n        if (w_limit == -1) w_limit = w;\n        T k\
    \ = 1;\n        Matrix A = *this;\n        int i1 = 0;\n        for (int j = 0;\
    \ j < w_limit; j++) {\n            if (i1 >= h) break;\n            for (int i2\
    \ = i1; i2 < h; i2++) {\n                if (A[i2][j] != 0) {\n              \
    \      swap(A[i1], A[i2]);\n                    if (i1 != i2) k = -k;\n      \
    \              break;\n                }\n            }\n            if (A[i1][j]\
    \ == 0) {\n                continue;\n            }\n            T inv = 1 / A[i1][j];\n\
    \            k *= A[i1][j];\n            for (int jj = 0; jj < w; jj++) {\n  \
    \              A[i1][jj] *= inv;\n            }\n            for (int i = 0; i\
    \ < h; i++)\n                if (A[i][j] != 0 && i != i1) {\n                \
    \    T c = -A[i][j];\n                    for (int jj = 0; jj < w; jj++) {\n \
    \                       A[i][jj] += A[i1][jj] * c;\n                    }\n  \
    \              }\n            i1++;\n        }\n        return make_tuple(A, k,\
    \ i1);\n    }\n\n    ll rank() const {\n        auto [dat, k, rnk] = (*this).gaussian_elimination();\n\
    \        return rnk;\n    }\n\n    pair<vector<T>, bool> linear_equations() const\
    \ {\n        assert(h == w - 1);\n        vector<T> ret(w - 1);\n        auto\
    \ [dat, p, rnk] = (*this).gaussian_elimination(w - 1);\n        if (rnk != w -\
    \ 1) return make_pair(ret, false);\n        for (int i = 0; i < h; i++) {\n  \
    \          ret[i] = dat[i][w - 1];\n        }\n        return make_pair(ret, true);\n\
    \    }\n\n    pair<Matrix, bool> inv() const {\n        assert(h == w);\n    \
    \    Matrix slv(h, w * 2);\n        for (int i = 0; i < h; i++)\n            for\
    \ (int j = 0; j < w; j++) {\n                slv[i][j] = (*this)[i][j];\n    \
    \        }\n        for (int i = 0; i < h; i++) {\n            slv[i][i + w] =\
    \ 1;\n        }\n\n        auto [dat, p, rnk] = slv.gaussian_elimination(w);\n\
    \        auto ret = Matrix::unit(h);\n        if (rnk != h) return make_pair(ret,\
    \ false);\n        for (int i = 0; i < h; i++) {\n            for (int j = 0;\
    \ j < w; j++) {\n                ret[i][j] = dat[i][j + w];\n            }\n \
    \       }\n        return make_pair(ret, true);\n    }\n\n    T det() const {\n\
    \        assert(h == w);\n        auto [A, p, rnk] = (*this).gaussian_elimination();\n\
    \        for (int i = 0; i < h; i++) p *= A[i][i];\n        return p;\n    }\n\
    \n    friend ostream &operator<<(ostream &os, Matrix a) {\n        for (int i\
    \ = 0; i < a.h; i++) {\n            for (int j = 0; j < a.w; j++) {\n        \
    \        os << a[i][j] << (j != a.w - 1 ? \" \" : \"\");\n            }\n    \
    \        os << (i != a.h - 1 ? \"\\n\" : \"\");\n        }\n        return os;\n\
    \    }\n};\n"
  code: "template <typename T> struct Matrix {\n    int h, w;\n    vector<vector<T>>\
    \ d;\n    Matrix() {}\n    Matrix(int h, int w, T val = 0) : h(h), w(w), d(h,\
    \ vector<T>(w, val)) {}\n    Matrix(vector<vector<T>> const &dat) : h(dat.size()),\
    \ w(0), d(dat) {\n        if (h > 0) w = d[0].size();\n    }\n\n    static Matrix\
    \ unit(int n) {\n        Matrix uni(n, n, 0);\n        for (int i = 0; i < n;\
    \ i++) {\n            uni[i][i] = 1;\n        }\n        return uni;\n    }\n\
    \    const vector<T> &operator[](int i) const { return d[i]; }\n    vector<T>\
    \ &operator[](int i) { return d[i]; }\n    Matrix &operator*=(const Matrix &a)\
    \ { return *this = (*this) * a; }\n    Matrix operator*(const Matrix &a) const\
    \ {\n        assert(w == a.h);\n        Matrix r(h, a.w);\n        for (int i\
    \ = 0; i < h; i++)\n            for (int k = 0; k < w; k++)\n                for\
    \ (int j = 0; j < a.w; j++) {\n                    r[i][j] += d[i][k] * a[k][j];\n\
    \                }\n\n        return r;\n    }\n\n    Matrix pow(ll t) const {\n\
    \        assert(h == w);\n        Matrix res = Matrix::unit(h);\n        Matrix\
    \ x = (*this);\n        while (t > 0) {\n            if (t & 1) res = res * x;\n\
    \            x = x * x;\n            t >>= 1;\n        }\n        return res;\n\
    \    }\n\n    tuple<Matrix, T, ll> gaussian_elimination(int w_limit = -1) const\
    \ {\n        if (w_limit == -1) w_limit = w;\n        T k = 1;\n        Matrix\
    \ A = *this;\n        int i1 = 0;\n        for (int j = 0; j < w_limit; j++) {\n\
    \            if (i1 >= h) break;\n            for (int i2 = i1; i2 < h; i2++)\
    \ {\n                if (A[i2][j] != 0) {\n                    swap(A[i1], A[i2]);\n\
    \                    if (i1 != i2) k = -k;\n                    break;\n     \
    \           }\n            }\n            if (A[i1][j] == 0) {\n             \
    \   continue;\n            }\n            T inv = 1 / A[i1][j];\n            k\
    \ *= A[i1][j];\n            for (int jj = 0; jj < w; jj++) {\n               \
    \ A[i1][jj] *= inv;\n            }\n            for (int i = 0; i < h; i++)\n\
    \                if (A[i][j] != 0 && i != i1) {\n                    T c = -A[i][j];\n\
    \                    for (int jj = 0; jj < w; jj++) {\n                      \
    \  A[i][jj] += A[i1][jj] * c;\n                    }\n                }\n    \
    \        i1++;\n        }\n        return make_tuple(A, k, i1);\n    }\n\n   \
    \ ll rank() const {\n        auto [dat, k, rnk] = (*this).gaussian_elimination();\n\
    \        return rnk;\n    }\n\n    pair<vector<T>, bool> linear_equations() const\
    \ {\n        assert(h == w - 1);\n        vector<T> ret(w - 1);\n        auto\
    \ [dat, p, rnk] = (*this).gaussian_elimination(w - 1);\n        if (rnk != w -\
    \ 1) return make_pair(ret, false);\n        for (int i = 0; i < h; i++) {\n  \
    \          ret[i] = dat[i][w - 1];\n        }\n        return make_pair(ret, true);\n\
    \    }\n\n    pair<Matrix, bool> inv() const {\n        assert(h == w);\n    \
    \    Matrix slv(h, w * 2);\n        for (int i = 0; i < h; i++)\n            for\
    \ (int j = 0; j < w; j++) {\n                slv[i][j] = (*this)[i][j];\n    \
    \        }\n        for (int i = 0; i < h; i++) {\n            slv[i][i + w] =\
    \ 1;\n        }\n\n        auto [dat, p, rnk] = slv.gaussian_elimination(w);\n\
    \        auto ret = Matrix::unit(h);\n        if (rnk != h) return make_pair(ret,\
    \ false);\n        for (int i = 0; i < h; i++) {\n            for (int j = 0;\
    \ j < w; j++) {\n                ret[i][j] = dat[i][j + w];\n            }\n \
    \       }\n        return make_pair(ret, true);\n    }\n\n    T det() const {\n\
    \        assert(h == w);\n        auto [A, p, rnk] = (*this).gaussian_elimination();\n\
    \        for (int i = 0; i < h; i++) p *= A[i][i];\n        return p;\n    }\n\
    \n    friend ostream &operator<<(ostream &os, Matrix a) {\n        for (int i\
    \ = 0; i < a.h; i++) {\n            for (int j = 0; j < a.w; j++) {\n        \
    \        os << a[i][j] << (j != a.w - 1 ? \" \" : \"\");\n            }\n    \
    \        os << (i != a.h - 1 ? \"\\n\" : \"\");\n        }\n        return os;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/matrix.hpp
  requiredBy:
  - example/matrix.example.cpp
  timestamp: '2025-01-10 23:29:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Math_matrix_inv.test.cpp
  - verify/Math_matrix_pow.test.cpp
  - verify/matrix.test.cpp
  - verify/Math_matrix_det.test.cpp
  - verify/mat_det.test.cpp
  - verify/Math_matrix_rank.test.cpp
documentation_of: Math/matrix.hpp
layout: document
redirect_from:
- /library/Math/matrix.hpp
- /library/Math/matrix.hpp.html
title: Math/matrix.hpp
---

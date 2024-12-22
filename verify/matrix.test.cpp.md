---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/matrix.hpp
    title: matrix
  - icon: ':heavy_check_mark:'
    path: Utility/modint.hpp
    title: modint
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_matrix
    links:
    - https://judge.yosupo.jp/problem/pow_of_matrix
  bundledCode: "#line 1 \"verify/matrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\n\n//\
    \ \u52D5\u7684mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\
    \u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate <uint32_t mod> struct\
    \ modint {\n    using mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n\
    \    TT modint(T a = 0) : x((ll(a) % mod + mod)) {\n        if (x >= mod) x -=\
    \ mod;\n    }\n\n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n\
    \        if (a.x >= mod) a.x -= mod;\n        return a;\n    }\n    friend mm\
    \ operator-(mm a, mm b) {\n        a.x -= b.x;\n        if (a.x >= mod) a.x +=\
    \ mod;\n        return a;\n    }\n\n    mm operator-() const { return mod - x;\
    \ }\n\n    //+\u3068-\u3060\u3051\u3067\u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\
    \u4E0B\u306F\u7701\u7565\u3057\u3066\u826F\u3044\u3067\u3059\u3002\n\n    friend\
    \ mm operator*(mm a, mm b) { return (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm\
    \ a, mm b) { return a * b.inv(); }\n    friend mm &operator+=(mm &a, mm b) { return\
    \ a = a + b; }\n    friend mm &operator-=(mm &a, mm b) { return a = a - b; }\n\
    \    friend mm &operator*=(mm &a, mm b) { return a = a * b; }\n    friend mm &operator/=(mm\
    \ &a, mm b) { return a = a * b.inv(); }\n\n    mm inv() const {\n        assert(x\
    \ != 0);\n        return pow(mod - 2);\n    }\n    mm pow(ll y) const {\n    \
    \    mm res = 1;\n        mm v = *this;\n        while (y) {\n            if (y\
    \ & 1) res *= v;\n            v *= v;\n            y /= 2;\n        }\n      \
    \  return res;\n    }\n\n    friend istream &operator>>(istream &is, mm &a) {\n\
    \        ll t;\n        cin >> t;\n        a = mm(t);\n        return is;\n  \
    \  }\n\n    friend ostream &operator<<(ostream &os, mm a) { return os << a.x;\
    \ }\n\n    bool operator==(mm a) { return x == a.x; }\n    bool operator!=(mm\
    \ a) { return x != a.x; }\n\n    bool operator<(const mm &a) const { return x\
    \ < a.x; }\n};\nusing modint998244353 = modint<998244353>;\nusing modint1000000007\
    \ = modint<1'000'000'007>;\n/*\n@brief modint\n*/\n#line 1 \"Math/matrix.hpp\"\
    \ntemplate <typename T> struct Matrix {\n    int h, w;\n    vector<vector<T>>\
    \ d;\n    Matrix() {}\n    Matrix(int h, int w, T val = 0) : h(h), w(w), d(h,\
    \ vector<T>(w, val)) {}\n    Matrix &unit() {\n        assert(h == w);\n     \
    \   rep(i, 0, h) { d[i][i] = 1; }\n        return *this;\n    }\n    const vector<T>\
    \ &operator[](int i) const { return d[i]; }\n    vector<T> &operator[](int i)\
    \ { return d[i]; }\n    Matrix operator*(const Matrix &a) const {\n        assert(w\
    \ == a.h);\n        Matrix r(h, a.w);\n        rep(i, 0, h) {\n            rep(k,\
    \ 0, w) {\n                rep(j, 0, a.w) { r[i][j] += d[i][k] * a[k][j]; }\n\
    \            }\n        }\n        return r;\n    }\n    Matrix pow(ll t) const\
    \ {\n        assert(h == w);\n        Matrix res = Matrix(h, h).unit();\n    \
    \    Matrix x = (*this);\n        while (t > 0) {\n            if (t & 1) res\
    \ = res * x;\n            x = x * x;\n            t >>= 1;\n        }\n      \
    \  return res;\n    }\n\n    pair<Matrix, T> gaussian_elimination() {\n      \
    \  T k = 1;\n        Matrix A = *this;\n        rep(j, 0, min(h, w)) {\n     \
    \       rep(i, j, h) {\n                if (A[i][j] != 0) {\n                \
    \    swap(A[i], A[j]);\n                    if (i != j) k = -k;\n            \
    \        break;\n                }\n            }\n\n            if (A[j][j] ==\
    \ 0) break;\n            T inv = 1 / A[j][j];\n            k *= A[j][j];\n   \
    \         rep(jj, 0, w) A[j][jj] *= inv;\n\n            rep(i, 0, h) if (A[i][j]\
    \ != 0 && i != j) {\n                T c = -A[i][j];\n                rep(jj,\
    \ 0, w) { A[i][jj] += A[j][jj] * c; }\n            }\n        }\n        return\
    \ make_pair(A, k);\n    }\n\n    T det() {\n        assert(h == w);\n        auto\
    \ [A, p] = (*this).gaussian_elimination();\n        rep(i, 0, h) p *= A[i][i];\n\
    \        return p;\n    }\n\n    friend ostream &operator<<(ostream &os, Matrix\
    \ a) {\n        for (int i = 0; i < a.h; i++) {\n            for (int j = 0; j\
    \ < a.w; j++) {\n                os << a[i][j] << (j != a.w - 1 ? \" \" : \"\"\
    );\n            }\n            os << (i != a.h - 1 ? \"\\n\" : \"\");\n      \
    \  }\n        return os;\n    }\n};\n/*\n@brief matrix\n@docs doc/matrix.md\n\
    */\n#line 5 \"verify/matrix.test.cpp\"\nusing mint = modint998244353;\nint main()\
    \ {\n    ll N, K;\n    cin >> N >> K;\n    Matrix<mint> A(N, N, 0);\n    rep(i,\
    \ 0, N) rep(j, 0, N) {\n        cin >> A[i][j];\n    }\n    A = A.pow(K);\n  \
    \  rep(i, 0, N) {\n        rep(j, 0, N) {\n            cout << A[i][j].x << \"\
    \ \";\n        }\n        cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\n#include \"\
    ../Math/matrix.hpp\"\nusing mint = modint998244353;\nint main() {\n    ll N, K;\n\
    \    cin >> N >> K;\n    Matrix<mint> A(N, N, 0);\n    rep(i, 0, N) rep(j, 0,\
    \ N) {\n        cin >> A[i][j];\n    }\n    A = A.pow(K);\n    rep(i, 0, N) {\n\
    \        rep(j, 0, N) {\n            cout << A[i][j].x << \" \";\n        }\n\
    \        cout << '\\n';\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Math/matrix.hpp
  isVerificationFile: true
  path: verify/matrix.test.cpp
  requiredBy: []
  timestamp: '2024-12-03 09:45:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/matrix.test.cpp
- /verify/verify/matrix.test.cpp.html
title: verify/matrix.test.cpp
---

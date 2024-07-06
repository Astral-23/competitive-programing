---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: example/matrix.example.cpp
    title: example/matrix.example.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/matrix.test.cpp
    title: verify/matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/matrix.md
    document_title: "\u884C\u5217\u306E\u578B"
    links: []
  bundledCode: "#line 1 \"Math/matrix.hpp\"\ntemplate<typename T>\nstruct Matrix \
    \ {\n    int h, w;\n    vector<vector<T>> d;\n    Matrix() {}\n    Matrix(int\
    \ h, int w, T val = 0): h(h), w(w), d(h, vector<T>(w, val)){}\n    Matrix& unit()\
    \ {\n        assert(h == w);\n        rep(i, 0, h) {\n            d[i][i] = 1;\n\
    \        }\n     return *this;\n    }\n    const vector<T>& operator[](int i)\
    \ const{return d[i];}\n    vector<T>& operator[](int i) {return d[i];}\n    Matrix\
    \ operator*(const Matrix&a) const{\n        assert(w == a.h);\n        Matrix\
    \ r(h, a.w);\n        rep(i, 0, h) {\n            rep(k, 0, w) {\n           \
    \     rep(j, 0, a.w) {\n                    r[i][j] += d[i][k] * a[k][j];\n  \
    \              }\n            }\n        }\n        return r;\n    }\n    Matrix\
    \ pow(ll t) const {\n        assert(h == w);\n        if(!t) return Matrix(h,\
    \ h).unit();\n        if(t == 1) return *this;\n        Matrix r = pow(t >> 1);\n\
    \        r = r * r;\n        if(t&1) r = r*(*this);\n        return r;\n    }\n\
    \n    vec<vec<T>> dump() const {\n        return d;\n    }\n};\n/*\n@brief \u884C\
    \u5217\u306E\u578B\n@docs doc/matrix.md\n*/\n"
  code: "template<typename T>\nstruct Matrix  {\n    int h, w;\n    vector<vector<T>>\
    \ d;\n    Matrix() {}\n    Matrix(int h, int w, T val = 0): h(h), w(w), d(h, vector<T>(w,\
    \ val)){}\n    Matrix& unit() {\n        assert(h == w);\n        rep(i, 0, h)\
    \ {\n            d[i][i] = 1;\n        }\n     return *this;\n    }\n    const\
    \ vector<T>& operator[](int i) const{return d[i];}\n    vector<T>& operator[](int\
    \ i) {return d[i];}\n    Matrix operator*(const Matrix&a) const{\n        assert(w\
    \ == a.h);\n        Matrix r(h, a.w);\n        rep(i, 0, h) {\n            rep(k,\
    \ 0, w) {\n                rep(j, 0, a.w) {\n                    r[i][j] += d[i][k]\
    \ * a[k][j];\n                }\n            }\n        }\n        return r;\n\
    \    }\n    Matrix pow(ll t) const {\n        assert(h == w);\n        if(!t)\
    \ return Matrix(h, h).unit();\n        if(t == 1) return *this;\n        Matrix\
    \ r = pow(t >> 1);\n        r = r * r;\n        if(t&1) r = r*(*this);\n     \
    \   return r;\n    }\n\n    vec<vec<T>> dump() const {\n        return d;\n  \
    \  }\n};\n/*\n@brief \u884C\u5217\u306E\u578B\n@docs doc/matrix.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/matrix.hpp
  requiredBy:
  - example/matrix.example.cpp
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/matrix.test.cpp
documentation_of: Math/matrix.hpp
layout: document
redirect_from:
- /library/Math/matrix.hpp
- /library/Math/matrix.hpp.html
title: "\u884C\u5217\u306E\u578B"
---
## 概要
行列 <br>
参考 : https://github.com/atcoder/live_library

## 使用例

```
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Math/matrix.hpp"
using mint = modint998244353;

int main() {
    int n = 3; 
    Matrix<mint>  mat(n, n, 3); // n * nで初期値が mint(3) の行列を生成

    mat[0][0] = 1; // (0, 0)成分を 1 に変更
    mat[0][1] += 10; //(0, 1)成分に 10　加算
    //mat[3][3] = 100; //配列外参照 assert 無し

    auto pow_mat = mat.pow(5); // matの 5 乗を受け取る。 matは破壊されない。

    auto print_vec = [](vec<vec<mint>> v) {
        rep(i, 0, v.size()) {
            rep(j, 0, v[i].size()) cout << v[i][j] << " ";
            cout << endl;
        }
    };

    print_vec(mat.dump());// dumpで返された二次元配列を出力
    print_vec(pow_mat.dump());// 5乗されている。

    Matrix<mint> v(n, 1, 1); //n * 1の行列。擬似的なベクトルとして扱える。

    Matrix<mint> res = mat * v;//行列同士の掛け算。行列累乗の際、このような処理を書くかもしれない。
    print_vec(res.dump());
    cout << res[0][0] << endl;
}

```
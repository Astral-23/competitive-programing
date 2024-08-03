---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/bitwise_and_convolution.hpp
    title: Convolution/bitwise_and_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/bitwise_and_convolution.test.cpp
    title: verify/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/superset_transform.test.cpp
    title: verify/superset_transform.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Algorithm/superset_transform.hpp\"\ntemplate<class S, S\
    \ (*op)(S, S)> vector<S> superset_zeta_transform (vector<S> f, int n) {\n    rep(i,\
    \ 0, n) {\n        rep(s, 0, 1LL << n) {\n            if((s & (1 << i)) == 0)\
    \ { // if i in s\n                f[s] = op(f[s], f[s ^ (1 << i)]);\n        \
    \    }\n        }\n    }\n    return f;\n}\n\ntemplate<class S, S (*op)(S, S),\
    \ S (*inv)(S)> vector<S> superset_mobius_transform (vector<S> f, int n) {\n  \
    \  rrep(i, 0, n) {\n        rep(s, 0, 1LL << n) {\n            if((s & (1 << i))\
    \ == 0) { // if i in s\n                f[s] = op(f[s], inv(f[s ^ (1 << i)]));\n\
    \                //f[s] = f[s] -  f[s ^ (1 << i)];\n            }\n        }\n\
    \    }\n    return f;\n}\n"
  code: "template<class S, S (*op)(S, S)> vector<S> superset_zeta_transform (vector<S>\
    \ f, int n) {\n    rep(i, 0, n) {\n        rep(s, 0, 1LL << n) {\n           \
    \ if((s & (1 << i)) == 0) { // if i in s\n                f[s] = op(f[s], f[s\
    \ ^ (1 << i)]);\n            }\n        }\n    }\n    return f;\n}\n\ntemplate<class\
    \ S, S (*op)(S, S), S (*inv)(S)> vector<S> superset_mobius_transform (vector<S>\
    \ f, int n) {\n    rrep(i, 0, n) {\n        rep(s, 0, 1LL << n) {\n          \
    \  if((s & (1 << i)) == 0) { // if i in s\n                f[s] = op(f[s], inv(f[s\
    \ ^ (1 << i)]));\n                //f[s] = f[s] -  f[s ^ (1 << i)];\n        \
    \    }\n        }\n    }\n    return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/superset_transform.hpp
  requiredBy:
  - Convolution/bitwise_and_convolution.hpp
  timestamp: '2024-07-31 11:08:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/superset_transform.test.cpp
  - verify/bitwise_and_convolution.test.cpp
documentation_of: Algorithm/superset_transform.hpp
layout: document
redirect_from:
- /library/Algorithm/superset_transform.hpp
- /library/Algorithm/superset_transform.hpp.html
title: Algorithm/superset_transform.hpp
---

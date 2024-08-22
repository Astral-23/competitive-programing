---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/bitwise_or_convolution.hpp
    title: Convolution/bitwise_or_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/Chromatic_Number_with_restoration.hpp
    title: Graph/Chromatic_Number_with_restoration.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Chromatic_Number_with_restoration.test.cpp
    title: verify/Chromatic_Number_with_restoration.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Algorithm/subset_transform.hpp\"\ntemplate<class S, S (*op)(S,\
    \ S)> vector<S> subset_zeta_transform (vector<S> f, int n) {\n    rep(i, 0, n)\
    \ {\n        rep(s, 0, 1LL << n) {\n            if((s & (1 << i)) != 0) { // if\
    \ i in s\n                f[s] = op(f[s], f[s ^ (1 << i)]);\n            }\n \
    \       }\n    }\n    return f;\n}\n\ntemplate<class S, S (*op)(S, S), S (*inv)(S)>\
    \ vector<S> subset_mobius_transform (vector<S> f, int n) {\n    rrep(i, 0, n)\
    \ {\n        rep(s, 0, 1LL << n) {\n            if((s & (1 << i)) != 0) { // if\
    \ i in s\n                f[s] = op(f[s], inv(f[s ^ (1 << i)]));\n           \
    \ }\n        }\n    }\n    return f;\n}\n"
  code: "template<class S, S (*op)(S, S)> vector<S> subset_zeta_transform (vector<S>\
    \ f, int n) {\n    rep(i, 0, n) {\n        rep(s, 0, 1LL << n) {\n           \
    \ if((s & (1 << i)) != 0) { // if i in s\n                f[s] = op(f[s], f[s\
    \ ^ (1 << i)]);\n            }\n        }\n    }\n    return f;\n}\n\ntemplate<class\
    \ S, S (*op)(S, S), S (*inv)(S)> vector<S> subset_mobius_transform (vector<S>\
    \ f, int n) {\n    rrep(i, 0, n) {\n        rep(s, 0, 1LL << n) {\n          \
    \  if((s & (1 << i)) != 0) { // if i in s\n                f[s] = op(f[s], inv(f[s\
    \ ^ (1 << i)]));\n            }\n        }\n    }\n    return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/subset_transform.hpp
  requiredBy:
  - Convolution/bitwise_or_convolution.hpp
  - Graph/Chromatic_Number_with_restoration.hpp
  timestamp: '2024-07-31 11:08:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Chromatic_Number_with_restoration.test.cpp
documentation_of: Algorithm/subset_transform.hpp
layout: document
redirect_from:
- /library/Algorithm/subset_transform.hpp
- /library/Algorithm/subset_transform.hpp.html
title: Algorithm/subset_transform.hpp
---
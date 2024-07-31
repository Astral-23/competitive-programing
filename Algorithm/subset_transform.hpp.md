---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  requiredBy: []
  timestamp: '2024-07-31 11:08:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/subset_transform.hpp
layout: document
redirect_from:
- /library/Algorithm/subset_transform.hpp
- /library/Algorithm/subset_transform.hpp.html
title: Algorithm/subset_transform.hpp
---

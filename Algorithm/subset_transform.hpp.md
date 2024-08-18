---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Convolution/bitwise_or_convolution.hpp
    title: Convolution/bitwise_or_convolution.hpp
  - icon: ':x:'
    path: Gragh/Chromatic_Number_with_restoration.hpp
    title: "\u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/Chromatic_Number_with_restoration.test.cpp.cpp
    title: verify/Chromatic_Number_with_restoration.test.cpp.cpp
  - icon: ':x:'
    path: verify/chromatic_num_with_restore.test.cpp
    title: verify/chromatic_num_with_restore.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  - Gragh/Chromatic_Number_with_restoration.hpp
  - Convolution/bitwise_or_convolution.hpp
  timestamp: '2024-07-31 11:08:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/Chromatic_Number_with_restoration.test.cpp.cpp
  - verify/chromatic_num_with_restore.test.cpp
documentation_of: Algorithm/subset_transform.hpp
layout: document
redirect_from:
- /library/Algorithm/subset_transform.hpp
- /library/Algorithm/subset_transform.hpp.html
title: Algorithm/subset_transform.hpp
---

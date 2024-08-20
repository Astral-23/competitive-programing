---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/subset_transform.hpp
    title: Algorithm/subset_transform.hpp
  _extendedRequiredBy:
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
    \ }\n        }\n    }\n    return f;\n}\n#line 2 \"Convolution/bitwise_or_convolution.hpp\"\
    \n\ntemplate<class S, S (*op)(S, S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_or_convolution(vec<S>\
    \ A, vec<S> B) {\n    ll lg = 1;\n    while(A.size() > (1LL << lg)) lg++;\n  \
    \  while(B.size() > (1LL << lg)) lg++;\n    A.resize(1LL << lg, zero());\n   \
    \ B.resize(1LL << lg, zero());\n\n    vec<S> FA = subset_zeta_transform<S, op>(A,\
    \ lg);\n    vec<S> FB = subset_zeta_transform<S, op>(B, lg);\n    rep(i, 0, 1\
    \ << lg) FA[i] *= FB[i];\n    vec<S> f = subset_mobius_transform<S, op, inv>(FA,\
    \ lg);\n    return f;\n}\n//\u4EE5\u964D\u306E\u9805\u306B\u3064\u3044\u3066\u3001\
    0\u3067\u3042\u308B\u3002\n"
  code: "#include \"../Algorithm/subset_transform.hpp\"\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_or_convolution(vec<S> A, vec<S>\
    \ B) {\n    ll lg = 1;\n    while(A.size() > (1LL << lg)) lg++;\n    while(B.size()\
    \ > (1LL << lg)) lg++;\n    A.resize(1LL << lg, zero());\n    B.resize(1LL <<\
    \ lg, zero());\n\n    vec<S> FA = subset_zeta_transform<S, op>(A, lg);\n    vec<S>\
    \ FB = subset_zeta_transform<S, op>(B, lg);\n    rep(i, 0, 1 << lg) FA[i] *= FB[i];\n\
    \    vec<S> f = subset_mobius_transform<S, op, inv>(FA, lg);\n    return f;\n\
    }\n//\u4EE5\u964D\u306E\u9805\u306B\u3064\u3044\u3066\u30010\u3067\u3042\u308B\
    \u3002"
  dependsOn:
  - Algorithm/subset_transform.hpp
  isVerificationFile: false
  path: Convolution/bitwise_or_convolution.hpp
  requiredBy:
  - Graph/Chromatic_Number_with_restoration.hpp
  timestamp: '2024-08-18 17:09:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Chromatic_Number_with_restoration.test.cpp
documentation_of: Convolution/bitwise_or_convolution.hpp
layout: document
redirect_from:
- /library/Convolution/bitwise_or_convolution.hpp
- /library/Convolution/bitwise_or_convolution.hpp.html
title: Convolution/bitwise_or_convolution.hpp
---

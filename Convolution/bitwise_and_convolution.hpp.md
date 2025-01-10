---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/superset_transform.hpp
    title: Algorithm/superset_transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/bitwise_and_convolution.test.cpp
    title: verify/bitwise_and_convolution.test.cpp
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
    \    }\n    return f;\n}\n#line 2 \"Convolution/bitwise_and_convolution.hpp\"\n\
    // i and j = k <-> i and j \u304C k \u306E superset (\u21D4 i, j\u304C\u3068\u3082\
    \u306Bk\u306Esuperset)\ntemplate<class S, S (*op)(S, S), S (*inv)(S),  S(*zero)()>\
    \ vec<S> bitwise_and_convolution(vec<S> A, vec<S> B) {\n    ll lg = 1;\n    while(A.size()\
    \ > (1LL << lg)) lg++;\n    while(B.size() > (1LL << lg)) lg++;\n    A.resize(1LL\
    \ << lg, zero());\n    B.resize(1LL << lg, zero());\n\n    vec<S> FA = superset_zeta_transform<S,\
    \ op>(A, lg);\n    vec<S> FB = superset_zeta_transform<S, op>(B, lg);\n    rep(i,\
    \ 0, 1 << lg) FA[i] *= FB[i];\n    vec<S> f = superset_mobius_transform<S, op,\
    \ inv>(FA, lg);\n    return f;\n}\n//\u4EE5\u964D\u306E\u9805\u306B\u3064\u3044\
    \u3066\u30010\u3067\u3042\u308B\u3002\n"
  code: "#include \"../Algorithm/superset_transform.hpp\"\n// i and j = k <-> i and\
    \ j \u304C k \u306E superset (\u21D4 i, j\u304C\u3068\u3082\u306Bk\u306Esuperset)\n\
    template<class S, S (*op)(S, S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_and_convolution(vec<S>\
    \ A, vec<S> B) {\n    ll lg = 1;\n    while(A.size() > (1LL << lg)) lg++;\n  \
    \  while(B.size() > (1LL << lg)) lg++;\n    A.resize(1LL << lg, zero());\n   \
    \ B.resize(1LL << lg, zero());\n\n    vec<S> FA = superset_zeta_transform<S, op>(A,\
    \ lg);\n    vec<S> FB = superset_zeta_transform<S, op>(B, lg);\n    rep(i, 0,\
    \ 1 << lg) FA[i] *= FB[i];\n    vec<S> f = superset_mobius_transform<S, op, inv>(FA,\
    \ lg);\n    return f;\n}\n//\u4EE5\u964D\u306E\u9805\u306B\u3064\u3044\u3066\u3001\
    0\u3067\u3042\u308B\u3002"
  dependsOn:
  - Algorithm/superset_transform.hpp
  isVerificationFile: false
  path: Convolution/bitwise_and_convolution.hpp
  requiredBy: []
  timestamp: '2025-01-11 07:38:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/bitwise_and_convolution.test.cpp
documentation_of: Convolution/bitwise_and_convolution.hpp
layout: document
redirect_from:
- /library/Convolution/bitwise_and_convolution.hpp
- /library/Convolution/bitwise_and_convolution.hpp.html
title: Convolution/bitwise_and_convolution.hpp
---

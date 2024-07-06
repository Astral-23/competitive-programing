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
  bundledCode: "#line 1 \"random/random_generator.hpp\"\nstruct RNG {\n    mt19937_64\
    \ mt;\n    RNG() {mt = mt19937_64(clock());}\n\n    int rndint(int l, int r) {\
    \ return mt()%(r-l+1)+l; }\n    ll rndll(ll l, ll r) { return mt()%(r-l+1)+l;\
    \ }\n    TT vec<T> rvec(int n, T l, T r) {\n        vec<T> res(n);\n        for(T&\
    \ x : res) x = rndll(l, r);\n        return res;\n    }\n\n    string rstr(int\
    \ n, char l, char r) {\n        string res;\n        rep(i, 0, n) res += l + rndint(0,\
    \ r-l);\n        return res;\n    }\n    \n};\n"
  code: "struct RNG {\n    mt19937_64 mt;\n    RNG() {mt = mt19937_64(clock());}\n\
    \n    int rndint(int l, int r) { return mt()%(r-l+1)+l; }\n    ll rndll(ll l,\
    \ ll r) { return mt()%(r-l+1)+l; }\n    TT vec<T> rvec(int n, T l, T r) {\n  \
    \      vec<T> res(n);\n        for(T& x : res) x = rndll(l, r);\n        return\
    \ res;\n    }\n\n    string rstr(int n, char l, char r) {\n        string res;\n\
    \        rep(i, 0, n) res += l + rndint(0, r-l);\n        return res;\n    }\n\
    \    \n};\n"
  dependsOn: []
  isVerificationFile: false
  path: random/random_generator.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/random_generator.hpp
layout: document
redirect_from:
- /library/random/random_generator.hpp
- /library/random/random_generator.hpp.html
title: random/random_generator.hpp
---

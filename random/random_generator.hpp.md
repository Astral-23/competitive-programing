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
  bundledCode: "#line 1 \"random/random_generator.hpp\"\nnamespace RNG {\nstatic mt19937_64\
    \ engine(clock());\ntemplate <typename T = long long> T rnd(T l, T r) {\n    return\
    \ engine() % (r - l) + l;\n}\nstring rstr(ll len, char l, char r) {\n    string\
    \ res;\n    for (int i = 0; i < len; i++) res += l + rnd(0, int(r - l));\n   \
    \ return res;\n}\ntemplate <typename T> vector<T> rvec(ll len, T l, T r) {\n \
    \   vector<T> res(len);\n    for (T &x : res) x = rnd<T>(l, r);\n    return res;\n\
    }\n}  // namespace RNG\nusing namespace RNG;\n"
  code: "namespace RNG {\nstatic mt19937_64 engine(clock());\ntemplate <typename T\
    \ = long long> T rnd(T l, T r) {\n    return engine() % (r - l) + l;\n}\nstring\
    \ rstr(ll len, char l, char r) {\n    string res;\n    for (int i = 0; i < len;\
    \ i++) res += l + rnd(0, int(r - l));\n    return res;\n}\ntemplate <typename\
    \ T> vector<T> rvec(ll len, T l, T r) {\n    vector<T> res(len);\n    for (T &x\
    \ : res) x = rnd<T>(l, r);\n    return res;\n}\n}  // namespace RNG\nusing namespace\
    \ RNG;"
  dependsOn: []
  isVerificationFile: false
  path: random/random_generator.hpp
  requiredBy: []
  timestamp: '2024-08-13 15:37:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/random_generator.hpp
layout: document
redirect_from:
- /library/random/random_generator.hpp
- /library/random/random_generator.hpp.html
title: random/random_generator.hpp
---

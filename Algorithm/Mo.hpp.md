---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/mo.test.cpp
    title: verify/mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Mo\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
    links: []
  bundledCode: "#line 1 \"Algorithm/Mo.hpp\"\n\nstruct Mo {\n    int n, q;\n    vec<pair<int,\
    \ int>> qs;\n    vec<int> qi;\n    Mo(int n, vec<pair<int, int>> qs) : n(n), q(qs.size()),\
    \ qs(qs) {   \n        qi = vec<int>(q);\n        iota(all(qi), 0);\n        int\
    \ width = max<int>(1, 1.0 * n / max(1.0, sqrt(q * 2.0 / 3.0)));\n        sort(all(qi),\
    \ [&](int i, int j) {\n            if(qs[i].first/width != qs[j].first/width)\
    \ {\n                return qs[i].first < qs[j].first;\n            }\n      \
    \      else {\n                int g = qs[i].first / width;\n                if(g\
    \ % 2 == 0) {\n                    return qs[i].second < qs[j].second;\n     \
    \           }\n                else {\n                    return qs[i].second\
    \ > qs[j].second;\n                }\n            }\n        });\n    }\n    \n\
    \    template<class AL, class AR, class DL, class DR, class REM> void run(AL addL,\
    \ AR addR, DL delL, DR delR, REM rem) {\n        int l = 0, r = 0;\n        for(int\
    \ i : qi) {\n            while(l > qs[i].first) addL(--l);\n            while(l\
    \ < qs[i].first) delL(l++);\n            while(r < qs[i].second)addR(r++);\n \
    \           while(r > qs[i].second)delR(--r);\n            rem(i, l, r);     \
    \       \n        }\n    }\n};\n\n/*\n@brief Mo\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\
    \n*/\n"
  code: "\nstruct Mo {\n    int n, q;\n    vec<pair<int, int>> qs;\n    vec<int> qi;\n\
    \    Mo(int n, vec<pair<int, int>> qs) : n(n), q(qs.size()), qs(qs) {   \n   \
    \     qi = vec<int>(q);\n        iota(all(qi), 0);\n        int width = max<int>(1,\
    \ 1.0 * n / max(1.0, sqrt(q * 2.0 / 3.0)));\n        sort(all(qi), [&](int i,\
    \ int j) {\n            if(qs[i].first/width != qs[j].first/width) {\n       \
    \         return qs[i].first < qs[j].first;\n            }\n            else {\n\
    \                int g = qs[i].first / width;\n                if(g % 2 == 0)\
    \ {\n                    return qs[i].second < qs[j].second;\n               \
    \ }\n                else {\n                    return qs[i].second > qs[j].second;\n\
    \                }\n            }\n        });\n    }\n    \n    template<class\
    \ AL, class AR, class DL, class DR, class REM> void run(AL addL, AR addR, DL delL,\
    \ DR delR, REM rem) {\n        int l = 0, r = 0;\n        for(int i : qi) {\n\
    \            while(l > qs[i].first) addL(--l);\n            while(l < qs[i].first)\
    \ delL(l++);\n            while(r < qs[i].second)addR(r++);\n            while(r\
    \ > qs[i].second)delR(--r);\n            rem(i, l, r);            \n        }\n\
    \    }\n};\n\n/*\n@brief Mo\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Mo.hpp
  requiredBy: []
  timestamp: '2024-08-17 22:36:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/mo.test.cpp
documentation_of: Algorithm/Mo.hpp
layout: document
redirect_from:
- /library/Algorithm/Mo.hpp
- /library/Algorithm/Mo.hpp.html
title: "Mo\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
---

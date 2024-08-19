---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/sprase_table.test.cpp
    title: verify/sprase_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: sprase_table
    links: []
  bundledCode: "#line 1 \"Datastructure/sparse_table.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct sparse_table {\n    vector<vector<S>> d;\n    vector<int>\
    \ lookup;\n    bool built = true;\n\n    sparse_table() {}\n\n    sparse_table(const\
    \ vector<S> &v) {\n        int n = v.size();\n        int lg = 0;\n        while\
    \ ((1LL << lg) <= n) lg++;\n        d.resize(lg, vector<S>(1LL << lg, e()));\n\
    \        for (int i = 0; i < n; i++) {\n            d[0][i] = v[i];\n        }\n\
    \n        for (int i = 1; i < lg; i++) {\n            for (int j = 0; j + (1LL\
    \ << i) <= (1LL << lg); j++) {\n                d[i][j] = op(d[i - 1][j], d[i\
    \ - 1][j + (1LL << (i - 1))]);\n            }\n        }\n\n        lookup.resize(n\
    \ + 1);\n        for (int i = 2; i < int(lookup.size()); i++) {\n            lookup[i]\
    \ = lookup[i >> 1] + 1;\n        }\n    }\n\n    S prod(int l, int r) {\n    \
    \    assert(l <= r);\n        if (l == r) return e();\n        int lg = lookup[r\
    \ - l];\n        return op(d[lg][l], d[lg][r - (1LL << lg)]);\n    }\n};\n/*\n\
    @brief sprase_table\n*/\n"
  code: "template <class S, S (*op)(S, S), S (*e)()> struct sparse_table {\n    vector<vector<S>>\
    \ d;\n    vector<int> lookup;\n    bool built = true;\n\n    sparse_table() {}\n\
    \n    sparse_table(const vector<S> &v) {\n        int n = v.size();\n        int\
    \ lg = 0;\n        while ((1LL << lg) <= n) lg++;\n        d.resize(lg, vector<S>(1LL\
    \ << lg, e()));\n        for (int i = 0; i < n; i++) {\n            d[0][i] =\
    \ v[i];\n        }\n\n        for (int i = 1; i < lg; i++) {\n            for\
    \ (int j = 0; j + (1LL << i) <= (1LL << lg); j++) {\n                d[i][j] =\
    \ op(d[i - 1][j], d[i - 1][j + (1LL << (i - 1))]);\n            }\n        }\n\
    \n        lookup.resize(n + 1);\n        for (int i = 2; i < int(lookup.size());\
    \ i++) {\n            lookup[i] = lookup[i >> 1] + 1;\n        }\n    }\n\n  \
    \  S prod(int l, int r) {\n        assert(l <= r);\n        if (l == r) return\
    \ e();\n        int lg = lookup[r - l];\n        return op(d[lg][l], d[lg][r -\
    \ (1LL << lg)]);\n    }\n};\n/*\n@brief sprase_table\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-08-19 13:17:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/sprase_table.test.cpp
documentation_of: Datastructure/sparse_table.hpp
layout: document
redirect_from:
- /library/Datastructure/sparse_table.hpp
- /library/Datastructure/sparse_table.hpp.html
title: sprase_table
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_sprase_table.test.cpp
    title: verify/Datastructure_sprase_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: sparse_table
    links: []
  bundledCode: "#line 1 \"Datastructure/sparse_table.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct sparse_table {\n    vector<vector<S>> d;\n    vector<int>\
    \ lookup;\n    bool built = false;\n    int n, lg;\n    vector<S> v;\n\n    sparse_table(int\
    \ n) : n(n), v(n, e()) {}\n\n    sparse_table(const vector<S> &v) : n(v.size()),\
    \ v(v) {}\n\n    void set(int i, S x) {\n        assert(0 <= i && i < n);\n  \
    \      assert(built == false);\n        v[i] = x;\n    }\n\n    void build() {\n\
    \        n = v.size();\n        lg = 0;\n        while ((1LL << lg) <= n) lg++;\n\
    \        d.resize(lg, vector<S>(1LL << lg, e()));\n        for (int i = 0; i <\
    \ n; i++) {\n            d[0][i] = v[i];\n        }\n        for (int i = 1; i\
    \ < lg; i++) {\n            for (int j = 0; j + (1LL << i) <= (1LL << lg); j++)\
    \ {\n                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1LL << (i - 1))]);\n\
    \            }\n        }\n        lookup.resize(n + 1);\n        for (int i =\
    \ 2; i < int(lookup.size()); i++) {\n            lookup[i] = lookup[i >> 1] +\
    \ 1;\n        }\n        built = true;\n    }\n\n    S get(int i) {\n        assert(0\
    \ <= i && i < n);\n        return v[i];\n    }\n\n    S prod(int l, int r) {\n\
    \        assert(built == true);\n        assert(0 <= l && r <= n);\n        if\
    \ (l >= r) return e();\n        int LG = lookup[r - l];\n        return op(d[LG][l],\
    \ d[LG][r - (1LL << LG)]);\n    }\n};\n\n/*\n@brief sparse_table\n*/\n"
  code: "template <class S, S (*op)(S, S), S (*e)()> struct sparse_table {\n    vector<vector<S>>\
    \ d;\n    vector<int> lookup;\n    bool built = false;\n    int n, lg;\n    vector<S>\
    \ v;\n\n    sparse_table(int n) : n(n), v(n, e()) {}\n\n    sparse_table(const\
    \ vector<S> &v) : n(v.size()), v(v) {}\n\n    void set(int i, S x) {\n       \
    \ assert(0 <= i && i < n);\n        assert(built == false);\n        v[i] = x;\n\
    \    }\n\n    void build() {\n        n = v.size();\n        lg = 0;\n       \
    \ while ((1LL << lg) <= n) lg++;\n        d.resize(lg, vector<S>(1LL << lg, e()));\n\
    \        for (int i = 0; i < n; i++) {\n            d[0][i] = v[i];\n        }\n\
    \        for (int i = 1; i < lg; i++) {\n            for (int j = 0; j + (1LL\
    \ << i) <= (1LL << lg); j++) {\n                d[i][j] = op(d[i - 1][j], d[i\
    \ - 1][j + (1LL << (i - 1))]);\n            }\n        }\n        lookup.resize(n\
    \ + 1);\n        for (int i = 2; i < int(lookup.size()); i++) {\n            lookup[i]\
    \ = lookup[i >> 1] + 1;\n        }\n        built = true;\n    }\n\n    S get(int\
    \ i) {\n        assert(0 <= i && i < n);\n        return v[i];\n    }\n\n    S\
    \ prod(int l, int r) {\n        assert(built == true);\n        assert(0 <= l\
    \ && r <= n);\n        if (l >= r) return e();\n        int LG = lookup[r - l];\n\
    \        return op(d[LG][l], d[LG][r - (1LL << LG)]);\n    }\n};\n\n/*\n@brief\
    \ sparse_table\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-08-26 00:04:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Datastructure_sprase_table.test.cpp
documentation_of: Datastructure/sparse_table.hpp
layout: document
redirect_from:
- /library/Datastructure/sparse_table.hpp
- /library/Datastructure/sparse_table.hpp.html
title: sparse_table
---

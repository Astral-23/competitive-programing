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
    \ engine() % (r - l) + l;\n}\nstring rndstr(ll len, char l, char r) {\n    string\
    \ res;\n    for (int i = 0; i < len; i++) res += l + rnd(0, int(r - l));\n   \
    \ return res;\n}\ntemplate <typename T> vector<T> rndvec(ll len, T l, T r) {\n\
    \    vector<T> res(len);\n    for (T &x : res) x = rnd<T>(l, r);\n    return res;\n\
    }\nvector<pair<int, int>> rndtree(int n) {\n    vector<pair<int, int>> res;\n\
    \    atcoder::dsu uf(n);\n    while (uf.size(0) != n) {\n        int u = rnd(0,\
    \ n);\n        int v = rnd(0, n - 1);\n        if (v >= u) v++;\n        if (uf.same(u,\
    \ v))\n            continue;\n        else {\n            uf.merge(u, v);\n  \
    \          res.emplace_back(u, v);\n        }\n    }\n    return res;\n}\n\ntemplate\
    \ <bool simple> vector<pair<int, int>> rndgraph(int n, int m) {\n    vector<pair<int,\
    \ int>> res;\n    set<pair<int, int>> cnt;\n    while (int(res.size()) < m) {\n\
    \        int u = rnd(0, n);\n        int v = rnd(0, n);\n        if (u == v &&\
    \ simple) continue;\n        if (u > v) swap(u, v);\n        if (simple && cnt.count(make_pair(u,\
    \ v))) continue;\n        res.emplace_back(u, v);\n        if (simple) cnt.insert(make_pair(u,\
    \ v));\n    }\n    return res;\n}  // \u9023\u7D50\u3068\u306F\u9650\u3089\u306A\
    \u3044\u304B\u3089\u6CE8\u610F\n\ntemplate <bool simple> vector<pair<int, int>>\
    \ rndgraph_connected(int n) {\n    vector<pair<int, int>> res;\n    set<pair<int,\
    \ int>> cnt;\n    atcoder::dsu uf(n);\n    while (uf.size(0) != n) {\n       \
    \ int u = rnd(0, n);\n        int v = rnd(0, n);\n        if (u == v && simple)\
    \ continue;\n        if (u > v) swap(u, v);\n        if (simple && cnt.count(make_pair(u,\
    \ v))) continue;\n        res.emplace_back(u, v);\n        uf.merge(u, v);\n \
    \       if (simple) cnt.insert(make_pair(u, v));\n    }\n    return res;\n}\n\
    }  // namespace RNG\nusing namespace RNG;\n"
  code: "namespace RNG {\nstatic mt19937_64 engine(clock());\ntemplate <typename T\
    \ = long long> T rnd(T l, T r) {\n    return engine() % (r - l) + l;\n}\nstring\
    \ rndstr(ll len, char l, char r) {\n    string res;\n    for (int i = 0; i < len;\
    \ i++) res += l + rnd(0, int(r - l));\n    return res;\n}\ntemplate <typename\
    \ T> vector<T> rndvec(ll len, T l, T r) {\n    vector<T> res(len);\n    for (T\
    \ &x : res) x = rnd<T>(l, r);\n    return res;\n}\nvector<pair<int, int>> rndtree(int\
    \ n) {\n    vector<pair<int, int>> res;\n    atcoder::dsu uf(n);\n    while (uf.size(0)\
    \ != n) {\n        int u = rnd(0, n);\n        int v = rnd(0, n - 1);\n      \
    \  if (v >= u) v++;\n        if (uf.same(u, v))\n            continue;\n     \
    \   else {\n            uf.merge(u, v);\n            res.emplace_back(u, v);\n\
    \        }\n    }\n    return res;\n}\n\ntemplate <bool simple> vector<pair<int,\
    \ int>> rndgraph(int n, int m) {\n    vector<pair<int, int>> res;\n    set<pair<int,\
    \ int>> cnt;\n    while (int(res.size()) < m) {\n        int u = rnd(0, n);\n\
    \        int v = rnd(0, n);\n        if (u == v && simple) continue;\n       \
    \ if (u > v) swap(u, v);\n        if (simple && cnt.count(make_pair(u, v))) continue;\n\
    \        res.emplace_back(u, v);\n        if (simple) cnt.insert(make_pair(u,\
    \ v));\n    }\n    return res;\n}  // \u9023\u7D50\u3068\u306F\u9650\u3089\u306A\
    \u3044\u304B\u3089\u6CE8\u610F\n\ntemplate <bool simple> vector<pair<int, int>>\
    \ rndgraph_connected(int n) {\n    vector<pair<int, int>> res;\n    set<pair<int,\
    \ int>> cnt;\n    atcoder::dsu uf(n);\n    while (uf.size(0) != n) {\n       \
    \ int u = rnd(0, n);\n        int v = rnd(0, n);\n        if (u == v && simple)\
    \ continue;\n        if (u > v) swap(u, v);\n        if (simple && cnt.count(make_pair(u,\
    \ v))) continue;\n        res.emplace_back(u, v);\n        uf.merge(u, v);\n \
    \       if (simple) cnt.insert(make_pair(u, v));\n    }\n    return res;\n}\n\
    }  // namespace RNG\nusing namespace RNG;"
  dependsOn: []
  isVerificationFile: false
  path: random/random_generator.hpp
  requiredBy: []
  timestamp: '2024-09-24 04:11:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/random_generator.hpp
layout: document
redirect_from:
- /library/random/random_generator.hpp
- /library/random/random_generator.hpp.html
title: random/random_generator.hpp
---

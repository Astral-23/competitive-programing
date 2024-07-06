---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/potential_dsu.test.cpp
    title: verify/potential_dsu.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: potential dsu
    links: []
  bundledCode: "#line 1 \"Datastructure/potential_dsu.hpp\"\nTT struct potential_dsu\
    \ {\n    using vi = vec<int>;\n    using vvi = vec<vi>;\n    vi par, sz, es;\n\
    \    vec<T> h;\n    int cc;\n    int root;\n\n    potential_dsu(int n, int ROOT)\
    \ : root(ROOT) {\n        par = vi(n);\n        sz = vi(n, 1);\n        es = vi(n,\
    \ 0);\n        cc = n;\n        iota(all(par), 0);\n\n        h = vec<T>(n, 0);\n\
    \    }\n\n    int leader(int u) {\n        if(par[u] != u) {\n            int\
    \ r = leader(par[u]);\n            h[u] += h[par[u]];\n            return par[u]\
    \ = r;\n        }\n        return u;\n    }\n\n    bool same(int a, int b) {\n\
    \        return leader(a) == leader(b);\n    }\n\n    bool merge(int s, int t,\
    \ T w) {\n        w += weight(s), w -= weight(t);\n        s = leader(s), t =\
    \ leader(t);\n        if(s == t) {\n            es[s]++;\n            return false;\n\
    \        }\n\n        if(sz[s] < sz[t] && s != root) {\n            swap(s, t);\n\
    \            w *= -1;\n        }\n\n        cc--;\n        par[t] = s;\n     \
    \   sz[s] += sz[t];\n        es[s] += es[t] + 1;\n\n        h[t] = w;\n      \
    \  return true;\n        \n    }\n\n    T weight(int v) {\n        leader(v);\n\
    \        return h[v];\n    }\n\n    T diff(int s, int t) {\n        return weight(t)\
    \ - weight(s);\n    }\n\n};\n\n/*\n@brief potential dsu\n*/\n\n"
  code: "TT struct potential_dsu {\n    using vi = vec<int>;\n    using vvi = vec<vi>;\n\
    \    vi par, sz, es;\n    vec<T> h;\n    int cc;\n    int root;\n\n    potential_dsu(int\
    \ n, int ROOT) : root(ROOT) {\n        par = vi(n);\n        sz = vi(n, 1);\n\
    \        es = vi(n, 0);\n        cc = n;\n        iota(all(par), 0);\n\n     \
    \   h = vec<T>(n, 0);\n    }\n\n    int leader(int u) {\n        if(par[u] !=\
    \ u) {\n            int r = leader(par[u]);\n            h[u] += h[par[u]];\n\
    \            return par[u] = r;\n        }\n        return u;\n    }\n\n    bool\
    \ same(int a, int b) {\n        return leader(a) == leader(b);\n    }\n\n    bool\
    \ merge(int s, int t, T w) {\n        w += weight(s), w -= weight(t);\n      \
    \  s = leader(s), t = leader(t);\n        if(s == t) {\n            es[s]++;\n\
    \            return false;\n        }\n\n        if(sz[s] < sz[t] && s != root)\
    \ {\n            swap(s, t);\n            w *= -1;\n        }\n\n        cc--;\n\
    \        par[t] = s;\n        sz[s] += sz[t];\n        es[s] += es[t] + 1;\n\n\
    \        h[t] = w;\n        return true;\n        \n    }\n\n    T weight(int\
    \ v) {\n        leader(v);\n        return h[v];\n    }\n\n    T diff(int s, int\
    \ t) {\n        return weight(t) - weight(s);\n    }\n\n};\n\n/*\n@brief potential\
    \ dsu\n*/\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/potential_dsu.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/potential_dsu.test.cpp
documentation_of: Datastructure/potential_dsu.hpp
layout: document
redirect_from:
- /library/Datastructure/potential_dsu.hpp
- /library/Datastructure/potential_dsu.hpp.html
title: potential dsu
---

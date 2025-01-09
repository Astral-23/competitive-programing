---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_potential_dsu.test.cpp
    title: verify/Datastructure_potential_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ T w) {// h[t] = h[s] + w \u6216\u3044\u306F s -> t\u306B\u91CD\u307Fw\u306E\u8FBA\
    \u3000  \n        w += weight(s), w -= weight(t);\n        s = leader(s), t =\
    \ leader(t);\n        if(s == t) {\n            es[s]++;\n            return false;\n\
    \        }\n\n        if(sz[s] < sz[t] && s != root) {\n            swap(s, t);\n\
    \            w *= -1;\n        }\n\n        cc--;\n        par[t] = s;\n     \
    \   sz[s] += sz[t];\n        es[s] += es[t] + 1;\n\n        h[t] = w;\n      \
    \  return true;\n        \n    }\n\n    T weight(int v) {//\u6839\u304B\u3089\u898B\
    \u305F v\u306E\u5024  p[\u6839]\u306F0\u3002\n        leader(v);\n        return\
    \ h[v];\n    }\n\n    T diff(int s, int t) {//s\u304B\u3089\u898B\u305F t\u306E\
    \u5024\n        return weight(t) - weight(s);\n    }\n\n};\n\n/*\n@brief potential\
    \ dsu\n*/\n\n"
  code: "TT struct potential_dsu {\n    using vi = vec<int>;\n    using vvi = vec<vi>;\n\
    \    vi par, sz, es;\n    vec<T> h;\n    int cc;\n    int root;\n\n    potential_dsu(int\
    \ n, int ROOT) : root(ROOT) {\n        par = vi(n);\n        sz = vi(n, 1);\n\
    \        es = vi(n, 0);\n        cc = n;\n        iota(all(par), 0);\n\n     \
    \   h = vec<T>(n, 0);\n    }\n\n    int leader(int u) {\n        if(par[u] !=\
    \ u) {\n            int r = leader(par[u]);\n            h[u] += h[par[u]];\n\
    \            return par[u] = r;\n        }\n        return u;\n    }\n\n    bool\
    \ same(int a, int b) {\n        return leader(a) == leader(b);\n    }\n\n    bool\
    \ merge(int s, int t, T w) {// h[t] = h[s] + w \u6216\u3044\u306F s -> t\u306B\
    \u91CD\u307Fw\u306E\u8FBA\u3000  \n        w += weight(s), w -= weight(t);\n \
    \       s = leader(s), t = leader(t);\n        if(s == t) {\n            es[s]++;\n\
    \            return false;\n        }\n\n        if(sz[s] < sz[t] && s != root)\
    \ {\n            swap(s, t);\n            w *= -1;\n        }\n\n        cc--;\n\
    \        par[t] = s;\n        sz[s] += sz[t];\n        es[s] += es[t] + 1;\n\n\
    \        h[t] = w;\n        return true;\n        \n    }\n\n    T weight(int\
    \ v) {//\u6839\u304B\u3089\u898B\u305F v\u306E\u5024  p[\u6839]\u306F0\u3002\n\
    \        leader(v);\n        return h[v];\n    }\n\n    T diff(int s, int t) {//s\u304B\
    \u3089\u898B\u305F t\u306E\u5024\n        return weight(t) - weight(s);\n    }\n\
    \n};\n\n/*\n@brief potential dsu\n*/\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/potential_dsu.hpp
  requiredBy: []
  timestamp: '2024-09-28 22:59:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Datastructure_potential_dsu.test.cpp
documentation_of: Datastructure/potential_dsu.hpp
layout: document
redirect_from:
- /library/Datastructure/potential_dsu.hpp
- /library/Datastructure/potential_dsu.hpp.html
title: potential dsu
---

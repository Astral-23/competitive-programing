---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/scc.test.cpp
    title: verify/scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: doc/scc.md
    document_title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"Algorithm/scc.hpp\"\nvec<int> SCC (vec<vec<int>> g) {\n\
    \    using vi = vec<int>;\n    using vvi = vec<vi>;\n\n    int n = g.size();\n\
    \    vvi rg(n);\n    vi vs, cmp(n, -1);\n    vec<bool> seen(n, false), nees(n,\
    \ false);\n\n    rep(i, 0, n) for(int to : g[i]) rg[to].push_back(i);\n\n    auto\
    \ dfs = [&](auto f, int v) -> void {\n        seen[v] = true;\n        for(auto\
    \ to : g[v]) if(!seen[to]) f(f, to);\n        vs.push_back(v);\n        return;\n\
    \    };\n\n    int k = 0;\n\n    auto sfd = [&](auto f, int v) -> void {\n   \
    \     nees[v] = true;\n        cmp[v] = k;\n        for(int to : rg[v]) if(!nees[to])\
    \ f(f, to);\n        return;\n    };\n\n    \n    rep(i, 0, n) if(!seen[i]) dfs(dfs,\
    \ i);\n    rrep(i, 0, vs.size()) if(!nees[vs[i]]) sfd(sfd, vs[i]), k++;\n    return\
    \ cmp;\n}\n\n/*\n@brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n@docs doc/scc.md\n\
    */\n"
  code: "vec<int> SCC (vec<vec<int>> g) {\n    using vi = vec<int>;\n    using vvi\
    \ = vec<vi>;\n\n    int n = g.size();\n    vvi rg(n);\n    vi vs, cmp(n, -1);\n\
    \    vec<bool> seen(n, false), nees(n, false);\n\n    rep(i, 0, n) for(int to\
    \ : g[i]) rg[to].push_back(i);\n\n    auto dfs = [&](auto f, int v) -> void {\n\
    \        seen[v] = true;\n        for(auto to : g[v]) if(!seen[to]) f(f, to);\n\
    \        vs.push_back(v);\n        return;\n    };\n\n    int k = 0;\n\n    auto\
    \ sfd = [&](auto f, int v) -> void {\n        nees[v] = true;\n        cmp[v]\
    \ = k;\n        for(int to : rg[v]) if(!nees[to]) f(f, to);\n        return;\n\
    \    };\n\n    \n    rep(i, 0, n) if(!seen[i]) dfs(dfs, i);\n    rrep(i, 0, vs.size())\
    \ if(!nees[vs[i]]) sfd(sfd, vs[i]), k++;\n    return cmp;\n}\n\n/*\n@brief \u5F37\
    \u9023\u7D50\u6210\u5206\u5206\u89E3\n@docs doc/scc.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/scc.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/scc.test.cpp
documentation_of: Algorithm/scc.hpp
layout: document
redirect_from:
- /library/Algorithm/scc.hpp
- /library/Algorithm/scc.hpp.html
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
## 概要
強連結成分分解をする

## 関数
頂点数を $n$ 、辺の本数を $m$ と置く。
- **vec\<int\> SCC(vec\<vec\<int\>\> g)** ... 強連結成分分解をし、サイズ $n$ の配列 $a$ を返す。この時、a[i] := グラフを強連結成分分解し、トポロジカルソートした場合、頂点番号iはトポロジカル順で何番目か(0-origin)
    - **計算量** $O(n + m)$

    

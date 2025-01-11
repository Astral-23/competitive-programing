---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Graph_scc_old.test.cpp
    title: verify/Graph_scc_old.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/scc.md
    document_title: scc_old
    links: []
  bundledCode: "#line 1 \"Graph/scc_old.hpp\"\nnamespace SCC {\nvec<int> ids(const\
    \ vec<vec<int>> &g) {\n    using vi = vec<int>;\n    using vvi = vec<vi>;\n\n\
    \    int n = g.size();\n    vvi rg(n);\n    vi vs, cmp(n, -1);\n    vec<bool>\
    \ seen(n, false), nees(n, false);\n\n    rep(i, 0, n) for (int to : g[i]) rg[to].push_back(i);\n\
    \n    auto dfs = [&](auto f, int v) -> void {\n        seen[v] = true;\n     \
    \   for (auto to : g[v])\n            if (!seen[to]) f(f, to);\n        vs.push_back(v);\n\
    \        return;\n    };\n\n    int k = 0;\n\n    auto sfd = [&](auto f, int v)\
    \ -> void {\n        nees[v] = true;\n        cmp[v] = k;\n        for (int to\
    \ : rg[v])\n            if (!nees[to]) f(f, to);\n        return;\n    };\n\n\
    \    rep(i, 0, n) if (!seen[i]) dfs(dfs, i);\n    rrep(i, 0, vs.size()) if (!nees[vs[i]])\
    \ sfd(sfd, vs[i]), k++;\n    return cmp;\n}\n\nvec<vec<int>> groups(const vec<vec<int>>\
    \ &g) {\n    int n = g.size();\n    vec<int> id = ids(g);\n\n    vec<vec<int>>\
    \ gs(n);\n    rep(i, 0, n) gs[id[i]].push_back(i);\n    while (gs.empty() == false\
    \ && gs.back().empty() == true) {\n        gs.pop_back();\n    }\n    return gs;\n\
    }\n\nvec<vec<int>> graph(const vec<vec<int>> &g) {\n    vec<int> id = ids(g);\n\
    \    int n = 0;\n    rep(i, 0, g.size()) chmax(n, id[i] + 1);\n\n    vec<vec<int>>\
    \ ng(n);\n    rep(i, 0, g.size()) for (int to : g[i]) {\n        if (id[i] ==\
    \ id[to]) continue;\n        ng[id[i]].push_back(id[to]);\n    }\n    return ng;\n\
    }\n\nvec<vec<int>> graph_rev(const vec<vec<int>> &g) {\n    auto ser = graph(g);\n\
    \    int n = ser.size();\n    vec<vec<int>> res(n);\n    rep(i, 0, n) for(int\
    \ to : ser[i]) {\n        res[to].push_back(i);\n    }\n    return res;\n}\n\n\
    }  // namespace SCC\n\n/*\n@brief scc_old\n@docs doc/scc.md\n*/\n"
  code: "namespace SCC {\nvec<int> ids(const vec<vec<int>> &g) {\n    using vi = vec<int>;\n\
    \    using vvi = vec<vi>;\n\n    int n = g.size();\n    vvi rg(n);\n    vi vs,\
    \ cmp(n, -1);\n    vec<bool> seen(n, false), nees(n, false);\n\n    rep(i, 0,\
    \ n) for (int to : g[i]) rg[to].push_back(i);\n\n    auto dfs = [&](auto f, int\
    \ v) -> void {\n        seen[v] = true;\n        for (auto to : g[v])\n      \
    \      if (!seen[to]) f(f, to);\n        vs.push_back(v);\n        return;\n \
    \   };\n\n    int k = 0;\n\n    auto sfd = [&](auto f, int v) -> void {\n    \
    \    nees[v] = true;\n        cmp[v] = k;\n        for (int to : rg[v])\n    \
    \        if (!nees[to]) f(f, to);\n        return;\n    };\n\n    rep(i, 0, n)\
    \ if (!seen[i]) dfs(dfs, i);\n    rrep(i, 0, vs.size()) if (!nees[vs[i]]) sfd(sfd,\
    \ vs[i]), k++;\n    return cmp;\n}\n\nvec<vec<int>> groups(const vec<vec<int>>\
    \ &g) {\n    int n = g.size();\n    vec<int> id = ids(g);\n\n    vec<vec<int>>\
    \ gs(n);\n    rep(i, 0, n) gs[id[i]].push_back(i);\n    while (gs.empty() == false\
    \ && gs.back().empty() == true) {\n        gs.pop_back();\n    }\n    return gs;\n\
    }\n\nvec<vec<int>> graph(const vec<vec<int>> &g) {\n    vec<int> id = ids(g);\n\
    \    int n = 0;\n    rep(i, 0, g.size()) chmax(n, id[i] + 1);\n\n    vec<vec<int>>\
    \ ng(n);\n    rep(i, 0, g.size()) for (int to : g[i]) {\n        if (id[i] ==\
    \ id[to]) continue;\n        ng[id[i]].push_back(id[to]);\n    }\n    return ng;\n\
    }\n\nvec<vec<int>> graph_rev(const vec<vec<int>> &g) {\n    auto ser = graph(g);\n\
    \    int n = ser.size();\n    vec<vec<int>> res(n);\n    rep(i, 0, n) for(int\
    \ to : ser[i]) {\n        res[to].push_back(i);\n    }\n    return res;\n}\n\n\
    }  // namespace SCC\n\n/*\n@brief scc_old\n@docs doc/scc.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/scc_old.hpp
  requiredBy: []
  timestamp: '2025-01-11 19:51:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Graph_scc_old.test.cpp
documentation_of: Graph/scc_old.hpp
layout: document
redirect_from:
- /library/Graph/scc_old.hpp
- /library/Graph/scc_old.hpp.html
title: scc_old
---
## 概要
強連結成分分解をする

## 関数
頂点数を $n$ 、辺の本数を $m$ と置く。
- **vec\<int\> SCC(vec\<vec\<int\>\> g)** ... 強連結成分分解をし、サイズ $n$ の配列 $a$ を返す。この時、a[i] := グラフを強連結成分分解し、トポロジカルソートした場合、頂点番号iはトポロジカル順で何番目か(0-origin)
    - **計算量** $O(n + m)$

    

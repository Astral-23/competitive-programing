---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/bi_connected.test.cpp
    title: verify/bi_connected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u30FB\
      BCT Tree"
    links: []
  bundledCode: "#line 1 \"Graph/bi_connected.hpp\"\nstruct bi_connected_components\
    \ : lowlink {\n    using lowlink::aux;\n    using lowlink::in;\n    using lowlink::low;\n\
    \    using lowlink::n;\n    using lowlink::tr;\n\n    int sz;            // \u6210\
    \u5206\u306E\u500B\u6570\u3002\n    vec<vec<int>> vs;  // \u9802\u70B9\u30EA\u30B9\
    \u30C8\u3002\n    vec<vec<pair<int, int>>> bc;  // \u8FBA\u30EA\u30B9\u30C8\u3002\
    vs[i] \u3068 bc[i]\u306F\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u3002\n    vec<bool>\
    \ seen;    // \u88DC\u52A9\n\n    bi_connected_components(const vvi &G)\n    \
    \    : lowlink(G), sz(0), vs(n), bc(n), seen(n, false) {\n        auto dfs_make\
    \ = [&](auto f, int v) -> void {\n            vs[sz].push_back(v);\n         \
    \   seen[v] = true;\n            for (int to : tr[v]) {\n                if (seen[to]\
    \ == false) {\n                    bc[sz].emplace_back(minmax(v, to));\n     \
    \               f(f, to);\n                }\n            }\n            for (int\
    \ to : aux[v]) {\n                bc[sz].emplace_back(minmax(v, to));\n      \
    \      }\n        };\n\n        auto dfs = [&](auto f, int v, int root) -> void\
    \ {\n            for (int to : tr[v]) {\n                f(f, to, root);\n   \
    \         }\n\n            for (int to : tr[v])\n                if (low[to] >=\
    \ in[v]) {\n                    dfs_make(dfs_make, to);\n                    bc[sz].emplace_back(minmax(v,\
    \ to));\n                    vs[sz].push_back(v);\n                    sz++;\n\
    \                }\n\n            if (v == root && tr[v].size() == 0) {\n    \
    \            dfs_make(dfs_make, v);\n                sz++;\n            }\n  \
    \      };\n\n        rep(i, 0, n) if (seen[i] == false) { dfs(dfs, i, i); }\n\
    \        vs.resize(sz);\n        bc.resize(sz);\n    }\n};\n\nstruct block_cut_tree\
    \ : bi_connected_components {\n    using bi_connected_components::vs;\n    using\
    \ lowlink::aux;\n    using lowlink::in;\n    using lowlink::low;\n    using lowlink::n;\n\
    \    using lowlink::tr;\n\n    vec<vec<int>> bct;\n    vec<int> bct_rev;\n   \
    \ vec<vec<int>> bct_vs;\n    int vsz;\n    block_cut_tree(const vvi &G)\n    \
    \    : bi_connected_components(G),\n          bct(joints.size() + vs.size()),\n\
    \          bct_rev(n),\n          bct_vs(joints.size() + vs.size()) {\n      \
    \  int id = 0;\n        rep(i, 0, n) if (is_joint(i)) {\n            bct_vs[id].push_back(i);\n\
    \            bct_rev[i] = id;\n            id++;\n        }\n\n        rep(i,\
    \ 0, vs.size()) {\n            for (int v : vs[i]) {\n                if (is_joint(v))\
    \ {\n                    bct[id].push_back(bct_rev[v]);\n                    bct[bct_rev[v]].push_back(id);\n\
    \                } else {\n                    bct_vs[id].push_back(v);\n    \
    \                bct_rev[v] = id;\n                }\n            }\n        \
    \    id++;\n        }\n    }\n\n    int operator()(int v) const { return bct_rev[v];\
    \ }\n};\n\n/*\n@brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u30FB\
    BCT Tree\n*/\n"
  code: "struct bi_connected_components : lowlink {\n    using lowlink::aux;\n   \
    \ using lowlink::in;\n    using lowlink::low;\n    using lowlink::n;\n    using\
    \ lowlink::tr;\n\n    int sz;            // \u6210\u5206\u306E\u500B\u6570\u3002\
    \n    vec<vec<int>> vs;  // \u9802\u70B9\u30EA\u30B9\u30C8\u3002\n    vec<vec<pair<int,\
    \ int>>> bc;  // \u8FBA\u30EA\u30B9\u30C8\u3002vs[i] \u3068 bc[i]\u306F\u540C\u3058\
    \u30B0\u30EB\u30FC\u30D7\u3002\n    vec<bool> seen;    // \u88DC\u52A9\n\n   \
    \ bi_connected_components(const vvi &G)\n        : lowlink(G), sz(0), vs(n), bc(n),\
    \ seen(n, false) {\n        auto dfs_make = [&](auto f, int v) -> void {\n   \
    \         vs[sz].push_back(v);\n            seen[v] = true;\n            for (int\
    \ to : tr[v]) {\n                if (seen[to] == false) {\n                  \
    \  bc[sz].emplace_back(minmax(v, to));\n                    f(f, to);\n      \
    \          }\n            }\n            for (int to : aux[v]) {\n           \
    \     bc[sz].emplace_back(minmax(v, to));\n            }\n        };\n\n     \
    \   auto dfs = [&](auto f, int v, int root) -> void {\n            for (int to\
    \ : tr[v]) {\n                f(f, to, root);\n            }\n\n            for\
    \ (int to : tr[v])\n                if (low[to] >= in[v]) {\n                \
    \    dfs_make(dfs_make, to);\n                    bc[sz].emplace_back(minmax(v,\
    \ to));\n                    vs[sz].push_back(v);\n                    sz++;\n\
    \                }\n\n            if (v == root && tr[v].size() == 0) {\n    \
    \            dfs_make(dfs_make, v);\n                sz++;\n            }\n  \
    \      };\n\n        rep(i, 0, n) if (seen[i] == false) { dfs(dfs, i, i); }\n\
    \        vs.resize(sz);\n        bc.resize(sz);\n    }\n};\n\nstruct block_cut_tree\
    \ : bi_connected_components {\n    using bi_connected_components::vs;\n    using\
    \ lowlink::aux;\n    using lowlink::in;\n    using lowlink::low;\n    using lowlink::n;\n\
    \    using lowlink::tr;\n\n    vec<vec<int>> bct;\n    vec<int> bct_rev;\n   \
    \ vec<vec<int>> bct_vs;\n    int vsz;\n    block_cut_tree(const vvi &G)\n    \
    \    : bi_connected_components(G),\n          bct(joints.size() + vs.size()),\n\
    \          bct_rev(n),\n          bct_vs(joints.size() + vs.size()) {\n      \
    \  int id = 0;\n        rep(i, 0, n) if (is_joint(i)) {\n            bct_vs[id].push_back(i);\n\
    \            bct_rev[i] = id;\n            id++;\n        }\n\n        rep(i,\
    \ 0, vs.size()) {\n            for (int v : vs[i]) {\n                if (is_joint(v))\
    \ {\n                    bct[id].push_back(bct_rev[v]);\n                    bct[bct_rev[v]].push_back(id);\n\
    \                } else {\n                    bct_vs[id].push_back(v);\n    \
    \                bct_rev[v] = id;\n                }\n            }\n        \
    \    id++;\n        }\n    }\n\n    int operator()(int v) const { return bct_rev[v];\
    \ }\n};\n\n/*\n@brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u30FB\
    BCT Tree\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bi_connected.hpp
  requiredBy: []
  timestamp: '2024-10-19 03:07:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/bi_connected.test.cpp
documentation_of: Graph/bi_connected.hpp
layout: document
redirect_from:
- /library/Graph/bi_connected.hpp
- /library/Graph/bi_connected.hpp.html
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u30FBBCT Tree"
---

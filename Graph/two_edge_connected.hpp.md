---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/two_edge_connected.test.cpp
    title: verify/two_edge_connected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"Graph/two_edge_connected.hpp\"\nstruct two_edge_connected_components\
    \ : lowlink {\n    using lowlink::aux;\n    using lowlink::in;\n    using lowlink::low;\n\
    \    using lowlink::n;\n    using lowlink::tr;\n    int sz;  // \u6210\u5206\u306E\
    \u500B\u6570\n    vi rev;  // \u9802\u70B9i\u304C\u5C5E\u3059\u308B\u6210\u5206\
    \u306E\u756A\u53F7\n    vvi g;   // \u7E2E\u7D04\u30B0\u30E9\u30D5\n    two_edge_connected_components(const\
    \ vvi &G)\n        : lowlink(G), sz(0), rev(n, -1), g(n) {\n        auto dfs =\
    \ [&](auto f, int v, int this_id) -> void {\n            rev[v] = this_id;\n \
    \           for (int to : G[v])\n                if (rev[to] == -1) {\n      \
    \              if (is_bridge(v, to)) {\n                        sz++;\n      \
    \                  g[this_id].push_back(sz - 1);\n                        g[sz\
    \ - 1].push_back(this_id);\n                        f(f, to, sz - 1);\n      \
    \              } else {\n                        f(f, to, this_id);\n        \
    \            }\n                }\n        };\n\n        rep(i, 0, n) if (rev[i]\
    \ == -1) {\n            sz++;\n            dfs(dfs, i, sz - 1);\n        }\n \
    \       g.resize(sz);\n    }\n\n    int operator()(int v) const { return rev[v];\
    \ }\n};\n/*\n@brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/\n"
  code: "struct two_edge_connected_components : lowlink {\n    using lowlink::aux;\n\
    \    using lowlink::in;\n    using lowlink::low;\n    using lowlink::n;\n    using\
    \ lowlink::tr;\n    int sz;  // \u6210\u5206\u306E\u500B\u6570\n    vi rev;  //\
    \ \u9802\u70B9i\u304C\u5C5E\u3059\u308B\u6210\u5206\u306E\u756A\u53F7\n    vvi\
    \ g;   // \u7E2E\u7D04\u30B0\u30E9\u30D5\n    two_edge_connected_components(const\
    \ vvi &G)\n        : lowlink(G), sz(0), rev(n, -1), g(n) {\n        auto dfs =\
    \ [&](auto f, int v, int this_id) -> void {\n            rev[v] = this_id;\n \
    \           for (int to : G[v])\n                if (rev[to] == -1) {\n      \
    \              if (is_bridge(v, to)) {\n                        sz++;\n      \
    \                  g[this_id].push_back(sz - 1);\n                        g[sz\
    \ - 1].push_back(this_id);\n                        f(f, to, sz - 1);\n      \
    \              } else {\n                        f(f, to, this_id);\n        \
    \            }\n                }\n        };\n\n        rep(i, 0, n) if (rev[i]\
    \ == -1) {\n            sz++;\n            dfs(dfs, i, sz - 1);\n        }\n \
    \       g.resize(sz);\n    }\n\n    int operator()(int v) const { return rev[v];\
    \ }\n};\n/*\n@brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/two_edge_connected.hpp
  requiredBy: []
  timestamp: '2024-10-19 03:07:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/two_edge_connected.test.cpp
documentation_of: Graph/two_edge_connected.hpp
layout: document
redirect_from:
- /library/Graph/two_edge_connected.hpp
- /library/Graph/two_edge_connected.hpp.html
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

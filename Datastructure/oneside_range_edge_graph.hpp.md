---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/oneside_range_edge_graph.test.cpp
    title: verify/oneside_range_edge_graph.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF(\u7279\
      \u6B8A\u7248)"
    links: []
  bundledCode: "#line 1 \"Datastructure/oneside_range_edge_graph.hpp\"\n/*\n\u6CE8\
    \u610F: \u3053\u308C\u306B\u3088\u308A\u5F97\u3089\u308C\u305F\u30B0\u30E9\u30D5\
    \u3067\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u5834\u5408\u3001\u9802\
    \u70B9\u756A\u53F7\u3092\u305A\u3089\u3057\u3066\u5229\u7528\u3059\u308B\u5FC5\
    \u8981\u304C\u3042\u308B\u3002\n\u7406\u7531: \u30BB\u30B0\u6728\u306E\u6700\u4E0B\
    \u6BB5\u3092\u751F\u306E\u9802\u70B9\u3068\u3057\u3066\u6271\u3063\u3066\u3044\
    \u308B\u3002\n*/\nstruct range_edge_graph {\n    #define pb push_back\n    struct\
    \ edge {\n        int to;\n        ll cost;\n        //ll cap; \u30D5\u30ED\u30FC\
    \u306A\u3089\u3053\u308C\u3082\u4F7F\u3046\u3002\n        edge(){}\n        edge(int\
    \ a, ll b, ll c) : to(a), cost(b) {}\n        //edge(int a, ll b, ll c) : to(a),\
    \ cost(b), cap(c) {}\n        //\u30D5\u30ED\u30FC\u306E\u6642\u306E\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n    };\n\n    edge e(int to) {\n        return\
    \ edge(to, 0, LLONG_MAX);\n    }\n  \n    int n;\n    int sz = 1;\n    int node;\n\
    \    vec<vec<edge>> g;\n\n    range_edge_graph(int N) : n(N) {\n        while(sz\
    \ < n) sz <<= 1;\n\n        g = vec<vec<edge>>(2 * sz);\n        node = 2 * sz;\n\
    \        rep(i, 1, sz) {\n            g[i].pb( e(i * 2) );\n            g[i].pb(\
    \ e(i * 2 + 1 ) );\n        }\n    }\n\n    void point_range(int s, int tl, int\
    \ tr, ll cost) {\n        s += sz;\n        tl += sz;\n        tr += sz;\n\n \
    \       while(tl < tr) {\n            if(tl & 1) g[s].pb( edge(tl, cost, 0) ),\
    \ tl++;\n            if(tr & 1) tr--, g[s].pb( edge(tr, cost, 0) ); \n       \
    \     tl >>= 1, tr >>= 1;\n        }\n    }\n\n    void range_point(int sl, int\
    \ sr, int t, ll cost) {\n        sl += sz;\n        sr += sz;\n        t += sz;\n\
    \n        while(sl < sr) {\n            if(sl & 1) g[sl].pb( edge(t, cost, 0)\
    \ ), sl++;\n            if(sr & 1) sr--, g[sr].pb ( edge(t, cost, 0) );\n    \
    \        sl >>= 1, sr >>= 1;\n        }\n    }\n\n    void add_edge(int s, int\
    \ t, ll cost, ll cap) {\n        s += sz, t += sz;\n        g[s].pb( edge(t, cost,\
    \ cap) );\n    }\n\n    vec<vec<edge>> graph() {\n        return g;\n    }\n\n\
    \    #undef pb\n};\n\n/*\n@brief \u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\
    \u30AF(\u7279\u6B8A\u7248)\n*/\n"
  code: "/*\n\u6CE8\u610F: \u3053\u308C\u306B\u3088\u308A\u5F97\u3089\u308C\u305F\u30B0\
    \u30E9\u30D5\u3067\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u5834\u5408\
    \u3001\u9802\u70B9\u756A\u53F7\u3092\u305A\u3089\u3057\u3066\u5229\u7528\u3059\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n\u7406\u7531: \u30BB\u30B0\u6728\u306E\
    \u6700\u4E0B\u6BB5\u3092\u751F\u306E\u9802\u70B9\u3068\u3057\u3066\u6271\u3063\
    \u3066\u3044\u308B\u3002\n*/\nstruct range_edge_graph {\n    #define pb push_back\n\
    \    struct edge {\n        int to;\n        ll cost;\n        //ll cap; \u30D5\
    \u30ED\u30FC\u306A\u3089\u3053\u308C\u3082\u4F7F\u3046\u3002\n        edge(){}\n\
    \        edge(int a, ll b, ll c) : to(a), cost(b) {}\n        //edge(int a, ll\
    \ b, ll c) : to(a), cost(b), cap(c) {}\n        //\u30D5\u30ED\u30FC\u306E\u6642\
    \u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    };\n\n    edge e(int to)\
    \ {\n        return edge(to, 0, LLONG_MAX);\n    }\n  \n    int n;\n    int sz\
    \ = 1;\n    int node;\n    vec<vec<edge>> g;\n\n    range_edge_graph(int N) :\
    \ n(N) {\n        while(sz < n) sz <<= 1;\n\n        g = vec<vec<edge>>(2 * sz);\n\
    \        node = 2 * sz;\n        rep(i, 1, sz) {\n            g[i].pb( e(i * 2)\
    \ );\n            g[i].pb( e(i * 2 + 1 ) );\n        }\n    }\n\n    void point_range(int\
    \ s, int tl, int tr, ll cost) {\n        s += sz;\n        tl += sz;\n       \
    \ tr += sz;\n\n        while(tl < tr) {\n            if(tl & 1) g[s].pb( edge(tl,\
    \ cost, 0) ), tl++;\n            if(tr & 1) tr--, g[s].pb( edge(tr, cost, 0) );\
    \ \n            tl >>= 1, tr >>= 1;\n        }\n    }\n\n    void range_point(int\
    \ sl, int sr, int t, ll cost) {\n        sl += sz;\n        sr += sz;\n      \
    \  t += sz;\n\n        while(sl < sr) {\n            if(sl & 1) g[sl].pb( edge(t,\
    \ cost, 0) ), sl++;\n            if(sr & 1) sr--, g[sr].pb ( edge(t, cost, 0)\
    \ );\n            sl >>= 1, sr >>= 1;\n        }\n    }\n\n    void add_edge(int\
    \ s, int t, ll cost, ll cap) {\n        s += sz, t += sz;\n        g[s].pb( edge(t,\
    \ cost, cap) );\n    }\n\n    vec<vec<edge>> graph() {\n        return g;\n  \
    \  }\n\n    #undef pb\n};\n\n/*\n@brief \u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\
    \u30C6\u30AF(\u7279\u6B8A\u7248)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/oneside_range_edge_graph.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/oneside_range_edge_graph.test.cpp
documentation_of: Datastructure/oneside_range_edge_graph.hpp
layout: document
redirect_from:
- /library/Datastructure/oneside_range_edge_graph.hpp
- /library/Datastructure/oneside_range_edge_graph.hpp.html
title: "\u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF(\u7279\u6B8A\u7248)"
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/range_edge_graph.hpp
    title: "\u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF"
  - icon: ':question:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i\
    \ < (ll)(t); i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s);\
    \ i--)\n#define all(x) begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n\n\
    #define TT template<typename T>\nTT using vec = vector<T>;\ntemplate<class T1,\
    \ class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y, true) : false; }\n\
    template<class T1, class T2> bool chmax(T1 &x, T2 y) { return x < y ? (x = y,\
    \ true) : false; }\n\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line\
    \ 1 \"Datastructure/range_edge_graph.hpp\"\nstruct range_edge_graph {\n    #define\
    \ pb push_back\n    struct edge {\n        int to;\n        ll cost;\n       \
    \ //ll cap; \u30D5\u30ED\u30FC\u306A\u3089\u3053\u308C\u3082\u4F7F\u3046\u3002\
    \n        edge(){}\n        edge(int a, ll b, ll c) : to(a), cost(b) {}\n    \
    \    //edge(int a, ll b, ll c) : to(a), cost(b), cap(c) {}\n        //\u30D5\u30ED\
    \u30FC\u306E\u6642\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    };\n\n\
    \    edge e(int to) {\n        return edge(to, 0, LLONG_MAX/4);\n    }\n  \n \
    \   int n;\n    int sz = 1;\n    int node;\n    vec<vec<edge>> g;\n\n    range_edge_graph(int\
    \ N) : n(N) {\n        while(sz < n) sz <<= 1;\n\n        g = vec<vec<edge>>(n\
    \ + 4 * sz);\n        node = n + 4 * sz;\n\n        rep(i, 1, sz) {\n        \
    \    g[i + n].pb( e(i * 2 + n) );\n            g[i + n].pb( e(i * 2 + 1 + n) );\n\
    \n            g[i * 2 + n + 2 * sz].pb( e(i + n + 2 * sz) );\n            g[i\
    \ * 2 + 1 + n + 2 * sz].pb( e(i + n + 2 * sz) );\n        }\n\n        rep(i,\
    \ 0, n) {\n            g[i + n + sz].pb( e(i) );\n            g[i].pb( e(i + n\
    \ + 3 * sz) );\n        }\n    }\n\n    void add_edge(int sl, int sr, int tl,\
    \ int tr, ll cost, ll cap) {\n        int nw = node++;\n        int nw2 = node++;\n\
    \        g.pb({ edge( nw2, cost, cap ) });\n        g.pb(vec<edge>());\n\n   \
    \     sl += sz;\n        sr += sz;\n        while(sl < sr) {\n            if(sl\
    \ & 1) g[sl + n + 2 * sz].pb( e(nw) ), sl++;\n            if(sr & 1) sr--, g[sr\
    \ + n + 2 * sz].pb( e(nw) );\n            sl >>= 1; sr >>= 1;\n        }\n\n \
    \       tl += sz;\n        tr += sz;\n        while(tl < tr) {\n            if(tl\
    \ & 1) g[nw2].pb( e(tl + n) ), tl++;\n            if(tr & 1) tr--, g[nw2].pb(\
    \ e(tr + n) ); \n            tl >>= 1, tr >>= 1;\n        }\n    }\n\n    void\
    \ add_edge(int s, int t, ll cost, ll cap) {\n        g[s].pb( edge(t, cost, cap)\
    \ );\n    }\n\n    vec<vec<edge>> graph() {\n        return g;\n    }\n\n    #undef\
    \ pb\n};\n\n/*\n@brief \u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF\n\
    @docs doc/range_edge_graph.md\n*/\n#line 3 \"example/range_edge_graph.example.cpp\"\
    \n\n\nint main() {\n    int n = 10;\n    range_edge_graph gh(n); //n\u9802\u70B9\
    \u3067\u7121\u8FBA\u306E\u30B0\u30E9\u30D5\u3092\u751F\u6210\u3002\n\n    gh.add_edge(0,\
    \ 3, 6, 9, 10, -1); // [0, 3) \u306E\u9802\u70B9\u304B\u3089 [6, 9) \u306B\u5411\
    \u3051\u3066 \u91CD\u307F = 10\u306E\u8FBA\u3092\u8FFD\u52A0\u3002\n\n    gh.add_edge(6,\
    \ 9, 9, 10, 5, -1); //[6, 9) \u306E\u9802\u70B9\u304B\u3089 [9, 10) \u306E\u9802\
    \u70B9\u306B\u5411\u3051\u3066\u3000\u91CD\u307F = 5\u306E\u8FBA\u3092\u8FFD\u52A0\
    \u3002\n\n    gh.add_edge(0, 9, 30, -1); // 0 \u304B\u3089 9 \u306B\u3000\u91CD\
    \u307F = 30\u306E\u8FBA\u3092\u8FFD\u52A0\u3002\n\n    auto g = gh.graph();\n\
    \    int new_n = g.size();\n    //0\u304B\u30899\u3078\u306E\u6700\u77ED\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B\u3002\n    \n    vec<int> dist(new_n, 100000);\n\
    \    dist[0] = 0;\n    priority_queue<pair<int, int>, vector<pair<int, int>>,\
    \ greater<pair<int, int>>> que;\n    que.emplace(0, 0);\n\n    while(!que.empty())\
    \ {\n        auto [c, v] = que.top();\n        que.pop();\n        if(dist[v]\
    \ < c) continue;\n\n        for(auto e : g[v]) {\n            if(chmin(dist[e.to],\
    \ e.cost + c)) {\n                que.emplace(dist[e.to], e.to);\n           \
    \ }\n        }\n    }\n\n    cout << dist[9] << endl; //15\n}\n"
  code: "#include \"../Utility/template.hpp\"\n#include \"../Datastructure/range_edge_graph.hpp\"\
    \n\n\nint main() {\n    int n = 10;\n    range_edge_graph gh(n); //n\u9802\u70B9\
    \u3067\u7121\u8FBA\u306E\u30B0\u30E9\u30D5\u3092\u751F\u6210\u3002\n\n    gh.add_edge(0,\
    \ 3, 6, 9, 10, -1); // [0, 3) \u306E\u9802\u70B9\u304B\u3089 [6, 9) \u306B\u5411\
    \u3051\u3066 \u91CD\u307F = 10\u306E\u8FBA\u3092\u8FFD\u52A0\u3002\n\n    gh.add_edge(6,\
    \ 9, 9, 10, 5, -1); //[6, 9) \u306E\u9802\u70B9\u304B\u3089 [9, 10) \u306E\u9802\
    \u70B9\u306B\u5411\u3051\u3066\u3000\u91CD\u307F = 5\u306E\u8FBA\u3092\u8FFD\u52A0\
    \u3002\n\n    gh.add_edge(0, 9, 30, -1); // 0 \u304B\u3089 9 \u306B\u3000\u91CD\
    \u307F = 30\u306E\u8FBA\u3092\u8FFD\u52A0\u3002\n\n    auto g = gh.graph();\n\
    \    int new_n = g.size();\n    //0\u304B\u30899\u3078\u306E\u6700\u77ED\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B\u3002\n    \n    vec<int> dist(new_n, 100000);\n\
    \    dist[0] = 0;\n    priority_queue<pair<int, int>, vector<pair<int, int>>,\
    \ greater<pair<int, int>>> que;\n    que.emplace(0, 0);\n\n    while(!que.empty())\
    \ {\n        auto [c, v] = que.top();\n        que.pop();\n        if(dist[v]\
    \ < c) continue;\n\n        for(auto e : g[v]) {\n            if(chmin(dist[e.to],\
    \ e.cost + c)) {\n                que.emplace(dist[e.to], e.to);\n           \
    \ }\n        }\n    }\n\n    cout << dist[9] << endl; //15\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/range_edge_graph.hpp
  isVerificationFile: false
  path: example/range_edge_graph.example.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: example/range_edge_graph.example.cpp
layout: document
redirect_from:
- /library/example/range_edge_graph.example.cpp
- /library/example/range_edge_graph.example.cpp.html
title: example/range_edge_graph.example.cpp
---

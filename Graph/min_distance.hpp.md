---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/bellman_ford.test.cpp
    title: verify/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.test.cpp
    title: verify/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/min_distance.md
    document_title: "\u6700\u77ED\u7D4C\u8DEF"
    links: []
  bundledCode: "#line 1 \"Graph/min_distance.hpp\"\n\ntemplate <typename T> struct\
    \ min_distance {\n    using pll = pair<ll, ll>;\n\n  private:\n    int n, s;\n\
    \    vec<vec<pll>> g;\n    vec<ll> dist;\n    vec<T> cnt;\n    vec<int> pre;\n\
    \    int built;\n    ll inf = LLONG_MAX / 4;\n\n    void init() {\n        fill(all(dist),\
    \ inf);\n        fill(all(cnt), 0);\n        fill(all(pre), -1);\n    }\n\n  public:\n\
    \    min_distance(int n) : n(n), dist(n), cnt(n), pre(n), built(0) {};\n    min_distance(int\
    \ n, vec<vec<pll>> &g)\n        : n(n), g(g), dist(n), cnt(n), pre(n), built(0)\
    \ {}\n\n    void add_edge(int from, int to, ll cost) { g[from].emplace_back(cost,\
    \ to); }\n\n    void run_dijkstra(int S) {\n        built = 1;\n        init();\n\
    \        s = S;\n        dist[s] = 0;\n        cnt[s] = 1;\n        priority_queue<pair<ll,\
    \ ll>, vector<pair<ll, ll>>,\n                       greater<pair<ll, ll>>>\n\
    \            que;\n        que.push({dist[s], s});\n        while (que.empty()\
    \ == false) {\n            auto [c, v] = que.top();\n            que.pop();\n\
    \            if (dist[v] < c) continue;\n            for (auto [cost, to] : g[v])\
    \ {\n                if (chmin(dist[to], cost + c)) {\n                    cnt[to]\
    \ = cnt[v];\n                    pre[to] = v;\n                    que.push({dist[to],\
    \ to});\n\n                } else if (dist[to] == cost + c) {\n              \
    \      cnt[to] += cnt[v];\n                }\n            }\n        }\n    }\n\
    \n    bool run_bellman_ford(int S) {\n        built = 2;\n        init();\n  \
    \      s = S;\n        dist[s] = 0;\n        cnt[s] = 1;\n        int last = -1;\n\
    \        rep(i, 0, n) {\n            bool found = false;\n            rep(v, 0,\
    \ n) if (dist[v] != inf) {\n                for (auto [cost, to] : g[v]) {\n \
    \                   if (chmin(dist[to], dist[v] + cost)) {\n                 \
    \       found = true;\n                        pre[to] = v;\n                \
    \    }\n                }\n            }\n            if (found) last = i;\n \
    \       }\n\n        if (last == n - 1) return true;\n        return false;\n\
    \    }\n\n    vec<vec<ll>> run_warshall_floyd() {\n        vec<vec<ll>> d(n, vec<ll>(n,\
    \ inf));\n        rep(i, 0, n) d[i][i] = 0;\n        rep(i, 0, n) for (auto [cost,\
    \ to] : g[i]) {\n            chmin(d[i][to], cost);\n            chmin(d[to][i],\
    \ cost);\n        }\n\n        rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {\n    \
    \        chmin(d[i][j], d[i][k] + d[k][j]);\n        }\n        return d;\n  \
    \  }\n\n    vec<ll> distance() {\n        assert(built != 0);\n        return\
    \ dist;\n    }\n\n    vec<T> count_path() {\n        assert(built == 1);\n   \
    \     return cnt;\n    }\n\n    vec<int> path(int t) {\n        assert(built !=\
    \ 0);\n        vec<int> res;\n        while (1) {\n            res.push_back(t);\n\
    \            if (t == s) break;\n            t = pre[t];\n        }\n        reverse(all(res));\n\
    \        return res;\n    }\n};\n/*\n@brief \u6700\u77ED\u7D4C\u8DEF\n@docs doc/min_distance.md\n\
    */\n"
  code: "\ntemplate <typename T> struct min_distance {\n    using pll = pair<ll, ll>;\n\
    \n  private:\n    int n, s;\n    vec<vec<pll>> g;\n    vec<ll> dist;\n    vec<T>\
    \ cnt;\n    vec<int> pre;\n    int built;\n    ll inf = LLONG_MAX / 4;\n\n   \
    \ void init() {\n        fill(all(dist), inf);\n        fill(all(cnt), 0);\n \
    \       fill(all(pre), -1);\n    }\n\n  public:\n    min_distance(int n) : n(n),\
    \ dist(n), cnt(n), pre(n), built(0) {};\n    min_distance(int n, vec<vec<pll>>\
    \ &g)\n        : n(n), g(g), dist(n), cnt(n), pre(n), built(0) {}\n\n    void\
    \ add_edge(int from, int to, ll cost) { g[from].emplace_back(cost, to); }\n\n\
    \    void run_dijkstra(int S) {\n        built = 1;\n        init();\n       \
    \ s = S;\n        dist[s] = 0;\n        cnt[s] = 1;\n        priority_queue<pair<ll,\
    \ ll>, vector<pair<ll, ll>>,\n                       greater<pair<ll, ll>>>\n\
    \            que;\n        que.push({dist[s], s});\n        while (que.empty()\
    \ == false) {\n            auto [c, v] = que.top();\n            que.pop();\n\
    \            if (dist[v] < c) continue;\n            for (auto [cost, to] : g[v])\
    \ {\n                if (chmin(dist[to], cost + c)) {\n                    cnt[to]\
    \ = cnt[v];\n                    pre[to] = v;\n                    que.push({dist[to],\
    \ to});\n\n                } else if (dist[to] == cost + c) {\n              \
    \      cnt[to] += cnt[v];\n                }\n            }\n        }\n    }\n\
    \n    bool run_bellman_ford(int S) {\n        built = 2;\n        init();\n  \
    \      s = S;\n        dist[s] = 0;\n        cnt[s] = 1;\n        int last = -1;\n\
    \        rep(i, 0, n) {\n            bool found = false;\n            rep(v, 0,\
    \ n) if (dist[v] != inf) {\n                for (auto [cost, to] : g[v]) {\n \
    \                   if (chmin(dist[to], dist[v] + cost)) {\n                 \
    \       found = true;\n                        pre[to] = v;\n                \
    \    }\n                }\n            }\n            if (found) last = i;\n \
    \       }\n\n        if (last == n - 1) return true;\n        return false;\n\
    \    }\n\n    vec<vec<ll>> run_warshall_floyd() {\n        vec<vec<ll>> d(n, vec<ll>(n,\
    \ inf));\n        rep(i, 0, n) d[i][i] = 0;\n        rep(i, 0, n) for (auto [cost,\
    \ to] : g[i]) {\n            chmin(d[i][to], cost);\n            chmin(d[to][i],\
    \ cost);\n        }\n\n        rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {\n    \
    \        chmin(d[i][j], d[i][k] + d[k][j]);\n        }\n        return d;\n  \
    \  }\n\n    vec<ll> distance() {\n        assert(built != 0);\n        return\
    \ dist;\n    }\n\n    vec<T> count_path() {\n        assert(built == 1);\n   \
    \     return cnt;\n    }\n\n    vec<int> path(int t) {\n        assert(built !=\
    \ 0);\n        vec<int> res;\n        while (1) {\n            res.push_back(t);\n\
    \            if (t == s) break;\n            t = pre[t];\n        }\n        reverse(all(res));\n\
    \        return res;\n    }\n};\n/*\n@brief \u6700\u77ED\u7D4C\u8DEF\n@docs doc/min_distance.md\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/min_distance.hpp
  requiredBy: []
  timestamp: '2024-08-31 23:47:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/bellman_ford.test.cpp
  - verify/dijkstra.test.cpp
documentation_of: Graph/min_distance.hpp
layout: document
redirect_from:
- /library/Graph/min_distance.hpp
- /library/Graph/min_distance.hpp.html
title: "\u6700\u77ED\u7D4C\u8DEF"
---
## 概要
最短距離
{距離、頂点}の集合を入れてね
bellman_fordのpathのverifyしてない
count_path(経路数)verifyしてない(atcoderで通った事があるぐらいの認識)
inf = LLONG_MAX / 4であることに気をつけてね(辿り着けるかの判定をLLONG_MAXとかLLONG_MAX/2出しないでね)


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
    links: []
  bundledCode: "#line 1 \"Graph/min_distance.hpp\"\ntemplate <typename T> struct min_distance\
    \ {\n    using pll = pair<ll, ll>;\n\n  private:\n    int n, s;\n    vec<vec<pll>>\
    \ g;\n    vec<ll> dist;\n    vec<T> cnt;\n    vec<int> pre;\n    int built;\n\
    \    ll inf = LLONG_MAX / 4;\n\n    void init() {\n        fill(all(dist), inf);\n\
    \        fill(all(cnt), 0);\n        fill(all(pre), -1);\n    }\n\n  public:\n\
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
    \ n) if(dist[v] != inf) {\n                for (auto [cost, to] : g[v]) {\n  \
    \                  if (chmin(dist[to], dist[v] + cost)) {\n                  \
    \      found = true;\n                        pre[to] = v;\n                 \
    \   }\n                }\n            }\n            if(found) last = i;\n   \
    \     }\n\n        if(last == n - 1) return true;\n        return false;\n   \
    \ }\n\n    vec<ll> distance() {\n        assert(built != 0);\n        return dist;\n\
    \    }\n\n    vec<T> count_path() {\n        assert(built == 1);\n        return\
    \ cnt;\n    }\n\n    vec<int> path(int t) {\n        assert(built != 0);\n   \
    \     vec<int> res;\n        while (1) {\n            res.push_back(t);\n    \
    \        if (t == s) break;\n            t = pre[t];\n        }\n        reverse(all(res));\n\
    \        return res;\n    }\n};\n"
  code: "template <typename T> struct min_distance {\n    using pll = pair<ll, ll>;\n\
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
    \ n) if(dist[v] != inf) {\n                for (auto [cost, to] : g[v]) {\n  \
    \                  if (chmin(dist[to], dist[v] + cost)) {\n                  \
    \      found = true;\n                        pre[to] = v;\n                 \
    \   }\n                }\n            }\n            if(found) last = i;\n   \
    \     }\n\n        if(last == n - 1) return true;\n        return false;\n   \
    \ }\n\n    vec<ll> distance() {\n        assert(built != 0);\n        return dist;\n\
    \    }\n\n    vec<T> count_path() {\n        assert(built == 1);\n        return\
    \ cnt;\n    }\n\n    vec<int> path(int t) {\n        assert(built != 0);\n   \
    \     vec<int> res;\n        while (1) {\n            res.push_back(t);\n    \
    \        if (t == s) break;\n            t = pre[t];\n        }\n        reverse(all(res));\n\
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/min_distance.hpp
  requiredBy: []
  timestamp: '2024-08-28 13:18:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dijkstra.test.cpp
  - verify/bellman_ford.test.cpp
documentation_of: Graph/min_distance.hpp
layout: document
redirect_from:
- /library/Graph/min_distance.hpp
- /library/Graph/min_distance.hpp.html
title: Graph/min_distance.hpp
---

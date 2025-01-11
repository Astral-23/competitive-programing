---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/scc.hpp
    title: "scc(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Graph_graph_bellman.test.cpp
    title: verify/Graph_graph_bellman.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Graph_graph_bellman_and_warshall.test.cpp
    title: verify/Graph_graph_bellman_and_warshall.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Graph_graph_cycle_detection_directed.test.cpp
    title: verify/Graph_graph_cycle_detection_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Graph_graph_cycle_detection_undirected.test.cpp
    title: verify/Graph_graph_cycle_detection_undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Graph_graph_dijkstra.test.cpp
    title: verify/Graph_graph_dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Graph_scc.test.cpp
    title: verify/Graph_scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/graph.hpp\"\ntemplate <typename T> struct Edge {\n\
    \    int to;\n    T cost;\n    int id;\n    static constexpr T INF = numeric_limits<T>::max()\
    \ / 2;\n    Edge(int to = 0, T cost = 0, int id = -1) : to(to), cost(cost), id(id)\
    \ {}\n};\n\ntemplate <typename T, bool directed> struct Graph : vector<vector<Edge<T>>>\
    \ {\n#define n int(this->size())\n#define inf Edge<T>::INF\n    using vector<vector<Edge<T>>>::vector;\n\
    \n  private:\n    bool chmin(T &x, T y) const { return x > y ? (x = y, true) :\
    \ false; }\n\n  public:\n    void add(int s, int t, T w, int id = -1) { add_edge(s,\
    \ t, w, id); }\n    void add_edge(int s, int t, T w, int id = -1) {\n        (*this)[s].emplace_back(t,\
    \ w, id);\n        if constexpr (directed == false) {\n            (*this)[t].emplace_back(s,\
    \ w, id);\n        }\n    }\n\n    vector<T> DFS(int s) const {\n        assert(0\
    \ <= s && s < n);\n        vector<T> d(n, inf);\n        d[s] = 0;\n        queue<int>\
    \ que;\n        que.push(s);\n        while (que.empty() == false) {\n       \
    \     int v = que.front();\n            que.pop();\n            for (auto e :\
    \ (*this)[v]) {\n                assert(e.cost == 1);\n                if (chmin(d[e.to],\
    \ d[v] + e.cost)) {\n                    que.push(e.to);\n                }\n\
    \            }\n        }\n        return d;\n    }\n\n    vector<T> dijkstra(int\
    \ s) const {\n        vector<T> d(n, inf);\n        d[s] = 0;\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>,\n                       greater<pair<T, int>>>\n\
    \            que;\n        que.push({d[s], s});\n        while (que.empty() ==\
    \ false) {\n            auto [c, v] = que.top();\n            que.pop();\n   \
    \         if (d[v] < c) continue;\n            for (auto e : (*this)[v]) {\n \
    \               assert(e.cost >= 0);\n                if (chmin(d[e.to], d[v]\
    \ + e.cost)) {\n                    que.push({d[e.to], e.to});\n             \
    \   }\n            }\n        }\n        return d;\n    }\n\n    pair<bool, vector<T>>\
    \ bellman_ford(int s) const {\n        vector<T> d(n, inf);\n        d[s] = 0;\n\
    \        int last = -1;\n        for (int i = 0; i <= n; i++) {\n            bool\
    \ f = false;\n            for (int v = 0; v < n; v++)\n                if (d[v]\
    \ != inf) {\n                    for (auto e : (*this)[v]) {\n               \
    \         if (chmin(d[e.to], d[v] + e.cost)) {\n                            f\
    \ = true;\n                        }\n                    }\n                }\n\
    \            if (f) last = i;\n        }\n\n        if (last == n)\n         \
    \   return {true, d};\n        else\n            return {false, d};\n    }\n\n\
    \    bool has_negative_cycle() const {\n        if (this->size() == 0) return\
    \ false;\n        auto [f, d] = bellman_ford(0);\n        return f;\n    }\n\n\
    \    vector<vector<T>> warshall() const {\n        vector<vector<T>> d(n, vector<T>(n,\
    \ inf));\n        for (int i = 0; i < n; i++) {\n            d[i][i] = 0;\n  \
    \          for (auto e : (*this)[i]) {\n                chmin(d[i][e.to], e.cost);\n\
    \            }\n        }\n\n        for (int k = 0; k < n; k++) {\n         \
    \   for (int i = 0; i < n; i++) {\n                if (d[i][k] == inf) continue;\n\
    \                for (int j = 0; j < n; j++) {\n                    if (d[k][j]\
    \ == inf) continue;\n                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n\
    \                }\n            }\n        }\n        return d;\n    }\n\n   \
    \ pair<vector<int>, vector<int>> cycle_detection(int v = -1) const {\n       \
    \ vector<bool> in(n, false), out(n, false);\n        vector<int> vs, es;\n   \
    \     const int fin = INT_MAX;\n        auto dfs = [&](auto f, int v, int p) ->\
    \ int {\n            bool prev_edge = false;\n            in[v] = true;\n    \
    \        for (auto e : (*this)[v]) {\n                if constexpr (directed ==\
    \ false) {\n                    if (e.to == p) {\n                        if (prev_edge\
    \ == false) {\n                            prev_edge = true;\n               \
    \             continue;\n                        } else {\n                  \
    \          vs.push_back(v);\n                            es.push_back(e.id);\n\
    \                            out[v] = true;\n                            return\
    \ e.to;\n                        }\n                    }\n                }\n\
    \n                if (in[e.to] && out[e.to] == false) {\n                    vs.push_back(v);\n\
    \                    es.push_back(e.id);\n                    out[v] = true;\n\
    \                    return v == e.to ? fin : e.to;\n                }\n\n   \
    \             if (in[e.to] == false) {\n                    int root = f(f, e.to,\
    \ v);\n                    if (root != -1 && root != fin) {\n                \
    \        vs.push_back(v);\n                        es.push_back(e.id);\n     \
    \                   out[v] = true;\n                        return (v == root\
    \ ? fin : root);\n                    } else if (root == fin) {\n            \
    \            out[v] = true;\n                        return fin;\n           \
    \         }\n                }\n            }\n            out[v] = true;\n  \
    \          return -1;\n        };\n\n        int s = 0, t = n;\n        if (v\
    \ != -1) s = v, t = v + 1;\n\n        for (int i = s; i < t; i++) {\n        \
    \    if (in[i] == false) {\n                dfs(dfs, i, -1);\n               \
    \ if (vs.empty() == false) {\n                    reverse(vs.begin(), vs.end());\n\
    \                    reverse(es.begin(), es.end());\n                    return\
    \ make_pair(vs, es);\n                }\n            }\n        }\n        return\
    \ make_pair(vs, es);\n    }\n\n#undef n\n#undef inf\n};\n"
  code: "template <typename T> struct Edge {\n    int to;\n    T cost;\n    int id;\n\
    \    static constexpr T INF = numeric_limits<T>::max() / 2;\n    Edge(int to =\
    \ 0, T cost = 0, int id = -1) : to(to), cost(cost), id(id) {}\n};\n\ntemplate\
    \ <typename T, bool directed> struct Graph : vector<vector<Edge<T>>> {\n#define\
    \ n int(this->size())\n#define inf Edge<T>::INF\n    using vector<vector<Edge<T>>>::vector;\n\
    \n  private:\n    bool chmin(T &x, T y) const { return x > y ? (x = y, true) :\
    \ false; }\n\n  public:\n    void add(int s, int t, T w, int id = -1) { add_edge(s,\
    \ t, w, id); }\n    void add_edge(int s, int t, T w, int id = -1) {\n        (*this)[s].emplace_back(t,\
    \ w, id);\n        if constexpr (directed == false) {\n            (*this)[t].emplace_back(s,\
    \ w, id);\n        }\n    }\n\n    vector<T> DFS(int s) const {\n        assert(0\
    \ <= s && s < n);\n        vector<T> d(n, inf);\n        d[s] = 0;\n        queue<int>\
    \ que;\n        que.push(s);\n        while (que.empty() == false) {\n       \
    \     int v = que.front();\n            que.pop();\n            for (auto e :\
    \ (*this)[v]) {\n                assert(e.cost == 1);\n                if (chmin(d[e.to],\
    \ d[v] + e.cost)) {\n                    que.push(e.to);\n                }\n\
    \            }\n        }\n        return d;\n    }\n\n    vector<T> dijkstra(int\
    \ s) const {\n        vector<T> d(n, inf);\n        d[s] = 0;\n        priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>,\n                       greater<pair<T, int>>>\n\
    \            que;\n        que.push({d[s], s});\n        while (que.empty() ==\
    \ false) {\n            auto [c, v] = que.top();\n            que.pop();\n   \
    \         if (d[v] < c) continue;\n            for (auto e : (*this)[v]) {\n \
    \               assert(e.cost >= 0);\n                if (chmin(d[e.to], d[v]\
    \ + e.cost)) {\n                    que.push({d[e.to], e.to});\n             \
    \   }\n            }\n        }\n        return d;\n    }\n\n    pair<bool, vector<T>>\
    \ bellman_ford(int s) const {\n        vector<T> d(n, inf);\n        d[s] = 0;\n\
    \        int last = -1;\n        for (int i = 0; i <= n; i++) {\n            bool\
    \ f = false;\n            for (int v = 0; v < n; v++)\n                if (d[v]\
    \ != inf) {\n                    for (auto e : (*this)[v]) {\n               \
    \         if (chmin(d[e.to], d[v] + e.cost)) {\n                            f\
    \ = true;\n                        }\n                    }\n                }\n\
    \            if (f) last = i;\n        }\n\n        if (last == n)\n         \
    \   return {true, d};\n        else\n            return {false, d};\n    }\n\n\
    \    bool has_negative_cycle() const {\n        if (this->size() == 0) return\
    \ false;\n        auto [f, d] = bellman_ford(0);\n        return f;\n    }\n\n\
    \    vector<vector<T>> warshall() const {\n        vector<vector<T>> d(n, vector<T>(n,\
    \ inf));\n        for (int i = 0; i < n; i++) {\n            d[i][i] = 0;\n  \
    \          for (auto e : (*this)[i]) {\n                chmin(d[i][e.to], e.cost);\n\
    \            }\n        }\n\n        for (int k = 0; k < n; k++) {\n         \
    \   for (int i = 0; i < n; i++) {\n                if (d[i][k] == inf) continue;\n\
    \                for (int j = 0; j < n; j++) {\n                    if (d[k][j]\
    \ == inf) continue;\n                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n\
    \                }\n            }\n        }\n        return d;\n    }\n\n   \
    \ pair<vector<int>, vector<int>> cycle_detection(int v = -1) const {\n       \
    \ vector<bool> in(n, false), out(n, false);\n        vector<int> vs, es;\n   \
    \     const int fin = INT_MAX;\n        auto dfs = [&](auto f, int v, int p) ->\
    \ int {\n            bool prev_edge = false;\n            in[v] = true;\n    \
    \        for (auto e : (*this)[v]) {\n                if constexpr (directed ==\
    \ false) {\n                    if (e.to == p) {\n                        if (prev_edge\
    \ == false) {\n                            prev_edge = true;\n               \
    \             continue;\n                        } else {\n                  \
    \          vs.push_back(v);\n                            es.push_back(e.id);\n\
    \                            out[v] = true;\n                            return\
    \ e.to;\n                        }\n                    }\n                }\n\
    \n                if (in[e.to] && out[e.to] == false) {\n                    vs.push_back(v);\n\
    \                    es.push_back(e.id);\n                    out[v] = true;\n\
    \                    return v == e.to ? fin : e.to;\n                }\n\n   \
    \             if (in[e.to] == false) {\n                    int root = f(f, e.to,\
    \ v);\n                    if (root != -1 && root != fin) {\n                \
    \        vs.push_back(v);\n                        es.push_back(e.id);\n     \
    \                   out[v] = true;\n                        return (v == root\
    \ ? fin : root);\n                    } else if (root == fin) {\n            \
    \            out[v] = true;\n                        return fin;\n           \
    \         }\n                }\n            }\n            out[v] = true;\n  \
    \          return -1;\n        };\n\n        int s = 0, t = n;\n        if (v\
    \ != -1) s = v, t = v + 1;\n\n        for (int i = s; i < t; i++) {\n        \
    \    if (in[i] == false) {\n                dfs(dfs, i, -1);\n               \
    \ if (vs.empty() == false) {\n                    reverse(vs.begin(), vs.end());\n\
    \                    reverse(es.begin(), es.end());\n                    return\
    \ make_pair(vs, es);\n                }\n            }\n        }\n        return\
    \ make_pair(vs, es);\n    }\n\n#undef n\n#undef inf\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/graph.hpp
  requiredBy:
  - Graph/scc.hpp
  timestamp: '2025-01-11 19:51:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Graph_graph_bellman_and_warshall.test.cpp
  - verify/Graph_scc.test.cpp
  - verify/Graph_graph_cycle_detection_undirected.test.cpp
  - verify/Graph_graph_bellman.test.cpp
  - verify/Graph_graph_dijkstra.test.cpp
  - verify/Graph_graph_cycle_detection_directed.test.cpp
documentation_of: Graph/graph.hpp
layout: document
redirect_from:
- /library/Graph/graph.hpp
- /library/Graph/graph.hpp.html
title: Graph/graph.hpp
---

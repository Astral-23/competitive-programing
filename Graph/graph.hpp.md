---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Graph_graph_bellman.test.cpp
    title: verify/Graph_graph_bellman.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Graph_graph_bellman_and_warshall.test.cpp
    title: verify/Graph_graph_bellman_and_warshall.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Graph_graph_dijkstra.test.cpp
    title: verify/Graph_graph_dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/graph.hpp\"\ntemplate <typename T> struct Edge {\n\
    \    int to;\n    T cost;\n    int id;\n    static constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n    Edge(int to = 0, T cost = 0, int id = -1) : to(to), cost(cost), id(id)\
    \ {}\n};\n\ntemplate <typename T, bool directed> struct Graph : vector<vector<Edge<T>>>\
    \ {\n    using vector<vector<Edge<T>>>::vector;\n\n  private:\n    bool chmin(T\
    \ &x, T y) const { return x > y ? (x = y, true) : false; }\n\n  public:\n    void\
    \ add(int s, int t, T w, int id = -1) { add_edge(s, t, w, id); }\n    void add_edge(int\
    \ s, int t, T w, int id = -1) {\n        (*this)[s].emplace_back(t, w, id);\n\
    \        if constexpr (directed == false) {\n            (this)[t].emplace_back(s,\
    \ w, id);\n        }\n    }\n\n    vector<T> dfs(int s) const {\n        assert(0\
    \ <= s && s < this->size());\n        vector<T> d(this->size());\n        d[s]\
    \ = 0;\n        queue<int> que;\n        que.push(s);\n        while (que.empty()\
    \ == false) {\n            int v = que.front();\n            que.pop();\n    \
    \        for (auto e : (*this)[v]) {\n                assert(e.cost == 1);\n \
    \               if (chmin(d[e.to], d[v] + e.cost)) {\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n    }\n\n    vector<T> dijkstra(int\
    \ s) const {\n        vector<T> d(this->size(), Edge<T>::inf);\n        d[s] =\
    \ 0;\n        priority_queue<pair<T, int>, vector<pair<T, int>>,\n           \
    \            greater<pair<T, int>>>\n            que;\n        que.push({d[s],\
    \ s});\n        while (que.empty() == false) {\n            auto [c, v] = que.top();\n\
    \            que.pop();\n            if (d[v] < c) continue;\n            for\
    \ (auto e : (*this)[v]) {\n                assert(e.cost >= 0);\n            \
    \    if (chmin(d[e.to], d[v] + e.cost)) {\n                    que.push({d[e.to],\
    \ e.to});\n                }\n            }\n        }\n        return d;\n  \
    \  }\n\n    pair<bool, vector<T>> bellman_ford(int s) const {\n        vector<T>\
    \ d(this->size(), Edge<T>::inf);\n        d[s] = 0;\n        int last = -1;\n\
    \        for (int i = 0; i <= int(this->size()); i++) {\n            bool f =\
    \ false;\n            for (int v = 0; v < int(this->size()); v++)\n          \
    \      if (d[v] != Edge<T>::inf) {\n                    for (auto e : (*this)[v])\
    \ {\n                        if (chmin(d[e.to], d[v] + e.cost)) {\n          \
    \                  f = true;\n                        }\n                    }\n\
    \                }\n            if (f) last = i;\n        }\n\n        if (last\
    \ == int(this->size()))\n            return {true, d};\n        else\n       \
    \     return {false, d};\n    }\n\n    bool has_negative_cycle() const {\n   \
    \     if (this->size() == 0) return false;\n        auto [f, d] = bellman_ford(0);\n\
    \        return f;\n    }\n\n    vector<vector<T>> warshall() const {\n      \
    \  vector<vector<T>> d(this->size(),\n                            vector<T>(this->size(),\
    \ Edge<T>::inf));\n        for (int i = 0; i < int(this->size()); i++) {\n   \
    \         d[i][i] = 0;\n            for (auto e : (*this)[i]) {\n            \
    \    chmin(d[i][e.to], e.cost);\n            }\n        }\n        for (int k\
    \ = 0; k < int(this->size()); k++) {\n            for (int i = 0; i < int(this->size());\
    \ i++) {\n                if (d[i][k] == Edge<T>::inf) continue;\n           \
    \     for (int j = 0; j < int(this->size()); j++) {\n                    if (d[k][j]\
    \ == Edge<T>::inf) continue;\n                    d[i][j] = min(d[i][j], d[i][k]\
    \ + d[k][j]);\n                }\n            }\n        }\n        return d;\n\
    \    }\n};\n"
  code: "template <typename T> struct Edge {\n    int to;\n    T cost;\n    int id;\n\
    \    static constexpr T inf = numeric_limits<T>::max() / 2;\n    Edge(int to =\
    \ 0, T cost = 0, int id = -1) : to(to), cost(cost), id(id) {}\n};\n\ntemplate\
    \ <typename T, bool directed> struct Graph : vector<vector<Edge<T>>> {\n    using\
    \ vector<vector<Edge<T>>>::vector;\n\n  private:\n    bool chmin(T &x, T y) const\
    \ { return x > y ? (x = y, true) : false; }\n\n  public:\n    void add(int s,\
    \ int t, T w, int id = -1) { add_edge(s, t, w, id); }\n    void add_edge(int s,\
    \ int t, T w, int id = -1) {\n        (*this)[s].emplace_back(t, w, id);\n   \
    \     if constexpr (directed == false) {\n            (this)[t].emplace_back(s,\
    \ w, id);\n        }\n    }\n\n    vector<T> dfs(int s) const {\n        assert(0\
    \ <= s && s < this->size());\n        vector<T> d(this->size());\n        d[s]\
    \ = 0;\n        queue<int> que;\n        que.push(s);\n        while (que.empty()\
    \ == false) {\n            int v = que.front();\n            que.pop();\n    \
    \        for (auto e : (*this)[v]) {\n                assert(e.cost == 1);\n \
    \               if (chmin(d[e.to], d[v] + e.cost)) {\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n    }\n\n    vector<T> dijkstra(int\
    \ s) const {\n        vector<T> d(this->size(), Edge<T>::inf);\n        d[s] =\
    \ 0;\n        priority_queue<pair<T, int>, vector<pair<T, int>>,\n           \
    \            greater<pair<T, int>>>\n            que;\n        que.push({d[s],\
    \ s});\n        while (que.empty() == false) {\n            auto [c, v] = que.top();\n\
    \            que.pop();\n            if (d[v] < c) continue;\n            for\
    \ (auto e : (*this)[v]) {\n                assert(e.cost >= 0);\n            \
    \    if (chmin(d[e.to], d[v] + e.cost)) {\n                    que.push({d[e.to],\
    \ e.to});\n                }\n            }\n        }\n        return d;\n  \
    \  }\n\n    pair<bool, vector<T>> bellman_ford(int s) const {\n        vector<T>\
    \ d(this->size(), Edge<T>::inf);\n        d[s] = 0;\n        int last = -1;\n\
    \        for (int i = 0; i <= int(this->size()); i++) {\n            bool f =\
    \ false;\n            for (int v = 0; v < int(this->size()); v++)\n          \
    \      if (d[v] != Edge<T>::inf) {\n                    for (auto e : (*this)[v])\
    \ {\n                        if (chmin(d[e.to], d[v] + e.cost)) {\n          \
    \                  f = true;\n                        }\n                    }\n\
    \                }\n            if (f) last = i;\n        }\n\n        if (last\
    \ == int(this->size()))\n            return {true, d};\n        else\n       \
    \     return {false, d};\n    }\n\n    bool has_negative_cycle() const {\n   \
    \     if (this->size() == 0) return false;\n        auto [f, d] = bellman_ford(0);\n\
    \        return f;\n    }\n\n    vector<vector<T>> warshall() const {\n      \
    \  vector<vector<T>> d(this->size(),\n                            vector<T>(this->size(),\
    \ Edge<T>::inf));\n        for (int i = 0; i < int(this->size()); i++) {\n   \
    \         d[i][i] = 0;\n            for (auto e : (*this)[i]) {\n            \
    \    chmin(d[i][e.to], e.cost);\n            }\n        }\n        for (int k\
    \ = 0; k < int(this->size()); k++) {\n            for (int i = 0; i < int(this->size());\
    \ i++) {\n                if (d[i][k] == Edge<T>::inf) continue;\n           \
    \     for (int j = 0; j < int(this->size()); j++) {\n                    if (d[k][j]\
    \ == Edge<T>::inf) continue;\n                    d[i][j] = min(d[i][j], d[i][k]\
    \ + d[k][j]);\n                }\n            }\n        }\n        return d;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/graph.hpp
  requiredBy: []
  timestamp: '2025-01-11 19:00:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Graph_graph_bellman_and_warshall.test.cpp
  - verify/Graph_graph_bellman.test.cpp
  - verify/Graph_graph_dijkstra.test.cpp
documentation_of: Graph/graph.hpp
layout: document
redirect_from:
- /library/Graph/graph.hpp
- /library/Graph/graph.hpp.html
title: Graph/graph.hpp
---

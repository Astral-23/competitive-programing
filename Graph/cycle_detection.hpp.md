---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/cycle_detection_1.test.cpp
    title: verify/cycle_detection_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/cycle_detection_2.test.cpp
    title: verify/cycle_detection_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/cycle_detection.hpp\"\ntemplate <bool directed> struct\
    \ cycle_detection {\n    int n, ec;\n    vector<vector<pair<int, int>>> g;\n \
    \   cycle_detection(int n) : n(n), ec(0), g(n) {}\n\n    void add_edge(int u,\
    \ int v) {\n        g[u].emplace_back(v, ec);\n        if (directed == false)\
    \ g[v].emplace_back(u, ec);\n        ec++;\n    }\n\n    pair<vector<int>, vector<int>>\
    \ run() {\n        vector<bool> in(n, false);\n        vector<bool> out(n, false);\n\
    \        vector<int> vs;\n        vector<int> es;\n        const int fin = INT_MAX;\n\
    \        auto dfs = [&](auto f, int v, int p) -> int {\n            bool prev_edge\
    \ = false;\n            in[v] = true;\n\n            for (auto [to, id] : g[v])\
    \ {\n                if (to == p) {\n                    if (directed == false)\
    \ {\n                        if (prev_edge == false) {\n                     \
    \       prev_edge = true;\n                            continue;\n           \
    \             } else {\n                            vs.push_back(v);\n       \
    \                     es.push_back(id);\n                            out[v] =\
    \ true;\n                            return to;\n                        }\n \
    \                   }\n                }\n\n                if (in[to] == true\
    \ && out[to] == false) {\n                    vs.push_back(v);\n             \
    \       es.push_back(id);\n                    out[v] = true;\n              \
    \      return (v == to ? fin : to);\n                }\n\n                if (in[to]\
    \ == false) {\n                    int root = f(f, to, v);\n                 \
    \   if (root != -1 && root != fin) {\n                        vs.push_back(v);\n\
    \                        es.push_back(id);\n                        out[v] = true;\n\
    \                        return (v == root ? fin : root);\n                  \
    \  } else if (root == fin) {\n                        out[v] = true;\n       \
    \                 return fin;\n                    }\n                }\n    \
    \        }\n            out[v] = true;\n            return -1;\n        };\n\n\
    \        for (int i = 0; i < n; i++) {\n            if (in[i] == false) {\n  \
    \              dfs(dfs, i, -1);\n                if (vs.empty() == false) {\n\
    \                    reverse(vs.begin(), vs.end());\n                    reverse(es.begin(),\
    \ es.end());\n                    return make_pair(vs, es);\n                }\n\
    \            }\n        }\n        return make_pair(vs, es);\n    }\n};\n"
  code: "template <bool directed> struct cycle_detection {\n    int n, ec;\n    vector<vector<pair<int,\
    \ int>>> g;\n    cycle_detection(int n) : n(n), ec(0), g(n) {}\n\n    void add_edge(int\
    \ u, int v) {\n        g[u].emplace_back(v, ec);\n        if (directed == false)\
    \ g[v].emplace_back(u, ec);\n        ec++;\n    }\n\n    pair<vector<int>, vector<int>>\
    \ run() {\n        vector<bool> in(n, false);\n        vector<bool> out(n, false);\n\
    \        vector<int> vs;\n        vector<int> es;\n        const int fin = INT_MAX;\n\
    \        auto dfs = [&](auto f, int v, int p) -> int {\n            bool prev_edge\
    \ = false;\n            in[v] = true;\n\n            for (auto [to, id] : g[v])\
    \ {\n                if (to == p) {\n                    if (directed == false)\
    \ {\n                        if (prev_edge == false) {\n                     \
    \       prev_edge = true;\n                            continue;\n           \
    \             } else {\n                            vs.push_back(v);\n       \
    \                     es.push_back(id);\n                            out[v] =\
    \ true;\n                            return to;\n                        }\n \
    \                   }\n                }\n\n                if (in[to] == true\
    \ && out[to] == false) {\n                    vs.push_back(v);\n             \
    \       es.push_back(id);\n                    out[v] = true;\n              \
    \      return (v == to ? fin : to);\n                }\n\n                if (in[to]\
    \ == false) {\n                    int root = f(f, to, v);\n                 \
    \   if (root != -1 && root != fin) {\n                        vs.push_back(v);\n\
    \                        es.push_back(id);\n                        out[v] = true;\n\
    \                        return (v == root ? fin : root);\n                  \
    \  } else if (root == fin) {\n                        out[v] = true;\n       \
    \                 return fin;\n                    }\n                }\n    \
    \        }\n            out[v] = true;\n            return -1;\n        };\n\n\
    \        for (int i = 0; i < n; i++) {\n            if (in[i] == false) {\n  \
    \              dfs(dfs, i, -1);\n                if (vs.empty() == false) {\n\
    \                    reverse(vs.begin(), vs.end());\n                    reverse(es.begin(),\
    \ es.end());\n                    return make_pair(vs, es);\n                }\n\
    \            }\n        }\n        return make_pair(vs, es);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2024-09-16 21:01:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/cycle_detection_1.test.cpp
  - verify/cycle_detection_2.test.cpp
documentation_of: Graph/cycle_detection.hpp
layout: document
redirect_from:
- /library/Graph/cycle_detection.hpp
- /library/Graph/cycle_detection.hpp.html
title: Graph/cycle_detection.hpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Graph_cycle_detection_1.test.cpp
    title: verify/Graph_cycle_detection_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Graph_cycle_detection_2.test.cpp
    title: verify/Graph_cycle_detection_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/cycle_detection.md
    document_title: cycle_detection
    links: []
  bundledCode: "#line 1 \"Graph/cycle_detection.hpp\"\ntemplate <bool directed> struct\
    \ cycle_detection {\n    int n, ec;\n    vector<vector<pair<int, int>>> g;\n \
    \   cycle_detection(int n) : n(n), ec(0), g(n) {}\n\n    void add_edge(int u,\
    \ int v) {\n        g[u].emplace_back(v, ec);\n        if (directed == false)\
    \ g[v].emplace_back(u, ec);\n        ec++;\n    }\n\n    pair<vector<int>, vector<int>>\
    \ run(int vertex = -1) {\n        vector<bool> in(n, false);\n        vector<bool>\
    \ out(n, false);\n        vector<int> vs;\n        vector<int> es;\n        const\
    \ int fin = INT_MAX;\n        auto dfs = [&](auto f, int v, int p) -> int {\n\
    \            bool prev_edge = false;\n            in[v] = true;\n\n          \
    \  for (auto [to, id] : g[v]) {\n                if (to == p) {\n            \
    \        if (directed == false) {\n                        if (prev_edge == false)\
    \ {\n                            prev_edge = true;\n                         \
    \   continue;\n                        } else {\n                            vs.push_back(v);\n\
    \                            es.push_back(id);\n                            out[v]\
    \ = true;\n                            return to;\n                        }\n\
    \                    }\n                }\n\n                if (in[to] == true\
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
    \        int s = 0, t = n;\n        if (vertex != -1) s = vertex, t = vertex +\
    \ 1;\n\n        for (int i = s; i < t; i++) {\n            if (in[i] == false)\
    \ {\n                dfs(dfs, i, -1);\n                if (vs.empty() == false)\
    \ {\n                    reverse(vs.begin(), vs.end());\n                    reverse(es.begin(),\
    \ es.end());\n                    return make_pair(vs, es);\n                }\n\
    \            }\n        }\n        return make_pair(vs, es);\n    }\n};\n/*\n\
    @brief cycle_detection\n@docs doc/cycle_detection.md\n*/\n"
  code: "template <bool directed> struct cycle_detection {\n    int n, ec;\n    vector<vector<pair<int,\
    \ int>>> g;\n    cycle_detection(int n) : n(n), ec(0), g(n) {}\n\n    void add_edge(int\
    \ u, int v) {\n        g[u].emplace_back(v, ec);\n        if (directed == false)\
    \ g[v].emplace_back(u, ec);\n        ec++;\n    }\n\n    pair<vector<int>, vector<int>>\
    \ run(int vertex = -1) {\n        vector<bool> in(n, false);\n        vector<bool>\
    \ out(n, false);\n        vector<int> vs;\n        vector<int> es;\n        const\
    \ int fin = INT_MAX;\n        auto dfs = [&](auto f, int v, int p) -> int {\n\
    \            bool prev_edge = false;\n            in[v] = true;\n\n          \
    \  for (auto [to, id] : g[v]) {\n                if (to == p) {\n            \
    \        if (directed == false) {\n                        if (prev_edge == false)\
    \ {\n                            prev_edge = true;\n                         \
    \   continue;\n                        } else {\n                            vs.push_back(v);\n\
    \                            es.push_back(id);\n                            out[v]\
    \ = true;\n                            return to;\n                        }\n\
    \                    }\n                }\n\n                if (in[to] == true\
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
    \        int s = 0, t = n;\n        if (vertex != -1) s = vertex, t = vertex +\
    \ 1;\n\n        for (int i = s; i < t; i++) {\n            if (in[i] == false)\
    \ {\n                dfs(dfs, i, -1);\n                if (vs.empty() == false)\
    \ {\n                    reverse(vs.begin(), vs.end());\n                    reverse(es.begin(),\
    \ es.end());\n                    return make_pair(vs, es);\n                }\n\
    \            }\n        }\n        return make_pair(vs, es);\n    }\n};\n/*\n\
    @brief cycle_detection\n@docs doc/cycle_detection.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2024-09-24 03:56:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Graph_cycle_detection_1.test.cpp
  - verify/Graph_cycle_detection_2.test.cpp
documentation_of: Graph/cycle_detection.hpp
layout: document
redirect_from:
- /library/Graph/cycle_detection.hpp
- /library/Graph/cycle_detection.hpp.html
title: cycle_detection
---
## 概要
cycle検出

## コンストラクタ 
`cycle_detection<directed> (int n)`  directed = true : 有向グラフ　/ directed = false : 無向グラフ　として、n頂点0辺のグラフを生成

## 関数
- `void add_edge(int u, int v)` ... directed = true : 辺 u -> vを追加 / directed = false : 辺 u <-> v を追加
    - 計算量 $O(1)$
  
- `pair<vec<int>, vec<int>> run(int vertex = -1)` ... サイクルを探す。 ((サイクルに含まれる頂点), (サイクルに使われた辺の番号(:= 何番目に追加されたか))) を返す。サイクルがない場合、空の配列を返す。頂点及び辺の格納時順は
  [こちら](https://judge.yosupo.jp/problem/cycle_detection_undirected)を参照
    - 計算量 $O(|V| + |E|)$
    - 備考 vertex に値を入れると、指定された頂点が含まれる連結成分についてのみ調べられる。functional graphのサイクル列挙等に使う。
    - 備考2 runは何回呼んでも良い。



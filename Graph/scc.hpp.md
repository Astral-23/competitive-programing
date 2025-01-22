---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Graph_scc.test.cpp
    title: verify/Graph_scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/scc.md
    document_title: "scc(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)"
    links: []
  bundledCode: "#line 1 \"Graph/graph.hpp\"\ntemplate <typename T> struct Edge {\n\
    \    int to;\n    T cost;\n    int id;\n    static constexpr T INF = numeric_limits<T>::max()\
    \ / 2;\n    Edge(int to = 0, T cost = 0, int id = -1) : to(to), cost(cost), id(id)\
    \ {}\n};\n\ntemplate <typename T, bool directed> struct Graph : vector<vector<Edge<T>>>\
    \ {\n#define n int(this->size())\n    using vector<vector<Edge<T>>>::vector;\n\
    \    void add(int s, int t, T w = 0, int id = -1) {\n        (*this)[s].emplace_back(t,\
    \ w, id);\n        if constexpr (directed == false) {\n            (*this)[t].emplace_back(s,\
    \ w, id);\n        }\n    }\n#undef n\n};\n\ntemplate <typename T> struct Tree\
    \ : Graph<T, false> {\n#define n int(this->size())\n    using Graph<T,false>::Graph;\n\
    #undef n\n};\n\nnamespace Graph_lib {\n\n#define inf Edge<T>::INF\ntemplate <typename\
    \ T, bool directed>\nvector<T> DFS(Graph<T, directed> const &g, int s) {\n   \
    \ int n = g.size();\n    assert(0 <= s && s < n);\n    vector<T> d(n, inf);\n\
    \    d[s] = 0;\n    queue<int> que;\n    que.push(s);\n    while (que.empty()\
    \ == false) {\n        int v = que.front();\n        que.pop();\n        for (auto\
    \ &e : g[v]) {\n            assert(e.cost == 1);\n            if (chmin(d[e.to],\
    \ d[v] + e.cost)) {\n                que.push(e.to);\n            }\n        }\n\
    \    }\n    return d;\n}\n\ntemplate <typename T, bool directed>\nvector<T> dijkstra(Graph<T,\
    \ directed> const &g, int s) {\n    int n = g.size();\n    vector<T> d(n, inf);\n\
    \    d[s] = 0;\n    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>>\n        que;\n    que.push({d[s], s});\n    while (que.empty() == false)\
    \ {\n        auto [c, v] = que.top();\n        que.pop();\n        if (d[v] <\
    \ c) continue;\n        for (auto &e : g[v]) {\n            assert(e.cost >= 0);\n\
    \            if (chmin(d[e.to], d[v] + e.cost)) {\n                que.push({d[e.to],\
    \ e.to});\n            }\n        }\n    }\n    return d;\n}\n\ntemplate <typename\
    \ T, bool directed>\npair<bool, vector<T>> bellman_ford(Graph<T, directed> const\
    \ &g, int s) {\n    int n = g.size();\n    vector<T> d(n, inf);\n    d[s] = 0;\n\
    \    int last = -1;\n    for (int i = 0; i <= n; i++) {\n        bool f = false;\n\
    \        for (int v = 0; v < n; v++)\n            if (d[v] != inf) {\n       \
    \         for (auto &e : g[v]) {\n                    if (chmin(d[e.to], d[v]\
    \ + e.cost)) {\n                        f = true;\n                    }\n   \
    \             }\n            }\n        if (f) last = i;\n    }\n\n    if (last\
    \ == n)\n        return {true, d};\n    else\n        return {false, d};\n}\n\n\
    template <typename T, bool directed>\nbool has_negative_cycle(Graph<T, directed>\
    \ const &g) {\n    if (g.size() == 0) return false;\n    auto [f, d] = bellman_ford(g,\
    \ 0);\n    return f;\n}\n\ntemplate <typename T, bool directed>\nvector<vector<T>>\
    \ warshall(Graph<T, directed> const &g) {\n    int n = g.size();\n    vector<vector<T>>\
    \ d(n, vector<T>(n, inf));\n    for (int i = 0; i < n; i++) {\n        d[i][i]\
    \ = 0;\n        for (auto &e : g[i]) {\n            chmin(d[i][e.to], e.cost);\n\
    \        }\n    }\n\n    for (int k = 0; k < n; k++) {\n        for (int i = 0;\
    \ i < n; i++) {\n            if (d[i][k] == inf) continue;\n            for (int\
    \ j = 0; j < n; j++) {\n                if (d[k][j] == inf) continue;\n      \
    \          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n            }\n       \
    \ }\n    }\n    return d;\n}\n\ntemplate <typename T, bool directed>\npair<vector<int>,\
    \ vector<int>> cycle_detection(Graph<T, directed> const &g,\n                \
    \                               int v = -1) {\n    int n = g.size();\n    vector<bool>\
    \ in(n, false), out(n, false);\n    vector<int> vs, es;\n    const int fin = INT_MAX;\n\
    \    auto dfs = [&](auto f, int v, int p) -> int {\n        bool prev_edge = false;\n\
    \        in[v] = true;\n        for (auto e : g[v]) {\n            if constexpr\
    \ (directed == false) {\n                if (e.to == p) {\n                  \
    \  if (prev_edge == false) {\n                        prev_edge = true;\n    \
    \                    continue;\n                    } else {\n               \
    \         vs.push_back(v);\n                        es.push_back(e.id);\n    \
    \                    out[v] = true;\n                        return e.to;\n  \
    \                  }\n                }\n            }\n\n            if (in[e.to]\
    \ && out[e.to] == false) {\n                vs.push_back(v);\n               \
    \ es.push_back(e.id);\n                out[v] = true;\n                return\
    \ v == e.to ? fin : e.to;\n            }\n\n            if (in[e.to] == false)\
    \ {\n                int root = f(f, e.to, v);\n                if (root != -1\
    \ && root != fin) {\n                    vs.push_back(v);\n                  \
    \  es.push_back(e.id);\n                    out[v] = true;\n                 \
    \   return (v == root ? fin : root);\n                } else if (root == fin)\
    \ {\n                    out[v] = true;\n                    return fin;\n   \
    \             }\n            }\n        }\n        out[v] = true;\n        return\
    \ -1;\n    };\n\n    int s = 0, t = n;\n    if (v != -1) s = v, t = v + 1;\n\n\
    \    for (int i = s; i < t; i++) {\n        if (in[i] == false) {\n          \
    \  dfs(dfs, i, -1);\n            if (vs.empty() == false) {\n                reverse(vs.begin(),\
    \ vs.end());\n                reverse(es.begin(), es.end());\n               \
    \ return make_pair(vs, es);\n            }\n        }\n    }\n    return make_pair(vs,\
    \ es);\n}\n#undef inf\n};  // namespace Graph_lib\n\nnamespace Tree_lib {\n#define\
    \ inf Edge<T>::INF\ntemplate <typename T> vector<T> dist(Tree<T> const &tr, int\
    \ s) {\n    int n = tr.size();\n    vector<T> res(n, inf);\n    res[s] = 0;\n\
    \    queue<int> que;\n    que.push(s);\n    while (!que.empty()) {\n        int\
    \ v = que.front();\n        que.pop();\n        for (auto &e : tr[v])\n      \
    \      if (chmin(res[e.to], res[v] + e.cost)) {\n                que.push(e.to);\n\
    \            }\n    }\n    return res;\n}\n\ntemplate <typename T> vector<Edge<T>>\
    \ path(Tree<T> const &tr, int s, int t) {\n    vector<Edge<T>> res;\n    auto\
    \ dfs = [&](auto f, int v, int p = -1) -> bool {\n        if (v == t) {\n    \
    \        res.push_back(v);\n            return true;\n        }\n\n        for\
    \ (auto &e : tr[v])\n            if (e.to != p) {\n                if (f(f, e.to,\
    \ v)) {\n                    res.push_back(e);\n                    return true;\n\
    \                }\n            }\n        return false;\n    };\n\n    dfs(dfs,\
    \ s);\n    return res;\n}\n\n// diam() ... (\u76F4\u5F84, (\u76F4\u5F84\u306E\u7AEF\
    u, \u76F4\u5F84\u306E\u7AEFv))\ntemplate <typename T> pair<T, pair<int, int>>\
    \ diam(Tree<T> const &tr) {\n    int n = tr.size();\n    int u, v;\n    T d, tmp;\n\
    \    vector<T> ds = dist(tr, 0);\n    tmp = ds[0], u = 0;\n    for (int i = 1;\
    \ i < n; i++) {\n        if (chmax(tmp, ds[i])) u = i;\n    }\n\n    vector<T>\
    \ ds2 = dist(tr, u);\n    d = ds2[0], v = 0;\n    for (int i = 1; i < n; i++)\
    \ {\n        if (chmax(d, ds2[i])) v = i;\n    }\n    pair<T, pair<int, int>>\
    \ res;\n    res.first = d;\n    res.second.first = u;\n    res.second.second =\
    \ v;\n    return res;\n}\n#undef inf\n};  // namespace Tree_lib\n#line 2 \"Graph/scc.hpp\"\
    \n\nnamespace SCC {\ntemplate <typename T> vector<int> ids(const Graph<T, true>\
    \ &g) {\n    int n = g.size();\n    vector<int> vs, cmp(n, -1);\n    vec<bool>\
    \ seen(n, false), nees(n, false);\n    Graph<T, true> rg(n);\n\n    rep(i, 0,\
    \ n) for (auto e : g[i]) rg.add(e.to, i, e.cost, e.id);\n    auto dfs = [&](auto\
    \ f, int v) -> void {\n        seen[v] = true;\n        for (auto e : g[v])\n\
    \            if (!seen[e.to]) f(f, e.to);\n        vs.push_back(v);\n        return;\n\
    \    };\n\n    int k = 0;\n\n    auto sfd = [&](auto f, int v) -> void {\n   \
    \     nees[v] = true;\n        cmp[v] = k;\n        for (auto e : rg[v])\n   \
    \         if (!nees[e.to]) f(f, e.to);\n        return;\n    };\n\n    rep(i,\
    \ 0, n) if (!seen[i]) dfs(dfs, i);\n    rrep(i, 0, vs.size()) if (!nees[vs[i]])\
    \ sfd(sfd, vs[i]), k++;\n    return cmp;\n}\n\ntemplate <typename T> vector<vector<int>>\
    \ groups(const Graph<T, true> &g) {\n    int n = g.size();\n    vector<int> id\
    \ = ids<T>(g);\n    vector<vector<int>> gs(n);\n    rep(i, 0, n) gs[id[i]].push_back(i);\n\
    \    while (gs.empty() == false && gs.back().empty() == true) {\n        gs.pop_back();\n\
    \    }\n    return gs;\n}\n\ntemplate <typename T> Graph<T, true> graph(const\
    \ Graph<T, true> &g) {\n    vector<int> id = ids<T>(g);\n    int n = 0;\n    rep(i,\
    \ 0, g.size()) chmax(n, id[i] + 1);\n\n    Graph<T, true> ng(n);\n    rep(i, 0,\
    \ g.size()) for (auto e : g[i]) {\n        if (id[i] == id[e.to]) continue;\n\
    \        ng.add(id[i], id[e.to], e.cost, e.id);\n    }\n    return ng;\n}\n\n\
    template <typename T> Graph<T, true> graph_rev(const Graph<T, true> &g) {\n  \
    \  auto ser = graph<T>(g);\n    int n = ser.size();\n    Graph<T, true> res(n);\n\
    \    rep(i, 0, n) for (auto e : ser[i]) { res.add(e.to, i, e.cost, e.id); }\n\
    \    return res;\n}\n\n}  // namespace SCC\n\n/*\n@brief scc(\u5F37\u9023\u7D50\
    \u6210\u5206\u5206\u89E3)\n@docs doc/scc.md\n*/\n"
  code: "#include \"../Graph/graph.hpp\"\n\nnamespace SCC {\ntemplate <typename T>\
    \ vector<int> ids(const Graph<T, true> &g) {\n    int n = g.size();\n    vector<int>\
    \ vs, cmp(n, -1);\n    vec<bool> seen(n, false), nees(n, false);\n    Graph<T,\
    \ true> rg(n);\n\n    rep(i, 0, n) for (auto e : g[i]) rg.add(e.to, i, e.cost,\
    \ e.id);\n    auto dfs = [&](auto f, int v) -> void {\n        seen[v] = true;\n\
    \        for (auto e : g[v])\n            if (!seen[e.to]) f(f, e.to);\n     \
    \   vs.push_back(v);\n        return;\n    };\n\n    int k = 0;\n\n    auto sfd\
    \ = [&](auto f, int v) -> void {\n        nees[v] = true;\n        cmp[v] = k;\n\
    \        for (auto e : rg[v])\n            if (!nees[e.to]) f(f, e.to);\n    \
    \    return;\n    };\n\n    rep(i, 0, n) if (!seen[i]) dfs(dfs, i);\n    rrep(i,\
    \ 0, vs.size()) if (!nees[vs[i]]) sfd(sfd, vs[i]), k++;\n    return cmp;\n}\n\n\
    template <typename T> vector<vector<int>> groups(const Graph<T, true> &g) {\n\
    \    int n = g.size();\n    vector<int> id = ids<T>(g);\n    vector<vector<int>>\
    \ gs(n);\n    rep(i, 0, n) gs[id[i]].push_back(i);\n    while (gs.empty() == false\
    \ && gs.back().empty() == true) {\n        gs.pop_back();\n    }\n    return gs;\n\
    }\n\ntemplate <typename T> Graph<T, true> graph(const Graph<T, true> &g) {\n \
    \   vector<int> id = ids<T>(g);\n    int n = 0;\n    rep(i, 0, g.size()) chmax(n,\
    \ id[i] + 1);\n\n    Graph<T, true> ng(n);\n    rep(i, 0, g.size()) for (auto\
    \ e : g[i]) {\n        if (id[i] == id[e.to]) continue;\n        ng.add(id[i],\
    \ id[e.to], e.cost, e.id);\n    }\n    return ng;\n}\n\ntemplate <typename T>\
    \ Graph<T, true> graph_rev(const Graph<T, true> &g) {\n    auto ser = graph<T>(g);\n\
    \    int n = ser.size();\n    Graph<T, true> res(n);\n    rep(i, 0, n) for (auto\
    \ e : ser[i]) { res.add(e.to, i, e.cost, e.id); }\n    return res;\n}\n\n}  //\
    \ namespace SCC\n\n/*\n@brief scc(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n\
    @docs doc/scc.md\n*/\n"
  dependsOn:
  - Graph/graph.hpp
  isVerificationFile: false
  path: Graph/scc.hpp
  requiredBy: []
  timestamp: '2025-01-22 14:18:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Graph_scc.test.cpp
documentation_of: Graph/scc.hpp
layout: document
redirect_from:
- /library/Graph/scc.hpp
- /library/Graph/scc.hpp.html
title: "scc(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)"
---
## 概要
強連結成分分解をする

## 関数
頂点数を $n$ 、辺の本数を $m$ と置く。
- **vec\<int\> SCC(vec\<vec\<int\>\> g)** ... 強連結成分分解をし、サイズ $n$ の配列 $a$ を返す。この時、a[i] := グラフを強連結成分分解し、トポロジカルソートした場合、頂点番号iはトポロジカル順で何番目か(0-origin)
    - **計算量** $O(n + m)$

    

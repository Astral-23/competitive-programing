---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/scc.hpp
    title: "scc(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)"
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/Graph_scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Graph/graph.hpp\"\
    \ntemplate <typename T> struct Edge {\n    int to;\n    T cost;\n    int id;\n\
    \    static constexpr T INF = numeric_limits<T>::max() / 2;\n    Edge(int to =\
    \ 0, T cost = 0, int id = -1) : to(to), cost(cost), id(id) {}\n};\n\ntemplate\
    \ <typename T, bool directed> struct Graph : vector<vector<Edge<T>>> {\n#define\
    \ n int(this->size())\n#define inf Edge<T>::INF\n    using vector<vector<Edge<T>>>::vector;\n\
    \n  private:\n    bool chmin(T &x, T y) const { return x > y ? (x = y, true) :\
    \ false; }\n\n  public:\n\n\n    void add(int s, int t, T w, int id = -1) {\n\
    \        (*this)[s].emplace_back(t, w, id);\n        if constexpr (directed ==\
    \ false) {\n            (*this)[t].emplace_back(s, w, id);\n        }\n    }\n\
    \n\n    vector<T> DFS(int s) const {\n        assert(0 <= s && s < n);\n     \
    \   vector<T> d(n, inf);\n        d[s] = 0;\n        queue<int> que;\n       \
    \ que.push(s);\n        while (que.empty() == false) {\n            int v = que.front();\n\
    \            que.pop();\n            for (auto e : (*this)[v]) {\n           \
    \     assert(e.cost == 1);\n                if (chmin(d[e.to], d[v] + e.cost))\
    \ {\n                    que.push(e.to);\n                }\n            }\n \
    \       }\n        return d;\n    }\n\n    vector<T> dijkstra(int s) const {\n\
    \        vector<T> d(n, inf);\n        d[s] = 0;\n        priority_queue<pair<T,\
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
    \ make_pair(vs, es);\n    }\n\n#undef n\n#undef inf\n};\n#line 2 \"Graph/scc.hpp\"\
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
    \u6210\u5206\u5206\u89E3)\n@docs doc/scc.md\n*/\n#line 4 \"verify/Graph_scc.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    Graph<int, true> g(n);\n\
    \    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g.add(u,\
    \ v, 0);\n    }\n\n    auto res = SCC::groups(g);\n    \n    cout << res.size()\
    \ << endl;\n\n    rep(i, 0, res.size()) {\n        cout << res[i].size() << \"\
    \ \";\n        for(auto v : res[i]) cout << v << \" \";\n        cout << endl;\n\
    \    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"../Utility/template.hpp\"\
    \n#include \"../Graph/scc.hpp\"\n\nint main() {\n    int n, m;\n    cin >> n >>\
    \ m;\n    Graph<int, true> g(n);\n    rep(i, 0, m) {\n        int u, v;\n    \
    \    cin >> u >> v;\n        g.add(u, v, 0);\n    }\n\n    auto res = SCC::groups(g);\n\
    \    \n    cout << res.size() << endl;\n\n    rep(i, 0, res.size()) {\n      \
    \  cout << res[i].size() << \" \";\n        for(auto v : res[i]) cout << v <<\
    \ \" \";\n        cout << endl;\n    }\n}\n\n"
  dependsOn:
  - Utility/template.hpp
  - Graph/scc.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: verify/Graph_scc.test.cpp
  requiredBy: []
  timestamp: '2025-01-11 19:57:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Graph_scc.test.cpp
layout: document
redirect_from:
- /verify/verify/Graph_scc.test.cpp
- /verify/verify/Graph_scc.test.cpp.html
title: verify/Graph_scc.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"verify/Graph_graph_dijkstra.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\n#line\
    \ 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n\
    #define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x)\
    \ begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec = vector<T>;\n\
    template <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x\
    \ = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1 &x, T2 y)\
    \ {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n    io_setup()\
    \ {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n  \
    \      cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Graph/graph.hpp\"\ntemplate\
    \ <typename T> struct Edge {\n    int to;\n    T cost;\n    int id;\n    static\
    \ constexpr T INF = numeric_limits<T>::max() / 2;\n    Edge(int to = 0, T cost\
    \ = 1, int id = -1) : to(to), cost(cost), id(id) {}\n};\n\ntemplate <typename\
    \ T, bool directed> struct Graph : vector<vector<Edge<T>>> {\n#define n int(this->size())\n\
    \    using vector<vector<Edge<T>>>::vector;\n    void add(int s, int t, T w =\
    \ 1, int id = -1) {\n        (*this)[s].emplace_back(t, w, id);\n        if constexpr\
    \ (directed == false) {\n            (*this)[t].emplace_back(s, w, id);\n    \
    \    }\n    }\n#undef n\n};\n\ntemplate <typename T> struct Tree : Graph<T, false>\
    \ {\n#define n int(this->size())\n    using Graph<T, false>::Graph;\n#undef n\n\
    };\n\nnamespace Graph_lib {\n\n#define inf Edge<T>::INF\ntemplate <typename T,\
    \ bool directed>\nvector<T> DFS(Graph<T, directed> const &g, int s) {\n    int\
    \ n = g.size();\n    assert(0 <= s && s < n);\n    vector<T> d(n, inf);\n    d[s]\
    \ = 0;\n    queue<int> que;\n    que.push(s);\n    while (que.empty() == false)\
    \ {\n        int v = que.front();\n        que.pop();\n        for (auto &e :\
    \ g[v]) {\n            assert(e.cost == 1);\n            if (chmin(d[e.to], d[v]\
    \ + e.cost)) {\n                que.push(e.to);\n            }\n        }\n  \
    \  }\n    return d;\n}\n\ntemplate <typename T, bool directed>\nvector<T> dijkstra(Graph<T,\
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
    \ es);\n}\n\n// ret[v] := v\u3092\u542B\u3080\u9023\u7D50\u6210\u5206\u304C\n\
    //  -1 : \u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u3044  0 : \u8272\u5857\u3063\
    \u305F\u30890  1 : \u8272\u5857\u3063\u305F\u30891\n// \u3000\u8272\u5857\u308A\
    \u306F0\u304B\u3089\u59CB\u3081\u308B\ntemplate <typename T, bool directed>\n\
    vector<int> bipartite_check(Graph<T, directed> const &g) {\n    int n = g.size();\n\
    \    vector<int> col(n, -1);\n    vector<vector<int>> gs;\n\n    auto dfs = [&](auto\
    \ f, int v, int c, vector<int> &vs) -> void {\n        col[v] = c;\n        vs.push_back(v);\n\
    \        for (auto &e : g[v])\n            if (col[e.to] == -1) {\n          \
    \      f(f, e.to, c ^ 1, vs);\n            }\n    };\n\n    for (int i = 0; i\
    \ < n; i++) {\n        if (col[i] == -1) {\n            vector<int> vs;\n    \
    \        dfs(dfs, i, 0, vs);\n            gs.push_back(vs);\n        }\n    }\n\
    \n    for (auto &vs : gs) {\n        bool ng = false;\n        for (auto v : vs)\
    \ {\n            for (auto &e : g[v]) {\n                if (col[v] == col[e.to])\
    \ {\n                    ng = true;\n                }\n            }\n      \
    \  }\n        if (ng) {\n            for (auto v : vs) col[v] = -1;\n        }\n\
    \    }\n\n    return col;\n}\n\n#undef inf\n};  // namespace Graph_lib\n\nnamespace\
    \ Tree_lib {\n#define inf Edge<T>::INF\ntemplate <typename T> vector<T> dist(Tree<T>\
    \ const &tr, int s) {\n    int n = tr.size();\n    vector<T> res(n, inf);\n  \
    \  res[s] = 0;\n    queue<int> que;\n    que.push(s);\n    while (!que.empty())\
    \ {\n        int v = que.front();\n        que.pop();\n        for (auto &e :\
    \ tr[v])\n            if (chmin(res[e.to], res[v] + e.cost)) {\n             \
    \   que.push(e.to);\n            }\n    }\n    return res;\n}\n\ntemplate <typename\
    \ T> vector<int> path(Tree<T> const &tr, int s, int t) {\n    vector<int> res;\n\
    \    auto dfs = [&](auto f, int v, int p = -1) -> bool {\n        if (v == t)\
    \ {\n            return true;\n        }\n\n        for (auto &e : tr[v])\n  \
    \          if (e.to != p) {\n                if (f(f, e.to, v)) {\n          \
    \          res.push_back(e.to);\n                    return true;\n          \
    \      }\n            }\n        return false;\n    };\n\n    dfs(dfs, s);\n \
    \   res.push_back(s);\n    reverse(res.begin(), res.end());\n    return res;\n\
    }\n\n// diam() ... (\u76F4\u5F84, (\u76F4\u5F84\u306E\u7AEFu, \u76F4\u5F84\u306E\
    \u7AEFv))\ntemplate <typename T> pair<T, pair<int, int>> diam(Tree<T> const &tr)\
    \ {\n    int n = tr.size();\n    int u, v;\n    T d, tmp;\n    vector<T> ds =\
    \ dist(tr, 0);\n    tmp = ds[0], u = 0;\n    for (int i = 1; i < n; i++) {\n \
    \       if (chmax(tmp, ds[i])) u = i;\n    }\n\n    vector<T> ds2 = dist(tr, u);\n\
    \    d = ds2[0], v = 0;\n    for (int i = 1; i < n; i++) {\n        if (chmax(d,\
    \ ds2[i])) v = i;\n    }\n    pair<T, pair<int, int>> res;\n    res.first = d;\n\
    \    res.second.first = u;\n    res.second.second = v;\n    return res;\n}\n\n\
    // {\u76F4\u5F840, \u76F4\u5F841 or -1}\ntemplate <typename T> pair<int, int>\
    \ center(Tree<T> const &tr) {\n    auto [d, p] = diam(tr);\n    auto ph = path(tr,\
    \ p.first, p.second);\n    int m = (ph.size() + 1) / 2 - 1;\n    if (ph.size()\
    \ % 2 == 1)\n        return {ph[m], -1};\n    else\n        return {ph[m], ph[m\
    \ + 1]};\n}\n\ntemplate <typename T>\nvector<pair<int, int>> maximum_matching(Tree<T>\
    \ const &tr) {\n    vector<pair<int, int>> ret;\n    auto dfs = [&](auto f, int\
    \ v, int p) -> bool {\n        bool used = false;\n        for (auto &e : tr[v])\n\
    \            if (e.to != p) {\n                bool used_to = f(f, e.to, v);\n\
    \                if (used_to == false && used == false) {\n                  \
    \  used = true;\n                    ret.emplace_back(v, e.to);\n            \
    \    }\n            }\n        return used;\n    };\n\n    dfs(dfs, 0, -1);\n\n\
    \    return ret;\n}\n\n//{\u5B58\u5728\u3059\u308B\u304B\u3001\u9802\u70B9\u306E\
    \u30DA\u30A2\u306E\u96C6\u5408}\ntemplate <typename T>\npair<bool, vector<pair<int,\
    \ int>>> perfect_matching(Tree<T> const &tr) {\n    if (tr.size() % 2 == 1) return\
    \ {false, {}};\n\n    auto match = maximum_matching(tr);\n    if (match.size()\
    \ * 2 == tr.size()) {\n        return {true, match};\n    } else {\n        return\
    \ {false, match};\n    }\n}\n#undef inf\n};  // namespace Tree_lib\n#line 4 \"\
    verify/Graph_graph_dijkstra.test.cpp\"\nint main() {\n    ll n, m, r;\n    cin\
    \ >> n >> m >> r;\n    Graph<ll, true> g(n);\n    rep(i, 0, m) {\n        ll s,\
    \ t, w;\n        cin >> s >> t >> w;\n        g.add(s, t, w);\n    }\n\n    auto\
    \ d = Graph_lib::dijkstra(g, r);\n    for (int i = 0; i < n; i++) {\n        if\
    \ (d[i] == Edge<ll>::INF) {\n            cout << \"INF\" << endl;\n        } else\
    \ {\n            cout << d[i] << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Graph/graph.hpp\"\nint main()\
    \ {\n    ll n, m, r;\n    cin >> n >> m >> r;\n    Graph<ll, true> g(n);\n   \
    \ rep(i, 0, m) {\n        ll s, t, w;\n        cin >> s >> t >> w;\n        g.add(s,\
    \ t, w);\n    }\n\n    auto d = Graph_lib::dijkstra(g, r);\n    for (int i = 0;\
    \ i < n; i++) {\n        if (d[i] == Edge<ll>::INF) {\n            cout << \"\
    INF\" << endl;\n        } else {\n            cout << d[i] << endl;\n        }\n\
    \    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: verify/Graph_graph_dijkstra.test.cpp
  requiredBy: []
  timestamp: '2025-04-03 05:20:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Graph_graph_dijkstra.test.cpp
layout: document
redirect_from:
- /verify/verify/Graph_graph_dijkstra.test.cpp
- /verify/verify/Graph_graph_dijkstra.test.cpp.html
title: verify/Graph_graph_dijkstra.test.cpp
---

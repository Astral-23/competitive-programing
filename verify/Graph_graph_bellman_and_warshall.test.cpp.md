---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"verify/Graph_graph_bellman_and_warshall.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
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
    \    }\n};\n#line 4 \"verify/Graph_graph_bellman_and_warshall.test.cpp\"\nint\
    \ main() {\n    ll n, m;\n    cin >> n >> m;\n    Graph<ll, true> g(n);\n    rep(i,\
    \ 0, m) {\n        ll s, t, w;\n        cin >> s >> t >> w;\n        g.add(s,\
    \ t, w);\n    }\n\n    if (g.has_negative_cycle()) {\n        cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n        return 0;\n    }\n\n    auto d = g.warshall();\n \
    \   for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n   \
    \         if (d[i][j] == Edge<ll>::inf) {\n                cout << \"INF\";\n\
    \            } else {\n                cout << d[i][j];\n            }\n     \
    \       if (j != n - 1) cout << \" \";\n        }\n        cout << endl;\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Graph/graph.hpp\"\nint main()\
    \ {\n    ll n, m;\n    cin >> n >> m;\n    Graph<ll, true> g(n);\n    rep(i, 0,\
    \ m) {\n        ll s, t, w;\n        cin >> s >> t >> w;\n        g.add(s, t,\
    \ w);\n    }\n\n    if (g.has_negative_cycle()) {\n        cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n        return 0;\n    }\n\n    auto d = g.warshall();\n \
    \   for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n   \
    \         if (d[i][j] == Edge<ll>::inf) {\n                cout << \"INF\";\n\
    \            } else {\n                cout << d[i][j];\n            }\n     \
    \       if (j != n - 1) cout << \" \";\n        }\n        cout << endl;\n   \
    \ }\n}"
  dependsOn:
  - Utility/template.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: verify/Graph_graph_bellman_and_warshall.test.cpp
  requiredBy: []
  timestamp: '2025-01-11 19:00:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Graph_graph_bellman_and_warshall.test.cpp
layout: document
redirect_from:
- /verify/verify/Graph_graph_bellman_and_warshall.test.cpp
- /verify/verify/Graph_graph_bellman_and_warshall.test.cpp.html
title: verify/Graph_graph_bellman_and_warshall.test.cpp
---

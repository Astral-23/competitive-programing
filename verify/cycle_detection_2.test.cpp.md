---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/cycle_detection.hpp
    title: cycle_detection
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection_undirected
    links:
    - https://judge.yosupo.jp/problem/cycle_detection_undirected
  bundledCode: "#line 1 \"verify/cycle_detection_2.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cycle_detection_undirected\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\n*/\n#line 1 \"Graph/cycle_detection.hpp\"\ntemplate <bool directed> struct\
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
    @brief cycle_detection\n@docs doc/cycle_detection.md\n*/\n#line 4 \"verify/cycle_detection_2.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    cycle_detection<false>\
    \ cyc(n);\n    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n   \
    \     cyc.add_edge(u, v);\n    }\n    auto [vs, es] = cyc.run();\n    if (vs.empty())\
    \ {\n        cout << -1 << endl;\n    } else {\n        cout << vs.size() << endl;\n\
    \        for(int v : vs) cout << v << \" \";\n        cout << endl;\n        for(int\
    \ e : es) cout << e << \" \";\n        cout << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Graph/cycle_detection.hpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    cycle_detection<false>\
    \ cyc(n);\n    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n   \
    \     cyc.add_edge(u, v);\n    }\n    auto [vs, es] = cyc.run();\n    if (vs.empty())\
    \ {\n        cout << -1 << endl;\n    } else {\n        cout << vs.size() << endl;\n\
    \        for(int v : vs) cout << v << \" \";\n        cout << endl;\n        for(int\
    \ e : es) cout << e << \" \";\n        cout << endl;\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Graph/cycle_detection.hpp
  isVerificationFile: true
  path: verify/cycle_detection_2.test.cpp
  requiredBy: []
  timestamp: '2024-09-24 03:56:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/cycle_detection_2.test.cpp
layout: document
redirect_from:
- /verify/verify/cycle_detection_2.test.cpp
- /verify/verify/cycle_detection_2.test.cpp.html
title: verify/cycle_detection_2.test.cpp
---

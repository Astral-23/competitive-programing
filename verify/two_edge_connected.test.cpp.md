---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/lowlink.hpp
    title: lowlink
  - icon: ':heavy_check_mark:'
    path: Graph/two_edge_connected.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
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
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"verify/two_edge_connected.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/two_edge_connected_components\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n*/\n#line 1 \"Graph/lowlink.hpp\"\nstruct lowlink {\n    using vi = vec<int>;\n\
    \    using vvi = vec<vi>;\n    using pii = pair<int, int>;\n\n    int n;\n   \
    \ vvi tr;  // dfs\u6728\u306B\u4F7F\u308F\u308C\u308B\u8FBA\u306E\u307F \u4E0A\
    \u304B\u3089\u4E0B\n    vvi aux;  // dfs\u6728\u306B\u4F7F\u308F\u308C\u306A\u3044\
    \u8FBA\u306E\u307F  \u4E0B\u304B\u3089\u4E0A \u81EA\u5DF1\u8FBA\u3082\u30B3\u30B3\
    \n    vi low, in, par;\n    vec<pii> bridges;\n    vec<int> joints;\n    vec<bool>\
    \ inner_is_joint;\n    vec<int> self_edge_cnt;\n    \n    lowlink(const vvi &g)\n\
    \        : n(g.size()),\n          tr(n),\n          aux(n),\n          low(n,\
    \ 1001001001),\n          in(n, -1),\n          par(n, -1),\n          inner_is_joint(n,\
    \ false),\n          self_edge_cnt(n, 0) {\n        int t = 0;\n        int r\
    \ = 0;\n        auto dfs = [&](auto f, int v, int p) -> void {\n            par[v]\
    \ = p;\n            in[v] = low[v] = t++;\n            bool duplication = false;\n\
    \            for (int to : g[v]) {\n                if (in[to] == -1) {\n    \
    \                tr[v].push_back(to);\n                    f(f, to, v);\n    \
    \            } else {\n                    if (to != p) {\n                  \
    \      if (in[to] < in[v])\n                            aux[v].push_back(to);\n\
    \                        else if (to == v) {\n                            if ((++self_edge_cnt[v])\
    \ & 1) aux[v].push_back(to);\n                        }\n                    \
    \    chmin(low[v], in[to]);\n                    } else if (duplication == false)\n\
    \                        duplication = true;\n                    else {\n   \
    \                     aux[v].push_back(to);\n                        chmin(low[v],\
    \ in[to]);\n                    }\n                }\n            }\n\n      \
    \      for (int to : tr[v]) {\n                chmin(low[v], low[to]);\n     \
    \       }\n            // \u90E8\u5206\u6728\u306B\u3064\u3044\u3066\u3001low/in\u304C\
    \u6C42\u307E\u3063\u305F\n            bool isjoint = false;\n            for (int\
    \ to : tr[v]) {\n                if (low[to] > in[v]) bridges.emplace_back(v,\
    \ to);\n                if (low[to] >= in[v]) isjoint = true;\n            }\n\
    \n            if (v != r && isjoint)\n                joints.push_back(v), inner_is_joint[v]\
    \ = true;\n            else if (v == r) {\n                if (tr[v].size() >\
    \ 1)\n                    joints.push_back(v), inner_is_joint[v] = true;\n   \
    \         }\n        };\n\n        rep(i, 0, n) if (in[i] == -1) {\n         \
    \   r = i;\n            dfs(dfs, i, -1);\n        }\n    }\n\n    bool is_bridge(int\
    \ u, int v) {\n        if (in[u] > in[v]) swap(u, v);\n        if (par[v] != u)\
    \ return false;\n        if (low[v] > in[u])\n            return true;\n     \
    \   else\n            return false;\n    }\n\n    bool is_joint(int v) { return\
    \ inner_is_joint[v]; }\n};\n\n/*\n@brief lowlink\n@docs doc/lowlink.md\n*/\n#line\
    \ 1 \"Graph/two_edge_connected.hpp\"\nstruct two_edge_connected_components : lowlink\
    \ {\n    using lowlink::aux;\n    using lowlink::in;\n    using lowlink::low;\n\
    \    using lowlink::n;\n    using lowlink::tr;\n    int sz;  // \u6210\u5206\u306E\
    \u500B\u6570\n    vi rev;  // \u9802\u70B9i\u304C\u5C5E\u3059\u308B\u6210\u5206\
    \u306E\u756A\u53F7\n    vvi g;   // \u7E2E\u7D04\u30B0\u30E9\u30D5\n    two_edge_connected_components(const\
    \ vvi &G)\n        : lowlink(G), sz(0), rev(n, -1), g(n) {\n        auto dfs =\
    \ [&](auto f, int v, int this_id) -> void {\n            rev[v] = this_id;\n \
    \           for (int to : G[v])\n                if (rev[to] == -1) {\n      \
    \              if (is_bridge(v, to)) {\n                        sz++;\n      \
    \                  g[this_id].push_back(sz - 1);\n                        g[sz\
    \ - 1].push_back(this_id);\n                        f(f, to, sz - 1);\n      \
    \              } else {\n                        f(f, to, this_id);\n        \
    \            }\n                }\n        };\n\n        rep(i, 0, n) if (rev[i]\
    \ == -1) {\n            sz++;\n            dfs(dfs, i, sz - 1);\n        }\n \
    \       g.resize(sz);\n    }\n\n    int operator()(int v) const { return rev[v];\
    \ }\n};\n/*\n@brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/\n\
    #line 5 \"verify/two_edge_connected.test.cpp\"\n\nint main() {\n    int n, m;\n\
    \    cin >> n >> m;\n    vec<vec<int>> g(n);\n    rep(i, 0, m) {\n        int\
    \ a, b;\n        cin >> a >> b;\n        g[a].push_back(b);\n        g[b].push_back(a);\n\
    \    }\n\n    two_edge_connected_components two(g);\n    vec<vec<int>> vs(two.sz);\n\
    \    rep(i, 0, n) vs[two(i)].push_back(i);\n\n    cout << two.sz << '\\n';\n\n\
    \    rep(i, 0, two.sz) {\n        cout << vs[i].size() << \" \";\n        for\
    \ (int v : vs[i]) cout << v << \" \";\n        cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Graph/lowlink.hpp\"\n#include\
    \ \"../Graph/two_edge_connected.hpp\"\n\nint main() {\n    int n, m;\n    cin\
    \ >> n >> m;\n    vec<vec<int>> g(n);\n    rep(i, 0, m) {\n        int a, b;\n\
    \        cin >> a >> b;\n        g[a].push_back(b);\n        g[b].push_back(a);\n\
    \    }\n\n    two_edge_connected_components two(g);\n    vec<vec<int>> vs(two.sz);\n\
    \    rep(i, 0, n) vs[two(i)].push_back(i);\n\n    cout << two.sz << '\\n';\n\n\
    \    rep(i, 0, two.sz) {\n        cout << vs[i].size() << \" \";\n        for\
    \ (int v : vs[i]) cout << v << \" \";\n        cout << '\\n';\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Graph/lowlink.hpp
  - Graph/two_edge_connected.hpp
  isVerificationFile: true
  path: verify/two_edge_connected.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/two_edge_connected.test.cpp
layout: document
redirect_from:
- /verify/verify/two_edge_connected.test.cpp
- /verify/verify/two_edge_connected.test.cpp.html
title: verify/two_edge_connected.test.cpp
---

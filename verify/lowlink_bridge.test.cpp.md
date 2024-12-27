---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/lowlink.hpp
    title: lowlink
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"verify/lowlink_bridge.test.cpp\"\n#define PROBLEM \\\n \
    \   \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\n#line\
    \ 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n\
    #define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x)\
    \ begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec = vector<T>;\n\
    template <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x\
    \ = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1 &x, T2 y)\
    \ {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n    io_setup()\
    \ {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n  \
    \      cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Graph/lowlink.hpp\"\nstruct\
    \ lowlink {\n    using vi = vec<int>;\n    using vvi = vec<vi>;\n    using pii\
    \ = pair<int, int>;\n\n    int n;\n    vvi tr;  // dfs\u6728\u306B\u4F7F\u308F\
    \u308C\u308B\u8FBA\u306E\u307F \u4E0A\u304B\u3089\u4E0B\n    vvi aux;  // dfs\u6728\
    \u306B\u4F7F\u308F\u308C\u306A\u3044\u8FBA\u306E\u307F  \u4E0B\u304B\u3089\u4E0A\
    \ \u81EA\u5DF1\u8FBA\u3082\u30B3\u30B3\n    vi low, in, par;\n    vec<pii> bridges;\n\
    \    vec<int> joints;\n    vec<bool> inner_is_joint;\n    vec<int> self_edge_cnt;\n\
    \    \n    lowlink(const vvi &g)\n        : n(g.size()),\n          tr(n),\n \
    \         aux(n),\n          low(n, 1001001001),\n          in(n, -1),\n     \
    \     par(n, -1),\n          inner_is_joint(n, false),\n          self_edge_cnt(n,\
    \ 0) {\n        int t = 0;\n        int r = 0;\n        auto dfs = [&](auto f,\
    \ int v, int p) -> void {\n            par[v] = p;\n            in[v] = low[v]\
    \ = t++;\n            bool duplication = false;\n            for (int to : g[v])\
    \ {\n                if (in[to] == -1) {\n                    tr[v].push_back(to);\n\
    \                    f(f, to, v);\n                } else {\n                \
    \    if (to != p) {\n                        if (in[to] < in[v])\n           \
    \                 aux[v].push_back(to);\n                        else if (to ==\
    \ v) {\n                            if ((++self_edge_cnt[v]) & 1) aux[v].push_back(to);\n\
    \                        }\n                        chmin(low[v], in[to]);\n \
    \                   } else if (duplication == false)\n                       \
    \ duplication = true;\n                    else {\n                        aux[v].push_back(to);\n\
    \                        chmin(low[v], in[to]);\n                    }\n     \
    \           }\n            }\n\n            for (int to : tr[v]) {\n         \
    \       chmin(low[v], low[to]);\n            }\n            // \u90E8\u5206\u6728\
    \u306B\u3064\u3044\u3066\u3001low/in\u304C\u6C42\u307E\u3063\u305F\n         \
    \   bool isjoint = false;\n            for (int to : tr[v]) {\n              \
    \  if (low[to] > in[v]) bridges.emplace_back(v, to);\n                if (low[to]\
    \ >= in[v]) isjoint = true;\n            }\n\n            if (v != r && isjoint)\n\
    \                joints.push_back(v), inner_is_joint[v] = true;\n            else\
    \ if (v == r) {\n                if (tr[v].size() > 1)\n                    joints.push_back(v),\
    \ inner_is_joint[v] = true;\n            }\n        };\n\n        rep(i, 0, n)\
    \ if (in[i] == -1) {\n            r = i;\n            dfs(dfs, i, -1);\n     \
    \   }\n    }\n\n    bool is_bridge(int u, int v) {\n        if (in[u] > in[v])\
    \ swap(u, v);\n        if (par[v] != u) return false;\n        if (low[v] > in[u])\n\
    \            return true;\n        else\n            return false;\n    }\n\n\
    \    bool is_joint(int v) { return inner_is_joint[v]; }\n};\n\n/*\n@brief lowlink\n\
    @docs doc/lowlink.md\n*/\n#line 5 \"verify/lowlink_bridge.test.cpp\"\n\nint main()\
    \ {\n    int v, e;\n    cin >> v >> e;\n    vec<vec<int>> g(v);\n    rep(i, 0,\
    \ e) {\n        int s, t;\n        cin >> s >> t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n\n    lowlink llink(g);\n    set<pair<int,\
    \ int>> bs;\n    auto ans = llink.bridges;\n    for (auto &[l, r] : ans)\n   \
    \     if (l > r) swap(l, r);\n    for (auto [l, r] : ans) bs.insert({l, r});\n\
    \n    rep(i, 0, v) {\n        for (int j : g[i]) {\n            if (llink.is_bridge(i,\
    \ j))\n                assert(bs.count({minmax<int>(i, j)}));\n            else\n\
    \                assert(!(bs.count(minmax<int>(i, j))));\n        }\n    }\n \
    \   sort(all(ans));\n\n    for (auto [l, r] : ans) cout << l << \" \" << r <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Graph/lowlink.hpp\"\n\n\
    int main() {\n    int v, e;\n    cin >> v >> e;\n    vec<vec<int>> g(v);\n   \
    \ rep(i, 0, e) {\n        int s, t;\n        cin >> s >> t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n\n    lowlink llink(g);\n    set<pair<int,\
    \ int>> bs;\n    auto ans = llink.bridges;\n    for (auto &[l, r] : ans)\n   \
    \     if (l > r) swap(l, r);\n    for (auto [l, r] : ans) bs.insert({l, r});\n\
    \n    rep(i, 0, v) {\n        for (int j : g[i]) {\n            if (llink.is_bridge(i,\
    \ j))\n                assert(bs.count({minmax<int>(i, j)}));\n            else\n\
    \                assert(!(bs.count(minmax<int>(i, j))));\n        }\n    }\n \
    \   sort(all(ans));\n\n    for (auto [l, r] : ans) cout << l << \" \" << r <<\
    \ '\\n';\n}"
  dependsOn:
  - Utility/template.hpp
  - Graph/lowlink.hpp
  isVerificationFile: true
  path: verify/lowlink_bridge.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lowlink_bridge.test.cpp
layout: document
redirect_from:
- /verify/verify/lowlink_bridge.test.cpp
- /verify/verify/lowlink_bridge.test.cpp.html
title: verify/lowlink_bridge.test.cpp
---

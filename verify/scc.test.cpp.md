---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 1 \"verify/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Graph/scc.hpp\"\nnamespace\
    \ SCC {\nvec<int> ids(const vec<vec<int>> &g) {\n    using vi = vec<int>;\n  \
    \  using vvi = vec<vi>;\n\n    int n = g.size();\n    vvi rg(n);\n    vi vs, cmp(n,\
    \ -1);\n    vec<bool> seen(n, false), nees(n, false);\n\n    rep(i, 0, n) for\
    \ (int to : g[i]) rg[to].push_back(i);\n\n    auto dfs = [&](auto f, int v) ->\
    \ void {\n        seen[v] = true;\n        for (auto to : g[v])\n            if\
    \ (!seen[to]) f(f, to);\n        vs.push_back(v);\n        return;\n    };\n\n\
    \    int k = 0;\n\n    auto sfd = [&](auto f, int v) -> void {\n        nees[v]\
    \ = true;\n        cmp[v] = k;\n        for (int to : rg[v])\n            if (!nees[to])\
    \ f(f, to);\n        return;\n    };\n\n    rep(i, 0, n) if (!seen[i]) dfs(dfs,\
    \ i);\n    rrep(i, 0, vs.size()) if (!nees[vs[i]]) sfd(sfd, vs[i]), k++;\n   \
    \ return cmp;\n}\n\nvec<vec<int>> groups(const vec<vec<int>> &g) {\n    int n\
    \ = g.size();\n    vec<int> id = ids(g);\n\n    vec<vec<int>> gs(n);\n    rep(i,\
    \ 0, n) gs[id[i]].push_back(i);\n    while (gs.empty() == false && gs.back().empty()\
    \ == true) {\n        gs.pop_back();\n    }\n    return gs;\n}\n\nvec<vec<int>>\
    \ graph(const vec<vec<int>> &g) {\n    vec<int> id = ids(g);\n    int n = 0;\n\
    \    rep(i, 0, g.size()) chmax(n, id[i] + 1);\n\n    vec<vec<int>> ng(n);\n  \
    \  rep(i, 0, g.size()) for (int to : g[i]) {\n        if (id[i] == id[to]) continue;\n\
    \        ng[id[i]].push_back(id[to]);\n    }\n    return ng;\n}\n\nvec<vec<int>>\
    \ graph_rev(const vec<vec<int>> &g) {\n    auto ser = graph(g);\n    int n = ser.size();\n\
    \    vec<vec<int>> res(n);\n    rep(i, 0, n) for(int to : ser[i]) {\n        res[to].push_back(i);\n\
    \    }\n    return res;\n}\n\n}  // namespace SCC\n\n/*\n@brief scc(\u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3)\n@docs doc/scc.md\n*/\n#line 4 \"verify/scc.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> g(n);\n\
    \    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \    }\n\n    auto res = SCC::groups(g);\n    \n    cout << res.size() << endl;\n\
    \n    rep(i, 0, res.size()) {\n        cout << res[i].size() << \" \";\n     \
    \   for(auto v : res[i]) cout << v << \" \";\n        cout << endl;\n    }\n}\n\
    \n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"../Utility/template.hpp\"\
    \n#include \"../Graph/scc.hpp\"\n\nint main() {\n    int n, m;\n    cin >> n >>\
    \ m;\n    vec<vec<int>> g(n);\n    rep(i, 0, m) {\n        int u, v;\n       \
    \ cin >> u >> v;\n        g[u].push_back(v);\n    }\n\n    auto res = SCC::groups(g);\n\
    \    \n    cout << res.size() << endl;\n\n    rep(i, 0, res.size()) {\n      \
    \  cout << res[i].size() << \" \";\n        for(auto v : res[i]) cout << v <<\
    \ \" \";\n        cout << endl;\n    }\n}\n\n"
  dependsOn:
  - Utility/template.hpp
  - Graph/scc.hpp
  isVerificationFile: true
  path: verify/scc.test.cpp
  requiredBy: []
  timestamp: '2024-08-20 17:56:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/scc.test.cpp
- /verify/verify/scc.test.cpp.html
title: verify/scc.test.cpp
---

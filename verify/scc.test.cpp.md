---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n\n#define TT template<typename\
    \ T>\nTT using vec = vector<T>;\ntemplate<class T1, class T2> bool chmin(T1 &x,\
    \ T2 y) { return x > y ? (x = y, true) : false; }\ntemplate<class T1, class T2>\
    \ bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }\n\nstruct\
    \ io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n       \
    \ std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n    }\n\
    } io_setup;\n\n/*\n@brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"\
    Algorithm/scc.hpp\"\nvec<int> SCC (vec<vec<int>> g) {\n    using vi = vec<int>;\n\
    \    using vvi = vec<vi>;\n\n    int n = g.size();\n    vvi rg(n);\n    vi vs,\
    \ cmp(n, -1);\n    vec<bool> seen(n, false), nees(n, false);\n\n    rep(i, 0,\
    \ n) for(int to : g[i]) rg[to].push_back(i);\n\n    auto dfs = [&](auto f, int\
    \ v) -> void {\n        seen[v] = true;\n        for(auto to : g[v]) if(!seen[to])\
    \ f(f, to);\n        vs.push_back(v);\n        return;\n    };\n\n    int k =\
    \ 0;\n\n    auto sfd = [&](auto f, int v) -> void {\n        nees[v] = true;\n\
    \        cmp[v] = k;\n        for(int to : rg[v]) if(!nees[to]) f(f, to);\n  \
    \      return;\n    };\n\n    \n    rep(i, 0, n) if(!seen[i]) dfs(dfs, i);\n \
    \   rrep(i, 0, vs.size()) if(!nees[vs[i]]) sfd(sfd, vs[i]), k++;\n    return cmp;\n\
    }\n\n/*\n@brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n@docs doc/scc.md\n\
    */\n#line 4 \"verify/scc.test.cpp\"\n\nint main() {\n    int n, m;\n    cin >>\
    \ n >> m;\n    vec<vec<int>> g(n);\n    rep(i, 0, m) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        g[u].push_back(v);\n    }\n\n    auto res = SCC(g);\n\
    \    vec<vec<int>> vs(n);\n    rep(i, 0, n) vs[res[i]].push_back(i);\n    \n \
    \   int c = 0;\n    rep(i, 0, n) if(vs[i].size() > 0)c++;\n    cout << c << endl;\n\
    \n     \n\n    rep(i, 0, n) if(vs[i].size() > 0) {\n        cout << vs[i].size()\
    \ << \" \";\n        for(auto v : vs[i]) cout << v << \" \";\n        cout <<\
    \ endl;\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"../Utility/template.hpp\"\
    \n#include \"../Algorithm/scc.hpp\"\n\nint main() {\n    int n, m;\n    cin >>\
    \ n >> m;\n    vec<vec<int>> g(n);\n    rep(i, 0, m) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        g[u].push_back(v);\n    }\n\n    auto res = SCC(g);\n\
    \    vec<vec<int>> vs(n);\n    rep(i, 0, n) vs[res[i]].push_back(i);\n    \n \
    \   int c = 0;\n    rep(i, 0, n) if(vs[i].size() > 0)c++;\n    cout << c << endl;\n\
    \n     \n\n    rep(i, 0, n) if(vs[i].size() > 0) {\n        cout << vs[i].size()\
    \ << \" \";\n        for(auto v : vs[i]) cout << v << \" \";\n        cout <<\
    \ endl;\n    }\n}\n\n"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/scc.hpp
  isVerificationFile: true
  path: verify/scc.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/scc.test.cpp
- /verify/verify/scc.test.cpp.html
title: verify/scc.test.cpp
---

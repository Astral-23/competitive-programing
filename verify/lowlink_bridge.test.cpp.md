---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/lowlink.hpp
    title: lowlink
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"verify/lowlink_bridge.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \ \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"Algorithm/lowlink.hpp\"\nstruct lowlink {\n\
    \    using vi = vec<int>;\n    using vvi = vec<vi>;\n    using pii = pair<int,\
    \ int>;\n    \n    int n;\n    vvi tr;\n    vi low, in;\n    vec<pii> bridges;\n\
    \    vec<int> joints;\n\n    lowlink(vvi g) : n(g.size()) {\n        low = vi(n,\
    \ 1001001001);\n        in = vi(n, -1);\n        tr.resize(n);\n    \n       \
    \ \n        int t = 0;\n        int r = 0;\n        auto dfs = [&](auto f, int\
    \ v, int p) -> void {\n            in[v] = low[v] = t++;\n            bool duplication\
    \ = false;\n            for(int to: g[v]) {\n                if(in[to] == -1)\
    \ {\n                    tr[v].push_back(to);\n                    f(f, to, v);\n\
    \                }\n                else {\n                    if(to != p) chmin(low[v],\
    \ in[to]);\n                    else if(duplication == false) duplication = true;\n\
    \                    else {\n                        chmin(low[v], in[to]);\n\
    \                    }\n                }\n            }\n\n            for(int\
    \ to : tr[v]) {\n                chmin(low[v], low[to]);\n            }\n    \
    \        //\u90E8\u5206\u6728\u306B\u3064\u3044\u3066\u3001low/in\u304C\u6C42\u307E\
    \u3063\u305F\n            bool isjoint = false;\n            for(int to : tr[v])\
    \ {\n                if(low[to] > in[v]) bridges.emplace_back(v, to);\n      \
    \          if(low[to] >= in[v]) isjoint = true;\n            }\n\n           \
    \ if(v != r && isjoint) joints.push_back(v);\n            else if(v == r) {\n\
    \                if(tr[v].size() > 1) joints.push_back(v);\n            }\n  \
    \      };\n\n        rep(i, 0, n) if(in[i] == -1) {\n            r = i;\n    \
    \        dfs(dfs, i, -1);\n        }\n    }\n\n};\n\n/*\n@brief lowlink\n@docs\
    \ doc/lowlink.md\n*/\n#line 4 \"verify/lowlink_bridge.test.cpp\"\n\n\nint main()\
    \ {\n    int v, e;\n    cin >> v >> e;\n    vec<vec<int>> g(v);\n    rep(i, 0,\
    \ e) {\n        int s, t;\n        cin >> s >> t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n\n    lowlink llink(g);\n    auto ans = llink.bridges;\n\
    \    for(auto& [l, r] : ans) if(l > r) swap(l, r);\n    sort(all(ans));\n    for(auto\
    \ [l, r] : ans) cout << l << \" \" << r << '\\n';\n\n\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \ \n#include \"../Utility/template.hpp\"\n#include \"../Algorithm/lowlink.hpp\"\
    \n\n\nint main() {\n    int v, e;\n    cin >> v >> e;\n    vec<vec<int>> g(v);\n\
    \    rep(i, 0, e) {\n        int s, t;\n        cin >> s >> t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n\n    lowlink llink(g);\n    auto ans = llink.bridges;\n\
    \    for(auto& [l, r] : ans) if(l > r) swap(l, r);\n    sort(all(ans));\n    for(auto\
    \ [l, r] : ans) cout << l << \" \" << r << '\\n';\n\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/lowlink.hpp
  isVerificationFile: true
  path: verify/lowlink_bridge.test.cpp
  requiredBy: []
  timestamp: '2024-07-09 04:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lowlink_bridge.test.cpp
layout: document
redirect_from:
- /verify/verify/lowlink_bridge.test.cpp
- /verify/verify/lowlink_bridge.test.cpp.html
title: verify/lowlink_bridge.test.cpp
---

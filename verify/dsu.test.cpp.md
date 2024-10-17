---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/dsu.hpp
    title: dsu
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/dsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/dsu.hpp\"\n\
    struct dsu {\n    using vi = vector<int>;   \n    using vvi = vector<vector<int>>;\n\
    \    vi par, sz, es;\n    int cc;\n\n    dsu(int n) {\n        par = vi(n);\n\
    \        sz = vi(n, 1);\n        es = vi(n, 0);\n        cc = n;\n        iota(all(par),\
    \ 0);\n    }\n  \n    int leader(int u) {\n        if (par[u] != u) {\n      \
    \      return par[u] = leader(par[u]);\n        }    \n         return u;\n  \
    \  }\n    \n    bool same(int a, int b) {\n        return leader(a) == leader(b);\n\
    \    }\n    \n    bool merge(int a, int b) {\n        a = leader(a), b = leader(b);\n\
    \        if(sz[a] < sz[b]) swap(a, b);\n\n        if(a == b) {\n            ++es[a];\n\
    \            return false;\n        }\n        else {\n            cc--;\n   \
    \         par[b] = leader(a);\n            sz[a] += sz[b];\n            es[a]\
    \ += es[b] + 1;\n            return true;\n        }\n    }\n\n    //\u4EE5\u4E0B\
    \u3001\u5FC5\u8981\u306A\u7269\u3092\u66F8\u304F\n\n    int size(int u) {\n  \
    \      return sz[leader(u)];\n    }\n\n    \n    int componentcnt() {\n      \
    \  return cc;\n    }\n    \n    int edgecnt(int u) {\n        return es[leader(u)];\n\
    \    }\n\n    vvi groups() {\n        int n = par.size();\n        vvi ms(n);\n\
    \        rep(v, 0, n) {\n            ms[leader(v)].push_back(v);\n        }\n\n\
    \        vvi res;\n        rep(i, 0, n) if(ms[i].size() > 0) {\n            res.push_back(ms[i]);\n\
    \        }\n\n        return res;\n    }\n\n};\n\n/*\n@brief dsu\n@docs doc/dsu.md\n\
    */\n#line 4 \"verify/dsu.test.cpp\"\n\nint main() {\n    int N, Q;\n    cin >>\
    \ N >> Q;\n    dsu d(N);\n    while(Q--) {\n        int t, u, v;\n        cin\
    \ >> t >> u >> v;\n        if(t==0) {\n            d.merge(u, v);\n        }\n\
    \        else {\n            if(d.same(u, v)) cout << 1 << '\\n';\n          \
    \  else cout << 0 << '\\n';\n        }\n\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../Utility/template.hpp\"\n#include \"../Datastructure/dsu.hpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    dsu d(N);\n    while(Q--) {\n    \
    \    int t, u, v;\n        cin >> t >> u >> v;\n        if(t==0) {\n         \
    \   d.merge(u, v);\n        }\n        else {\n            if(d.same(u, v)) cout\
    \ << 1 << '\\n';\n            else cout << 0 << '\\n';\n        }\n\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/dsu.hpp
  isVerificationFile: true
  path: verify/dsu.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dsu.test.cpp
layout: document
redirect_from:
- /verify/verify/dsu.test.cpp
- /verify/verify/dsu.test.cpp.html
title: verify/dsu.test.cpp
---

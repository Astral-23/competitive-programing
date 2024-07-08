---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Datastructure/potential_dsu.hpp
    title: potential dsu
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
  bundledCode: "#line 1 \"verify/potential_dsu.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/potential_dsu.hpp\"\nTT struct\
    \ potential_dsu {\n    using vi = vec<int>;\n    using vvi = vec<vi>;\n    vi\
    \ par, sz, es;\n    vec<T> h;\n    int cc;\n    int root;\n\n    potential_dsu(int\
    \ n, int ROOT) : root(ROOT) {\n        par = vi(n);\n        sz = vi(n, 1);\n\
    \        es = vi(n, 0);\n        cc = n;\n        iota(all(par), 0);\n\n     \
    \   h = vec<T>(n, 0);\n    }\n\n    int leader(int u) {\n        if(par[u] !=\
    \ u) {\n            int r = leader(par[u]);\n            h[u] += h[par[u]];\n\
    \            return par[u] = r;\n        }\n        return u;\n    }\n\n    bool\
    \ same(int a, int b) {\n        return leader(a) == leader(b);\n    }\n\n    bool\
    \ merge(int s, int t, T w) {\n        w += weight(s), w -= weight(t);\n      \
    \  s = leader(s), t = leader(t);\n        if(s == t) {\n            es[s]++;\n\
    \            return false;\n        }\n\n        if(sz[s] < sz[t] && s != root)\
    \ {\n            swap(s, t);\n            w *= -1;\n        }\n\n        cc--;\n\
    \        par[t] = s;\n        sz[s] += sz[t];\n        es[s] += es[t] + 1;\n\n\
    \        h[t] = w;\n        return true;\n        \n    }\n\n    T weight(int\
    \ v) {\n        leader(v);\n        return h[v];\n    }\n\n    T diff(int s, int\
    \ t) {\n        return weight(t) - weight(s);\n    }\n\n};\n\n/*\n@brief potential\
    \ dsu\n*/\n\n#line 4 \"verify/potential_dsu.test.cpp\"\n\nint main() {\n    int\
    \ N, M;\n    while(cin >> N >> M) {\n        if(N==0) break;\n        potential_dsu<ll>\
    \ uf(N, 1);\n        rep(i, 0, M) {\n            char c;\n            cin >> c;\n\
    \            int a, b, w;\n            if(c == '!') {\n                cin >>\
    \ a >> b >> w;\n                --a, --b;\n                uf.merge(a, b, w);\n\
    \            }\n            else {\n                cin >> a >> b;\n         \
    \       --a, --b;\n                if(!uf.same(a, b)) cout << \"UNKNOWN\" << endl;\n\
    \                else cout << uf.diff(a, b) << endl;\n            }\n        }\n\
    \    }\n    \n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/potential_dsu.hpp\"\
    \n\nint main() {\n    int N, M;\n    while(cin >> N >> M) {\n        if(N==0)\
    \ break;\n        potential_dsu<ll> uf(N, 1);\n        rep(i, 0, M) {\n      \
    \      char c;\n            cin >> c;\n            int a, b, w;\n            if(c\
    \ == '!') {\n                cin >> a >> b >> w;\n                --a, --b;\n\
    \                uf.merge(a, b, w);\n            }\n            else {\n     \
    \           cin >> a >> b;\n                --a, --b;\n                if(!uf.same(a,\
    \ b)) cout << \"UNKNOWN\" << endl;\n                else cout << uf.diff(a, b)\
    \ << endl;\n            }\n        }\n    }\n    \n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/potential_dsu.hpp
  isVerificationFile: true
  path: verify/potential_dsu.test.cpp
  requiredBy: []
  timestamp: '2024-07-09 04:15:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/potential_dsu.test.cpp
layout: document
redirect_from:
- /verify/verify/potential_dsu.test.cpp
- /verify/verify/potential_dsu.test.cpp.html
title: verify/potential_dsu.test.cpp
---

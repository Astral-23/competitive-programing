---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Datastructure/undabledsu.hpp
    title: undable dsu
  - icon: ':question:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"verify/undabledsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\
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
    Datastructure/undabledsu.hpp\"\nstruct dsu {\n    using vi = vector<int>;   \n\
    \    using vvi = vec<vi>;\n    struct dat {\n        int u, v;\n        ll x;\n\
    \        dat(){}\n        dat(int a, int b, ll c) : u(a), v(b), x(c) {}\n    };\n\
    \   \n    vi par, sz, es;\n    vec<ll> val;\n    stack<dat> his;\n    int cc;\n\
    \   \n    ll op(ll l, ll r) {return l + r;}\n    ll inv(ll x) {return -x;}\n\n\
    \    dsu(int n) {\n        par = vi(n);\n        sz = vi(n, 1);\n        es =\
    \ vi(n, 0);\n        val = vec<ll>(n, 0);\n        cc = n;\n        iota(all(par),\
    \ 0);\n    }\n  \n    int leader(int u) {\n        while(par[u] != u) {\n    \
    \        u = par[u];\n        }\n        return u;\n    }\n    \n    bool same(int\
    \ a, int b) {\n        return leader(a) == leader(b);\n    }\n    \n    bool merge(int\
    \ a, int b) {\n        a = leader(a), b = leader(b);\n        if(sz[a] < sz[b])\
    \ swap(a, b);\n        his.push(dat(a, b, val[a]));\n\n        if(a == b) {\n\
    \            es[a]++;\n            return false;\n        }\n        else {\n\
    \            cc--;\n            par[b] = a;\n            sz[a] += sz[b];\n   \
    \         es[a] += es[b] + 1;\n            val[a] = op(val[a] , val[b]);\n   \
    \         return true;\n        }\n    }\n\n    bool undo() {\n        if(his.empty())\
    \ return false;\n        dat p = his.top();\n        auto [u, v, x] = p; \n  \
    \      his.pop();\n        par[v] = v;\n        es[u]--;\n        if(u != v) {\n\
    \            cc++;\n            sz[u] -= sz[v];\n            es[u] -= es[v];\n\
    \            val[u] = op(val[u], inv( val[v] ));\n        }\n        return true;\n\
    \    }\n\n    //\u4EE5\u4E0B\u3001\u5FC5\u8981\u306A\u3044\u306A\u3089\u7701\u304F\
    \u3002\n\n    void set(int v, ll f) {//\u6CE8\u610F: \u4EE3\u5165\u3067\u306F\u7121\
    \u3044\n        while(1) {\n            val[v] = op(val[v], f);\n            if(v\
    \ == par[v]) break;\n            v = par[v];\n        }\n    }\n\n    ll get(int\
    \ u) {\n        return val[leader(u)];\n    }\n\n    int size(int u) {//u\u304C\
    \u542B\u307E\u308C\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\
    \u8FD4\u3059\n        return sz[leader(u)];\n    }\n\n    int edgecnt(int u) {\n\
    \        return es[leader(u)];\n    }\n\n    int component_count() {\n       \
    \ return cc;\n    }\n\n    vvi groups() {\n        int n = par.size();\n     \
    \   vvi ms(n);\n        rep(v, 0, n) {\n            ms[leader(v)].push_back(v);\n\
    \        }\n\n        vvi res;\n        rep(i, 0, n) if(ms[i].size() > 0) {\n\
    \            res.push_back(ms[i]);\n        }\n        return res;\n    }\n\n\
    };\n\n/*\n@brief undable dsu\n@docs doc/undodsu.md\n*/\n#line 4 \"verify/undabledsu.test.cpp\"\
    \n\n\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    dsu o(N);\n    vector<vector<vector<int>>>\
    \ ivs(Q+1);\n\n    rep(qi, 0, Q) {\n        int t, k, u, v;\n        cin >> t\
    \ >> k >> u >> v;\n        k++;\n        ivs[k].push_back({t, int(qi)+1, u, v});\n\
    \       \n    }\n\n    vector<int> ans(Q+1, -1);\n\n    auto dfs = [&](auto f,\
    \ int k, dsu& d) -> void {\n        for(auto a : ivs[k]) {\n            if(a[0]\
    \ == 1) {\n                if(d.same(a[2], a[3])) ans[a[1]-1] = 1;\n         \
    \       else ans[a[1]-1] = 0;\n                continue;\n            }\n    \
    \        else {\n                d.merge(a[2], a[3]);\n                f(f, a[1],\
    \ d);\n                d.undo();\n            }\n        }\n    };\n\n\n    dfs(dfs,\
    \ 0, o);\n    rep(qi,0 ,Q) if(ans[qi] != -1) cout << ans[qi] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include \"../Utility/template.hpp\"\n#include \"../Datastructure/undabledsu.hpp\"\
    \n\n\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    dsu o(N);\n    vector<vector<vector<int>>>\
    \ ivs(Q+1);\n\n    rep(qi, 0, Q) {\n        int t, k, u, v;\n        cin >> t\
    \ >> k >> u >> v;\n        k++;\n        ivs[k].push_back({t, int(qi)+1, u, v});\n\
    \       \n    }\n\n    vector<int> ans(Q+1, -1);\n\n    auto dfs = [&](auto f,\
    \ int k, dsu& d) -> void {\n        for(auto a : ivs[k]) {\n            if(a[0]\
    \ == 1) {\n                if(d.same(a[2], a[3])) ans[a[1]-1] = 1;\n         \
    \       else ans[a[1]-1] = 0;\n                continue;\n            }\n    \
    \        else {\n                d.merge(a[2], a[3]);\n                f(f, a[1],\
    \ d);\n                d.undo();\n            }\n        }\n    };\n\n\n    dfs(dfs,\
    \ 0, o);\n    rep(qi,0 ,Q) if(ans[qi] != -1) cout << ans[qi] << '\\n';\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/undabledsu.hpp
  isVerificationFile: true
  path: verify/undabledsu.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/undabledsu.test.cpp
layout: document
redirect_from:
- /verify/verify/undabledsu.test.cpp
- /verify/verify/undabledsu.test.cpp.html
title: verify/undabledsu.test.cpp
---

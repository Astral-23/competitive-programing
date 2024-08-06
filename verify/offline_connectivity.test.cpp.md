---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/offline_connectivity.hpp
    title: offline_connectivity
  - icon: ':heavy_check_mark:'
    path: Datastructure/undabledsu.hpp
    title: undable dsu
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "#line 1 \"verify/offline_connectivity.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\n\
    #line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n\
    #define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x)\
    \ begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/undabledsu.hpp\"\nstruct dsu {\n\
    \    using vi = vector<int>;   \n    using vvi = vec<vi>;\n    struct dat {\n\
    \        int u, v;\n        ll x;\n        dat(){}\n        dat(int a, int b,\
    \ ll c) : u(a), v(b), x(c) {}\n    };\n   \n    vi par, sz, es;\n    vec<ll> val;\n\
    \    stack<dat> his;\n    int cc;\n   \n    ll op(ll l, ll r) {return l + r;}\n\
    \    ll inv(ll x) {return -x;}\n\n    dsu(int n) {\n        par = vi(n);\n   \
    \     sz = vi(n, 1);\n        es = vi(n, 0);\n        val = vec<ll>(n, 0);\n \
    \       cc = n;\n        iota(all(par), 0);\n    }\n  \n    int leader(int u)\
    \ {\n        while(par[u] != u) {\n            u = par[u];\n        }\n      \
    \  return u;\n    }\n    \n    bool same(int a, int b) {\n        return leader(a)\
    \ == leader(b);\n    }\n    \n    bool merge(int a, int b) {\n        a = leader(a),\
    \ b = leader(b);\n        if(sz[a] < sz[b]) swap(a, b);\n        his.push(dat(a,\
    \ b, val[a]));\n\n        if(a == b) {\n            es[a]++;\n            return\
    \ false;\n        }\n        else {\n            cc--;\n            par[b] = a;\n\
    \            sz[a] += sz[b];\n            es[a] += es[b] + 1;\n            val[a]\
    \ = op(val[a] , val[b]);\n            return true;\n        }\n    }\n\n    bool\
    \ undo() {\n        if(his.empty()) return false;\n        dat p = his.top();\n\
    \        auto [u, v, x] = p; \n        his.pop();\n        par[v] = v;\n     \
    \   es[u]--;\n        if(u != v) {\n            cc++;\n            sz[u] -= sz[v];\n\
    \            es[u] -= es[v];\n            val[u] = op(val[u], inv( val[v] ));\n\
    \        }\n        return true;\n    }\n\n    //\u4EE5\u4E0B\u3001\u5FC5\u8981\
    \u306A\u3044\u306A\u3089\u7701\u304F\u3002\n\n    void set(int v, ll f) {//\u6CE8\
    \u610F: \u4EE3\u5165\u3067\u306F\u7121\u3044\n        while(1) {\n           \
    \ val[v] = op(val[v], f);\n            if(v == par[v]) break;\n            v =\
    \ par[v];\n        }\n    }\n\n    ll get(int u) {\n        return val[leader(u)];\n\
    \    }\n\n    int size(int u) {//u\u304C\u542B\u307E\u308C\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n        return sz[leader(u)];\n\
    \    }\n\n    int edgecnt(int u) {\n        return es[leader(u)];\n    }\n\n \
    \   int component_count() {\n        return cc;\n    }\n\n    vvi groups() {\n\
    \        int n = par.size();\n        vvi ms(n);\n        rep(v, 0, n) {\n   \
    \         ms[leader(v)].push_back(v);\n        }\n\n        vvi res;\n       \
    \ rep(i, 0, n) if(ms[i].size() > 0) {\n            res.push_back(ms[i]);\n   \
    \     }\n        return res;\n    }\n\n};\n\n/*\n@brief undable dsu\n@docs doc/undodsu.md\n\
    */\n#line 1 \"Datastructure/offline_connectivity.hpp\"\ntemplate<class dsu, class\
    \ S, class qif, bool multi_edge>\nstruct offline_connectivity {\n    using pii\
    \ = pair<int, int>;\n    using edge = array<int, 4>;\n    using que = pair<int,\
    \ qif>;\n    int n, t, sz, qi, li;\n    dsu uf;\n    vec<vec<pii>> dat;\n    vec<multiset<pii>>\
    \ es;\n    vec<edge> lrs;\n    vec<que> qs;\n    vec<array<ll, 3>> lz;//{t, \u9802\
    \u70B9, \u4F5C\u7528\u7D20}  \u4F5C\u7528\u7D20\u304Cll\u3067\u306F\u306A\u3044\
    \u5834\u5408\u3001\u9811\u5F35\u308B\u3002\n    vec<S> res;\n\n    offline_connectivity(int\
    \ N) : n(N), es(N), qi(0), li(0), t(0), sz(1), uf(N) { }\n\n    void build() {\n\
    \        rep(u, 0, n) {\n            for(auto [v, l] : es[u]) {\n            \
    \    lrs.push_back(edge{l, t, int(u), v});\n            }\n        }\n       \n\
    \        while(sz < t) sz <<= 1;\n        dat.resize(2 * sz);\n\n        for(auto\
    \ [l, r, u, v] : lrs) {\n            l += sz;\n            r += sz;\n        \
    \    while(l < r) {\n                if(l & 1) dat[l++].emplace_back(u, v);\n\
    \                if(r & 1) dat[--r].emplace_back(u, v);\n                l >>=\
    \ 1, r >>= 1;\n            }\n        }\n    }\n\n    TT void dfs(T f, int v)\
    \ {\n        for(auto [a, b] : dat[v]) uf.merge(a, b);\n        if(v >= sz) {\n\
    \            while(li < lz.size() && lz[li][0] == v - sz) uf.set(lz[li][1], lz[li][2]),\
    \ li++;//set\u2192 apply\u306B\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\u304B\
    \u3082(dsu\u306B\u5408\u308F\u305B\u308B)\n            if(qi < qs.size() && qs[qi].first\
    \ == v - sz) res.push_back(f(uf, qs[qi++].second));\n        }\n        else {\n\
    \            dfs(f, v * 2);\n            dfs(f, v * 2 + 1);\n        }\n     \
    \   rep(i, 0, dat[v].size()) uf.undo();\n    }\n    \n\n    TT vec<S> run(T f)\
    \ {\n        dfs(f, 1);\n        return res;\n    }\n\n    void link(int u, int\
    \ v) {\n        if(u > v) swap(u, v);\n        if(multi_edge == true) es[u].insert(pii(v,\
    \ t));\n        else {\n            auto it = es[u].lower_bound(pii(v, -1));\n\
    \            if(it != es[u].end() && (*it).first == v) return;\n            es[u].insert(pii(v,\
    \ t));\n        }\n    }\n\n    void cut(int u, int v) {\n        if(u > v) swap(u,\
    \ v);\n        auto it = es[u].lower_bound(pii(v, -1));\n        if(it == es[u].end())\
    \ return;\n        auto [tar, l] = *it;\n        if(tar != v) return;\n      \
    \  es[u].erase(it);\n        lrs.push_back(edge{l, t, u, v});\n        \n    }\n\
    \n    void query(qif q) {\n        qs.push_back(que(t++, q));\n    }\n\n    void\
    \ apply(int v, ll f) {\n        lz.push_back({t, v, f});\n    }\n\n    void set(int\
    \ v, ll f) {//uf\u306Eapply\u306B\u76F8\u5F53\u3059\u308B\u95A2\u6570\u540D\u304C\
    set\u3060\u3063\u305F\u6642\u7528\n        lz.push_back({t, v, f});\n    }\n\n\
    };\n/*\nS f(dsu &uf, qif q) {\n    return \u7B54\u3048\n}\n\u3092run\u306B\u6E21\
    \u3059\n&\u3092\u4ED8\u3051\u308B\u4E8B\u3092\u5FD8\u308C\u305A\u306B\uFF08\u8A08\
    \u7B97\u91CF\u3053\u308F\u308C\u308B\uFF09\n\n@brief offline_connectivity\n@docs\
    \ doc/offline_connectivity.md\n*/\n#line 5 \"verify/offline_connectivity.test.cpp\"\
    \n\n\n\nll f(dsu &uf, int v) {\n    return uf.get(v);\n}\n\n\nint main() {\n \
    \   int n, q;\n    cin >> n >> q;\n    vec<ll> A(n);\n    rep(i, 0, n) cin >>\
    \ A[i];\n    offline_connectivity<dsu, ll, int, false> uf(n);\n    rep(i, 0, n)\
    \ uf.apply(i, A[i]);\n\n    while(q--) {\n        int t;\n        cin >> t;\n\
    \        if(t == 0) {\n            int u, v;\n            cin >> u >> v;\n   \
    \         uf.link(u, v);\n        }\n        else if(t == 1) {\n            int\
    \ u, v;\n            cin >> u >> v;\n            uf.cut(u, v);\n        }\n  \
    \      else if(t == 2) {\n            int v; ll x;\n            cin >> v >> x;\n\
    \            uf.apply(v, x);\n        }\n        else {\n            int v;\n\
    \            cin >> v;\n            uf.query(v);\n        }\n    }\n\n    uf.build();\n\
    \    auto res = uf.run(f);\n    for(ll x : res) cout << x << '\\n';\n    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/undabledsu.hpp\"\
    \n#include \"../Datastructure/offline_connectivity.hpp\"\n\n\n\nll f(dsu &uf,\
    \ int v) {\n    return uf.get(v);\n}\n\n\nint main() {\n    int n, q;\n    cin\
    \ >> n >> q;\n    vec<ll> A(n);\n    rep(i, 0, n) cin >> A[i];\n    offline_connectivity<dsu,\
    \ ll, int, false> uf(n);\n    rep(i, 0, n) uf.apply(i, A[i]);\n\n    while(q--)\
    \ {\n        int t;\n        cin >> t;\n        if(t == 0) {\n            int\
    \ u, v;\n            cin >> u >> v;\n            uf.link(u, v);\n        }\n \
    \       else if(t == 1) {\n            int u, v;\n            cin >> u >> v;\n\
    \            uf.cut(u, v);\n        }\n        else if(t == 2) {\n           \
    \ int v; ll x;\n            cin >> v >> x;\n            uf.apply(v, x);\n    \
    \    }\n        else {\n            int v;\n            cin >> v;\n          \
    \  uf.query(v);\n        }\n    }\n\n    uf.build();\n    auto res = uf.run(f);\n\
    \    for(ll x : res) cout << x << '\\n';\n    \n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/undabledsu.hpp
  - Datastructure/offline_connectivity.hpp
  isVerificationFile: true
  path: verify/offline_connectivity.test.cpp
  requiredBy: []
  timestamp: '2024-07-09 04:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/offline_connectivity.test.cpp
layout: document
redirect_from:
- /verify/verify/offline_connectivity.test.cpp
- /verify/verify/offline_connectivity.test.cpp.html
title: verify/offline_connectivity.test.cpp
---
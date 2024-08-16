---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Datastructure/offline_connectivity.hpp
    title: offline_connectivity
  - icon: ':x:'
    path: Datastructure/value_dsu.hpp
    title: "\u5024\u96C6\u7D04\u30FB\u5909\u66F4\u53EF\u80FD\u306Adsu"
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "#line 1 \"verify/value_dsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/value_dsu.hpp\"\
    \ntemplate<class S, S (*op)(S, S), S (*e) ()> struct dsu {\n    using vi = vec<int>;\n\
    \    using vvi = vec<vi>;   \n\n    struct dat {\n        int r, u, v, p;\n  \
    \      dat(){}\n        dat(int a, int b, int c, int d) : r(a), u(b), v(c), p(d)\
    \ {}\n    };\n   \n    int cc;\n    vi par, sz, es, lv, lch, rch, rank;\n    vec<S>\
    \ A, acc;\n    stack<dat> his;\n   \n\n    dsu(int n) {\n        cc = n;\n   \
    \     par = vi(n);\n        lv = rank = es = vi(n, 0);\n        sz = vi(n, 1);\n\
    \        lch = rch = vi(n, -1);\n        A = acc = vec<S>(n, e());\n        iota(all(par),\
    \ 0);\n    }\n  \n    int leader(int u) {\n        while(par[u] != u) {\n    \
    \        u = par[u];\n        }\n        return u;\n    }\n    \n    bool same(int\
    \ a, int b) {\n        return leader(a) == leader(b);\n    }\n\n    int update(int\
    \ v) {\n        while(1) {\n            if(rch[v] != -1) {\n                lv[v]\
    \ = min(lv[lch[v]], lv[rch[v]]) + 1;\n                acc[v] = op(A[v], op(acc[lch[v]],\
    \ acc[rch[v]]));\n            }\n            else if(lch[v] != -1) {\n       \
    \         lv[v] = 0;\n                acc[v] = op(A[v], acc[lch[v]]);\n      \
    \      }\n            else {\n                lv[v] = 0;\n                acc[v]\
    \ = A[v];\n            }\n            if(v == par[v]) break;\n            v =\
    \ par[v];\n        }\n        return v;\n    }\n\n    \n    bool merge(int a,\
    \ int b) {\n        a = leader(a), b = leader(b);\n    \n        if(max(rank[a],\
    \ rank[b] + lv[a] + 1)  > max(rank[b], rank[a] + lv[b] + 1)) swap(a, b);\n   \
    \  \n        if(a == b) {\n            es[a]++;\n            his.push(dat(a, -1,\
    \ -1, -1));\n            return false;\n        }\n\n        cc--;\n        int\
    \ r = a;\n        int p = rank[a];\n        rank[a] = max(rank[a], lv[a] + rank[b]\
    \ + 1);\n        sz[a] += sz[b];\n        es[a] += es[b] + 1;\n\n        while(lch[a]\
    \ != -1 && rch[a] != -1) {\n            if(lv[lch[a]] < lv[rch[a]]) a = lch[a];\n\
    \            else a = rch[a];\n        }\n\n        par[b] = a;\n        if(lch[a]\
    \ == -1) lch[a] = b;\n        else rch[a] = b;\n        his.push(dat(r, a, b,\
    \ p));\n        update(a);\n        return true;\n    }\n\n    bool undo () {\n\
    \        if(his.empty()) return false;\n        dat pre = his.top();\n       \
    \ his.pop();\n        es[pre.r]--;\n\n        if(pre.u >= 0) {\n            cc++;\n\
    \            sz[pre.r] -= sz[pre.v];\n            es[pre.r] -= es[pre.v];\n  \
    \          rank[pre.r] = pre.p;\n            par[pre.v] = pre.v;\n           \
    \ if(lch[pre.u] == pre.v) lch[pre.u] = -1;\n            else rch[pre.u] = -1;\n\
    \            update(pre.u);\n        }\n        return true;\n    }\n\n    S get(int\
    \ u) {\n        return acc[leader(u)];\n    }\n\n    void set(int u, S s) {\n\
    \        A[u] = s;\n        update(u);\n    }\n\n    int size(int u) {//u\u304C\
    \u542B\u307E\u308C\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\
    \u8FD4\u3059\n        return sz[leader(u)];\n    }\n\n    int edgecnt(int u) {\n\
    \        return es[leader(u)];\n    }\n\n    int component_count() {\n       \
    \ return cc;\n    }\n\n    vvi groups() {\n        int n = par.size();\n     \
    \   vvi ms(n);\n        rep(v, 0, n) {\n            ms[leader(v)].push_back(v);\n\
    \        }\n\n        vvi res;\n        rep(i, 0, n) if(ms[i].size() > 0) {\n\
    \            res.push_back(ms[i]);\n        }\n        return res;\n    }\n};\n\
    \n/*\n@brief \u5024\u96C6\u7D04\u30FB\u5909\u66F4\u53EF\u80FD\u306Adsu\n@docs\
    \ doc/value_dsu.md\n*/\n#line 1 \"Datastructure/offline_connectivity.hpp\"\ntemplate<class\
    \ dsu, class S, class qif, bool multi_edge>\nstruct offline_connectivity {\n \
    \   using pii = pair<int, int>;\n    using edge = array<int, 4>;\n    using que\
    \ = pair<int, qif>;\n    int n, t, sz, qi, li;\n    dsu uf;\n    vec<vec<pii>>\
    \ dat;\n    vec<multiset<pii>> es;\n    vec<edge> lrs;\n    vec<que> qs;\n   \
    \ vec<array<ll, 3>> lz;//{t, \u9802\u70B9, \u4F5C\u7528\u7D20}  \u4F5C\u7528\u7D20\
    \u304Cll\u3067\u306F\u306A\u3044\u5834\u5408\u3001\u9811\u5F35\u308B\u3002\n \
    \   vec<S> res;\n\n    offline_connectivity(int N) : n(N), es(N), qi(0), li(0),\
    \ t(0), sz(1), uf(N) { }\n\n    void build() {\n        rep(u, 0, n) {\n     \
    \       for(auto [v, l] : es[u]) {\n                lrs.push_back(edge{l, t, int(u),\
    \ v});\n            }\n        }\n       \n        while(sz < t) sz <<= 1;\n \
    \       dat.resize(2 * sz);\n\n        for(auto [l, r, u, v] : lrs) {\n      \
    \      l += sz;\n            r += sz;\n            while(l < r) {\n          \
    \      if(l & 1) dat[l++].emplace_back(u, v);\n                if(r & 1) dat[--r].emplace_back(u,\
    \ v);\n                l >>= 1, r >>= 1;\n            }\n        }\n    }\n\n\
    \    TT void dfs(T f, int v) {\n        for(auto [a, b] : dat[v]) uf.merge(a,\
    \ b);\n        if(v >= sz) {\n            while(li < lz.size() && lz[li][0] ==\
    \ v - sz) uf.set(lz[li][1], lz[li][2]), li++;//set\u2192 apply\u306B\u3059\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\u304B\u3082(dsu\u306B\u5408\u308F\u305B\u308B)\n\
    \            if(qi < qs.size() && qs[qi].first == v - sz) res.push_back(f(uf,\
    \ qs[qi++].second));\n        }\n        else {\n            dfs(f, v * 2);\n\
    \            dfs(f, v * 2 + 1);\n        }\n        rep(i, 0, dat[v].size()) uf.undo();\n\
    \    }\n    \n\n    TT vec<S> run(T f) {\n        dfs(f, 1);\n        return res;\n\
    \    }\n\n    void link(int u, int v) {\n        if(u > v) swap(u, v);\n     \
    \   if(multi_edge == true) es[u].insert(pii(v, t));\n        else {\n        \
    \    auto it = es[u].lower_bound(pii(v, -1));\n            if(it != es[u].end()\
    \ && (*it).first == v) return;\n            es[u].insert(pii(v, t));\n       \
    \ }\n    }\n\n    void cut(int u, int v) {\n        if(u > v) swap(u, v);\n  \
    \      auto it = es[u].lower_bound(pii(v, -1));\n        if(it == es[u].end())\
    \ return;\n        auto [tar, l] = *it;\n        if(tar != v) return;\n      \
    \  es[u].erase(it);\n        lrs.push_back(edge{l, t, u, v});\n        \n    }\n\
    \n    void query(qif q) {\n        qs.push_back(que(t++, q));\n    }\n\n    void\
    \ apply(int v, ll f) {\n        lz.push_back({t, v, f});\n    }\n\n    void set(int\
    \ v, ll f) {//uf\u306Eapply\u306B\u76F8\u5F53\u3059\u308B\u95A2\u6570\u540D\u304C\
    set\u3060\u3063\u305F\u6642\u7528\n        lz.push_back({t, v, f});\n    }\n\n\
    };\n/*\nS f(dsu &uf, qif q) {\n    return \u7B54\u3048\n}\n\u3092run\u306B\u6E21\
    \u3059\n&\u3092\u4ED8\u3051\u308B\u4E8B\u3092\u5FD8\u308C\u305A\u306B\uFF08\u8A08\
    \u7B97\u91CF\u3053\u308F\u308C\u308B\uFF09\n\n@brief offline_connectivity\n@docs\
    \ doc/offline_connectivity.md\n*/\n#line 5 \"verify/value_dsu.test.cpp\"\n\nusing\
    \ S = ll;\nS op(S l, S r) {\n    return l + r;\n}\n\nS e() {\n    return 0LL;\n\
    }\n\n\nS f(dsu<S, op, e> &uf, int v) {\n    return uf.get(v);\n}\n\nint main()\
    \ {\n    int n, q;\n    cin >> n >> q;\n    vec<ll> A(n);\n    rep(i, 0, n) cin\
    \ >> A[i];\n    offline_connectivity<dsu<S, op, e>, S, int, false> uf(n);\n  \
    \  rep(i, 0, n) uf.set(i, A[i]);\n\n    while(q--) {\n        int t;\n       \
    \ cin >> t;\n        if(t == 0) {\n            int u, v;\n            cin >> u\
    \ >> v;\n            uf.link(u, v);\n        }\n        else if(t == 1) {\n  \
    \          int u, v;\n            cin >> u >> v;\n            uf.cut(u, v);\n\
    \        }\n        else if(t == 2) {\n            int v; ll x;\n            cin\
    \ >> v >> x;\n            A[v] += x;\n            uf.set(v, A[v]);\n        }\n\
    \        else {\n            int v;\n            cin >> v;\n            uf.query(v);\n\
    \        }\n    }\n\n    uf.build();\n    auto res = uf.run(f);\n    for(ll x\
    \ : res) cout << x << \"\\n\";\n\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/value_dsu.hpp\"\
    \n#include \"../Datastructure/offline_connectivity.hpp\"\n\nusing S = ll;\nS op(S\
    \ l, S r) {\n    return l + r;\n}\n\nS e() {\n    return 0LL;\n}\n\n\nS f(dsu<S,\
    \ op, e> &uf, int v) {\n    return uf.get(v);\n}\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    vec<ll> A(n);\n    rep(i, 0, n) cin >> A[i];\n    offline_connectivity<dsu<S,\
    \ op, e>, S, int, false> uf(n);\n    rep(i, 0, n) uf.set(i, A[i]);\n\n    while(q--)\
    \ {\n        int t;\n        cin >> t;\n        if(t == 0) {\n            int\
    \ u, v;\n            cin >> u >> v;\n            uf.link(u, v);\n        }\n \
    \       else if(t == 1) {\n            int u, v;\n            cin >> u >> v;\n\
    \            uf.cut(u, v);\n        }\n        else if(t == 2) {\n           \
    \ int v; ll x;\n            cin >> v >> x;\n            A[v] += x;\n         \
    \   uf.set(v, A[v]);\n        }\n        else {\n            int v;\n        \
    \    cin >> v;\n            uf.query(v);\n        }\n    }\n\n    uf.build();\n\
    \    auto res = uf.run(f);\n    for(ll x : res) cout << x << \"\\n\";\n\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/value_dsu.hpp
  - Datastructure/offline_connectivity.hpp
  isVerificationFile: true
  path: verify/value_dsu.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/value_dsu.test.cpp
layout: document
redirect_from:
- /verify/verify/value_dsu.test.cpp
- /verify/verify/value_dsu.test.cpp.html
title: verify/value_dsu.test.cpp
---

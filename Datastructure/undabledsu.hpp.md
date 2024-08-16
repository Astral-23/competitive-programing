---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: example/offline_connectivity.example.cpp
    title: example/offline_connectivity.example.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/offline_connectivity.test.cpp
    title: verify/offline_connectivity.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/offline_connectivity_more.test.cpp
    title: verify/offline_connectivity_more.test.cpp
  - icon: ':x:'
    path: verify/undabledsu.test.cpp
    title: verify/undabledsu.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: doc/undodsu.md
    document_title: undable dsu
    links: []
  bundledCode: "#line 1 \"Datastructure/undabledsu.hpp\"\nstruct dsu {\n    using\
    \ vi = vector<int>;   \n    using vvi = vec<vi>;\n    struct dat {\n        int\
    \ u, v;\n        ll x;\n        dat(){}\n        dat(int a, int b, ll c) : u(a),\
    \ v(b), x(c) {}\n    };\n   \n    vi par, sz, es;\n    vec<ll> val;\n    stack<dat>\
    \ his;\n    int cc;\n   \n    ll op(ll l, ll r) {return l + r;}\n    ll inv(ll\
    \ x) {return -x;}\n\n    dsu(int n) {\n        par = vi(n);\n        sz = vi(n,\
    \ 1);\n        es = vi(n, 0);\n        val = vec<ll>(n, 0);\n        cc = n;\n\
    \        iota(all(par), 0);\n    }\n  \n    int leader(int u) {\n        while(par[u]\
    \ != u) {\n            u = par[u];\n        }\n        return u;\n    }\n    \n\
    \    bool same(int a, int b) {\n        return leader(a) == leader(b);\n    }\n\
    \    \n    bool merge(int a, int b) {\n        a = leader(a), b = leader(b);\n\
    \        if(sz[a] < sz[b]) swap(a, b);\n        his.push(dat(a, b, val[a]));\n\
    \n        if(a == b) {\n            es[a]++;\n            return false;\n    \
    \    }\n        else {\n            cc--;\n            par[b] = a;\n         \
    \   sz[a] += sz[b];\n            es[a] += es[b] + 1;\n            val[a] = op(val[a]\
    \ , val[b]);\n            return true;\n        }\n    }\n\n    bool undo() {\n\
    \        if(his.empty()) return false;\n        dat p = his.top();\n        auto\
    \ [u, v, x] = p; \n        his.pop();\n        par[v] = v;\n        es[u]--;\n\
    \        if(u != v) {\n            cc++;\n            sz[u] -= sz[v];\n      \
    \      es[u] -= es[v];\n            val[u] = op(val[u], inv( val[v] ));\n    \
    \    }\n        return true;\n    }\n\n    //\u4EE5\u4E0B\u3001\u5FC5\u8981\u306A\
    \u3044\u306A\u3089\u7701\u304F\u3002\n\n    void set(int v, ll f) {//\u6CE8\u610F\
    : \u4EE3\u5165\u3067\u306F\u7121\u3044\n        while(1) {\n            val[v]\
    \ = op(val[v], f);\n            if(v == par[v]) break;\n            v = par[v];\n\
    \        }\n    }\n\n    ll get(int u) {\n        return val[leader(u)];\n   \
    \ }\n\n    int size(int u) {//u\u304C\u542B\u307E\u308C\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n        return sz[leader(u)];\n\
    \    }\n\n    int edgecnt(int u) {\n        return es[leader(u)];\n    }\n\n \
    \   int component_count() {\n        return cc;\n    }\n\n    vvi groups() {\n\
    \        int n = par.size();\n        vvi ms(n);\n        rep(v, 0, n) {\n   \
    \         ms[leader(v)].push_back(v);\n        }\n\n        vvi res;\n       \
    \ rep(i, 0, n) if(ms[i].size() > 0) {\n            res.push_back(ms[i]);\n   \
    \     }\n        return res;\n    }\n\n};\n\n/*\n@brief undable dsu\n@docs doc/undodsu.md\n\
    */\n"
  code: "struct dsu {\n    using vi = vector<int>;   \n    using vvi = vec<vi>;\n\
    \    struct dat {\n        int u, v;\n        ll x;\n        dat(){}\n       \
    \ dat(int a, int b, ll c) : u(a), v(b), x(c) {}\n    };\n   \n    vi par, sz,\
    \ es;\n    vec<ll> val;\n    stack<dat> his;\n    int cc;\n   \n    ll op(ll l,\
    \ ll r) {return l + r;}\n    ll inv(ll x) {return -x;}\n\n    dsu(int n) {\n \
    \       par = vi(n);\n        sz = vi(n, 1);\n        es = vi(n, 0);\n       \
    \ val = vec<ll>(n, 0);\n        cc = n;\n        iota(all(par), 0);\n    }\n \
    \ \n    int leader(int u) {\n        while(par[u] != u) {\n            u = par[u];\n\
    \        }\n        return u;\n    }\n    \n    bool same(int a, int b) {\n  \
    \      return leader(a) == leader(b);\n    }\n    \n    bool merge(int a, int\
    \ b) {\n        a = leader(a), b = leader(b);\n        if(sz[a] < sz[b]) swap(a,\
    \ b);\n        his.push(dat(a, b, val[a]));\n\n        if(a == b) {\n        \
    \    es[a]++;\n            return false;\n        }\n        else {\n        \
    \    cc--;\n            par[b] = a;\n            sz[a] += sz[b];\n           \
    \ es[a] += es[b] + 1;\n            val[a] = op(val[a] , val[b]);\n           \
    \ return true;\n        }\n    }\n\n    bool undo() {\n        if(his.empty())\
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
    };\n\n/*\n@brief undable dsu\n@docs doc/undodsu.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/undabledsu.hpp
  requiredBy:
  - example/offline_connectivity.example.cpp
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/offline_connectivity.test.cpp
  - verify/undabledsu.test.cpp
  - verify/offline_connectivity_more.test.cpp
documentation_of: Datastructure/undabledsu.hpp
layout: document
redirect_from:
- /library/Datastructure/undabledsu.hpp
- /library/Datastructure/undabledsu.hpp.html
title: undable dsu
---
## 概要
ACLのdsuをundo可能にし、更に機能を幾らか追加した。かつ、値の集約をつけた。

## コンストラクタ
dsu d(n)
- **計算量**
    $O(n)$

## 関数

- **merge(int u, int v)**...辺(u, v)を追加する。u, vが非連結だった場合true,そうでなければfalseを返す。
    - **制約**
    $0 \le u, v < n$
    - **計算量**
    $O(1)$

- **merge(int u, int v)**...頂点u, vが連結かどうかを返す。
    - **制約**
    $0 \le u, v < n$
    - **計算量**
    $O(\log{n})$

- **leader(int u)**...頂点uの属する連結成分の代表元を返す
    - **制約**
    $0 \le u < n$
    - **計算量**
    $O(\log{n})$
- **set(int u, ll f)** ... a[u] = op(a[u], f)。**代入では無い！**
    - **制約**
    $0 \le u < n$
    - **計算量**
    $O(\log{n})$

- **get(int u)** ... uが属する連結成分の頂点の値をopで集約した結果を返す
   - **制約**
    $0 \le u < n$
    - **計算量**
    $O(\log{n})$

- **size(int u)**...頂点uの属する連結成分のサイズを返す
    - **計算量**
    $O(\log{n})$


- **groups()**...グラフを連結成分ごとに分け、その情報を返す
    - **計算量**
    $O(n \log n)$
    - **備考**
    groupsで帰ってきた配列のサイズ = 連結成分の個数
 
- **edgecnt(int u)** ... 頂点uの属する連結成分が持つ辺の本数を返す
    - **計算量**
    $O(\log{n})$

- **componentcnt()** ... {0, ... , n-1}について、連結成分の個数を返す
    - **計算量**
    $O(1)$

## このデータ構造が想定している状況
値の集約について: <br>

値の変更がある場合 : 演算は逆元がないといけない。(例 : +, xor)<br>

値の変更が無い場合 : 逆元が無い演算も可能である、と考えている。実装変更する必要がある。<br>

またデフォルトでは+であり、変更したい場合、opとinvをそれぞれ演算・逆元を返すように変更する。

## verify
edgecnt ... https://atcoder.jp/contests/abc302/submissions/53942333

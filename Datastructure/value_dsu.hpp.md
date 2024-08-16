---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/value_dsu.test.cpp
    title: verify/value_dsu.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: doc/value_dsu.md
    document_title: "\u5024\u96C6\u7D04\u30FB\u5909\u66F4\u53EF\u80FD\u306Adsu"
    links: []
  bundledCode: "#line 1 \"Datastructure/value_dsu.hpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e) ()> struct dsu {\n    using vi = vec<int>;\n    using vvi = vec<vi>;\
    \   \n\n    struct dat {\n        int r, u, v, p;\n        dat(){}\n        dat(int\
    \ a, int b, int c, int d) : r(a), u(b), v(c), p(d) {}\n    };\n   \n    int cc;\n\
    \    vi par, sz, es, lv, lch, rch, rank;\n    vec<S> A, acc;\n    stack<dat> his;\n\
    \   \n\n    dsu(int n) {\n        cc = n;\n        par = vi(n);\n        lv =\
    \ rank = es = vi(n, 0);\n        sz = vi(n, 1);\n        lch = rch = vi(n, -1);\n\
    \        A = acc = vec<S>(n, e());\n        iota(all(par), 0);\n    }\n  \n  \
    \  int leader(int u) {\n        while(par[u] != u) {\n            u = par[u];\n\
    \        }\n        return u;\n    }\n    \n    bool same(int a, int b) {\n  \
    \      return leader(a) == leader(b);\n    }\n\n    int update(int v) {\n    \
    \    while(1) {\n            if(rch[v] != -1) {\n                lv[v] = min(lv[lch[v]],\
    \ lv[rch[v]]) + 1;\n                acc[v] = op(A[v], op(acc[lch[v]], acc[rch[v]]));\n\
    \            }\n            else if(lch[v] != -1) {\n                lv[v] = 0;\n\
    \                acc[v] = op(A[v], acc[lch[v]]);\n            }\n            else\
    \ {\n                lv[v] = 0;\n                acc[v] = A[v];\n            }\n\
    \            if(v == par[v]) break;\n            v = par[v];\n        }\n    \
    \    return v;\n    }\n\n    \n    bool merge(int a, int b) {\n        a = leader(a),\
    \ b = leader(b);\n    \n        if(max(rank[a], rank[b] + lv[a] + 1)  > max(rank[b],\
    \ rank[a] + lv[b] + 1)) swap(a, b);\n     \n        if(a == b) {\n           \
    \ es[a]++;\n            his.push(dat(a, -1, -1, -1));\n            return false;\n\
    \        }\n\n        cc--;\n        int r = a;\n        int p = rank[a];\n  \
    \      rank[a] = max(rank[a], lv[a] + rank[b] + 1);\n        sz[a] += sz[b];\n\
    \        es[a] += es[b] + 1;\n\n        while(lch[a] != -1 && rch[a] != -1) {\n\
    \            if(lv[lch[a]] < lv[rch[a]]) a = lch[a];\n            else a = rch[a];\n\
    \        }\n\n        par[b] = a;\n        if(lch[a] == -1) lch[a] = b;\n    \
    \    else rch[a] = b;\n        his.push(dat(r, a, b, p));\n        update(a);\n\
    \        return true;\n    }\n\n    bool undo () {\n        if(his.empty()) return\
    \ false;\n        dat pre = his.top();\n        his.pop();\n        es[pre.r]--;\n\
    \n        if(pre.u >= 0) {\n            cc++;\n            sz[pre.r] -= sz[pre.v];\n\
    \            es[pre.r] -= es[pre.v];\n            rank[pre.r] = pre.p;\n     \
    \       par[pre.v] = pre.v;\n            if(lch[pre.u] == pre.v) lch[pre.u] =\
    \ -1;\n            else rch[pre.u] = -1;\n            update(pre.u);\n       \
    \ }\n        return true;\n    }\n\n    S get(int u) {\n        return acc[leader(u)];\n\
    \    }\n\n    void set(int u, S s) {\n        A[u] = s;\n        update(u);\n\
    \    }\n\n    int size(int u) {//u\u304C\u542B\u307E\u308C\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n        return sz[leader(u)];\n\
    \    }\n\n    int edgecnt(int u) {\n        return es[leader(u)];\n    }\n\n \
    \   int component_count() {\n        return cc;\n    }\n\n    vvi groups() {\n\
    \        int n = par.size();\n        vvi ms(n);\n        rep(v, 0, n) {\n   \
    \         ms[leader(v)].push_back(v);\n        }\n\n        vvi res;\n       \
    \ rep(i, 0, n) if(ms[i].size() > 0) {\n            res.push_back(ms[i]);\n   \
    \     }\n        return res;\n    }\n};\n\n/*\n@brief \u5024\u96C6\u7D04\u30FB\
    \u5909\u66F4\u53EF\u80FD\u306Adsu\n@docs doc/value_dsu.md\n*/\n"
  code: "template<class S, S (*op)(S, S), S (*e) ()> struct dsu {\n    using vi =\
    \ vec<int>;\n    using vvi = vec<vi>;   \n\n    struct dat {\n        int r, u,\
    \ v, p;\n        dat(){}\n        dat(int a, int b, int c, int d) : r(a), u(b),\
    \ v(c), p(d) {}\n    };\n   \n    int cc;\n    vi par, sz, es, lv, lch, rch, rank;\n\
    \    vec<S> A, acc;\n    stack<dat> his;\n   \n\n    dsu(int n) {\n        cc\
    \ = n;\n        par = vi(n);\n        lv = rank = es = vi(n, 0);\n        sz =\
    \ vi(n, 1);\n        lch = rch = vi(n, -1);\n        A = acc = vec<S>(n, e());\n\
    \        iota(all(par), 0);\n    }\n  \n    int leader(int u) {\n        while(par[u]\
    \ != u) {\n            u = par[u];\n        }\n        return u;\n    }\n    \n\
    \    bool same(int a, int b) {\n        return leader(a) == leader(b);\n    }\n\
    \n    int update(int v) {\n        while(1) {\n            if(rch[v] != -1) {\n\
    \                lv[v] = min(lv[lch[v]], lv[rch[v]]) + 1;\n                acc[v]\
    \ = op(A[v], op(acc[lch[v]], acc[rch[v]]));\n            }\n            else if(lch[v]\
    \ != -1) {\n                lv[v] = 0;\n                acc[v] = op(A[v], acc[lch[v]]);\n\
    \            }\n            else {\n                lv[v] = 0;\n             \
    \   acc[v] = A[v];\n            }\n            if(v == par[v]) break;\n      \
    \      v = par[v];\n        }\n        return v;\n    }\n\n    \n    bool merge(int\
    \ a, int b) {\n        a = leader(a), b = leader(b);\n    \n        if(max(rank[a],\
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
    \ doc/value_dsu.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/value_dsu.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/value_dsu.test.cpp
documentation_of: Datastructure/value_dsu.hpp
layout: document
redirect_from:
- /library/Datastructure/value_dsu.hpp
- /library/Datastructure/value_dsu.hpp.html
title: "\u5024\u96C6\u7D04\u30FB\u5909\u66F4\u53EF\u80FD\u306Adsu"
---
## 概要
ACLのdsuをundo可能にし、更に機能を幾らか追加した。かつ、値の集約・変更をつけた。
詳しい: https://trap.jp/post/2251/

## コンストラクタ
dsu d(n)
- **計算量**
    $O(n)$

## 関数

- **merge(int u, int v)**...辺(u, v)を追加する。u, vが非連結だった場合true,そうでなければfalseを返す。
    - **制約**
    $0 \le u, v < n$
    - **計算量**
    $O(\log^2 n)$

- **merge(int u, int v)**...頂点u, vが連結かどうかを返す。
    - **制約**
    $0 \le u, v < n$
    - **計算量**
    $O(\log^2 n)$

- **leader(int u)**...頂点uの属する連結成分の代表元を返す
    - **制約**
    $0 \le u < n$
    - **計算量**
    $O(\log^2 n)$

- **set(int u, ll f)** ... a[u] = op(a[u], f)。**代入である！**
    - **制約**
    $0 \le u < n$
    - **計算量**
    $O(\log^2 n)$

- **get(int u)** ... uが属する連結成分の頂点の値をopで集約した結果を返す
   - **制約**
    $0 \le u < n$
    - **計算量**
    $O(\log^2 n)$

- **size(int u)**...頂点uの属する連結成分のサイズを返す
    - **計算量**
    $O(\log^2 n)$

- **groups()**...グラフを連結成分ごとに分け、その情報を返す
    - **計算量**
    $O(n \log^2 n)$
    - **備考**
    groupsで帰ってきた配列のサイズ = 連結成分の個数
 
- **edgecnt(int u)** ... 頂点uの属する連結成分が持つ辺の本数を返す
    - **計算量**
    $O(\log^2 n)$

- **componentcnt()** ... {0, ... , n-1}について、連結成分の個数を返す
    - **計算量**
    $O(1)$

## このデータ構造が想定している状況
値の集約について: <br>

演算に逆元がある場合・値の変更が無い場合: 通常のundo可能dsuで良い <br>


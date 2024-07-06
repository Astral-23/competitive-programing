---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dsu.test.cpp
    title: verify/dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/dsu.md
    document_title: dsu
    links: []
  bundledCode: "#line 1 \"Datastructure/dsu.hpp\"\nstruct dsu {\n    using vi = vector<int>;\
    \   \n    using vvi = vector<vector<int>>;\n    vi par, sz, es;\n    int cc;\n\
    \n    dsu(int n) {\n        par = vi(n);\n        sz = vi(n, 1);\n        es =\
    \ vi(n, 0);\n        cc = n;\n        iota(all(par), 0);\n    }\n  \n    int leader(int\
    \ u) {\n        if (par[u] != u) {\n            return par[u] = leader(par[u]);\n\
    \        }    \n         return u;\n    }\n    \n    bool same(int a, int b) {\n\
    \        return leader(a) == leader(b);\n    }\n    \n    bool merge(int a, int\
    \ b) {\n        a = leader(a), b = leader(b);\n        if(sz[a] < sz[b]) swap(a,\
    \ b);\n\n        if(a == b) {\n            ++es[a];\n            return false;\n\
    \        }\n        else {\n            cc--;\n            par[b] = leader(a);\n\
    \            sz[a] += sz[b];\n            es[a] += es[b] + 1;\n            return\
    \ true;\n        }\n    }\n\n    //\u4EE5\u4E0B\u3001\u5FC5\u8981\u306A\u7269\u3092\
    \u66F8\u304F\n\n    int size(int u) {\n        return sz[leader(u)];\n    }\n\n\
    \    \n    int componentcnt() {\n        return cc;\n    }\n    \n    int edgecnt(int\
    \ u) {\n        return es[leader(u)];\n    }\n\n    vvi groups() {\n        int\
    \ n = par.size();\n        vvi ms(n);\n        rep(v, 0, n) {\n            ms[leader(v)].push_back(v);\n\
    \        }\n\n        vvi res;\n        rep(i, 0, n) if(ms[i].size() > 0) {\n\
    \            res.push_back(ms[i]);\n        }\n\n        return res;\n    }\n\n\
    };\n\n/*\n@brief dsu\n@docs doc/dsu.md\n*/\n"
  code: "struct dsu {\n    using vi = vector<int>;   \n    using vvi = vector<vector<int>>;\n\
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
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/dsu.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dsu.test.cpp
documentation_of: Datastructure/dsu.hpp
layout: document
redirect_from:
- /library/Datastructure/dsu.hpp
- /library/Datastructure/dsu.hpp.html
title: dsu
---
## 概要
ACLのdsuに、いつくかの関数を追加した（実装はACLから取っていない）
参考 : https://github.com/atcoder/ac-library

## 省略できるもの
edgecnt, componentcnt, groupsは必要が無いなら省略して良いです。
## コンストラクタ
dsu d(n)
- **計算量**
    $O(n)$

## 関数

- **merge(int u, int v)**...辺(u, v)を追加する。u, vが非連結だった場合true,そうでなければfalseを返す。
    - **制約**
    $0 \le u, v < n$

- **same(int u, int v)**...頂点u, vが連結かどうかを返す。
    - **制約**
    $0 \le u, v < n$

- **leader(int u)**...頂点uの属する連結成分の代表元を返す
    - **制約**
    $0 \le u < n$

- **size(int u)**...頂点uの属する連結成分のサイズを返す
    - **計算量**
    $O(1)$

- **groups()**...グラフを連結成分ごとに分け、その情報を返す
    - **計算量**
    $O(n)$
    - **備考**
    groupsで帰ってきた配列のサイズ = 連結成分の個数
 
- **edgecnt(int u)** ... 頂点uの属する連結成分が持つ辺の本数を返す
    - **計算量**
    $O(\alpha (n))$

- **componentcnt()** ... {0, ... , n-1}について、連結成分の個数を返す
    - **計算量**
    $O(1)$

## verify
edgecnt ... https://atcoder.jp/contests/chokudai_S002/submissions/53940535

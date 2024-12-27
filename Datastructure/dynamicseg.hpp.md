---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dynamicseg.test.cpp
    title: verify/dynamicseg.test.cpp
  - icon: ':x:'
    path: verify/point_add_rec_sum.test.cpp
    title: verify/point_add_rec_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: doc/dynamicseg.md
    document_title: "\u52D5\u7684\u30BB\u30B0\u6728"
    links: []
  bundledCode: "#line 1 \"Datastructure/dynamicseg.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)(), class W> struct dynamicsegtree {\n    W  min_pos;\n    W  max_pos;\n\
    \    dynamicsegtree(){} \n    dynamicsegtree(W l, W r) :  min_pos(l), max_pos(r)\
    \ {};\n\n    private:\n        struct Node {\n            W p;\n            S\
    \ x;\n            S prod;\n            Node* l;\n            Node* r;\n      \
    \  \n            Node(W pos, S v) : p(pos), x(v), prod(v) {\n                l\
    \ = nullptr;\n                r = nullptr;\n            }\n        };\n      \
    \  using np = Node*;\n        \n        np root = nullptr;\n\n        S val(np\
    \ v) {\n            return v != nullptr ? v -> prod : e(); \n        }\n\n   \
    \     np apply(np v, W p, S &s, W L, W R) {\n            if(!v) {\n          \
    \      v = new Node(p, s);\n                return v;\n            }\n       \
    \     if(v-> p == p) {\n                v -> x = s;\n                v -> prod\
    \ = op(val(v -> l), op(v -> x, val(v -> r)));\n                return v;\n   \
    \         }\n            \n            W M = (L + R) >> 1;\n\n            if(p\
    \ < M) {\n                if(v -> p < p) swap(p, v -> p), swap(s, v -> x);\n \
    \               v -> l = apply(v -> l, p, s,  L, M);\n            }\n        \
    \    else {\n                if(v -> p > p) swap(p, v -> p), swap(s, v -> x);\n\
    \                v -> r = apply(v -> r, p, s, M, R);\n            }\n        \
    \    v -> prod = op(val(v -> l), op(v -> x, val(v -> r)));\n            return\
    \ v; \n        }\n\n        S query(np v, W l, W r, W L, W R) {\n            if(r\
    \ <= L || R <= l) return e();\n            if(!v) return e();\n            if(l\
    \ <= L && R <= r) return v -> prod;\n\n            W M = (L + R) >> 1;\n     \
    \       S res = query(v -> l, l, r, L, M);\n            if(l <= v -> p && v ->\
    \ p < r) res = op(res, v -> x);\n            return op(res, query(v -> r, l, r,\
    \ M, R));\n        }\n\n    public:\n        void set(W pos, S s) {\n        \
    \   root = apply(root, pos, s, min_pos, max_pos);\n        }\n\n        S  prod(W\
    \ l, W r) {\n            return query(root, l, r, min_pos, max_pos);\n       \
    \ }\n\n};\n\n/*\n    @brief \u52D5\u7684\u30BB\u30B0\u6728\n    @docs doc/dynamicseg.md\n\
    \        \n*/\n"
  code: "template <class S, S (*op)(S, S), S (*e)(), class W> struct dynamicsegtree\
    \ {\n    W  min_pos;\n    W  max_pos;\n    dynamicsegtree(){} \n    dynamicsegtree(W\
    \ l, W r) :  min_pos(l), max_pos(r) {};\n\n    private:\n        struct Node {\n\
    \            W p;\n            S x;\n            S prod;\n            Node* l;\n\
    \            Node* r;\n        \n            Node(W pos, S v) : p(pos), x(v),\
    \ prod(v) {\n                l = nullptr;\n                r = nullptr;\n    \
    \        }\n        };\n        using np = Node*;\n        \n        np root =\
    \ nullptr;\n\n        S val(np v) {\n            return v != nullptr ? v -> prod\
    \ : e(); \n        }\n\n        np apply(np v, W p, S &s, W L, W R) {\n      \
    \      if(!v) {\n                v = new Node(p, s);\n                return v;\n\
    \            }\n            if(v-> p == p) {\n                v -> x = s;\n  \
    \              v -> prod = op(val(v -> l), op(v -> x, val(v -> r)));\n       \
    \         return v;\n            }\n            \n            W M = (L + R) >>\
    \ 1;\n\n            if(p < M) {\n                if(v -> p < p) swap(p, v -> p),\
    \ swap(s, v -> x);\n                v -> l = apply(v -> l, p, s,  L, M);\n   \
    \         }\n            else {\n                if(v -> p > p) swap(p, v -> p),\
    \ swap(s, v -> x);\n                v -> r = apply(v -> r, p, s, M, R);\n    \
    \        }\n            v -> prod = op(val(v -> l), op(v -> x, val(v -> r)));\n\
    \            return v; \n        }\n\n        S query(np v, W l, W r, W L, W R)\
    \ {\n            if(r <= L || R <= l) return e();\n            if(!v) return e();\n\
    \            if(l <= L && R <= r) return v -> prod;\n\n            W M = (L +\
    \ R) >> 1;\n            S res = query(v -> l, l, r, L, M);\n            if(l <=\
    \ v -> p && v -> p < r) res = op(res, v -> x);\n            return op(res, query(v\
    \ -> r, l, r, M, R));\n        }\n\n    public:\n        void set(W pos, S s)\
    \ {\n           root = apply(root, pos, s, min_pos, max_pos);\n        }\n\n \
    \       S  prod(W l, W r) {\n            return query(root, l, r, min_pos, max_pos);\n\
    \        }\n\n};\n\n/*\n    @brief \u52D5\u7684\u30BB\u30B0\u6728\n    @docs doc/dynamicseg.md\n\
    \        \n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/dynamicseg.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/point_add_rec_sum.test.cpp
  - verify/dynamicseg.test.cpp
documentation_of: Datastructure/dynamicseg.hpp
layout: document
redirect_from:
- /library/Datastructure/dynamicseg.hpp
- /library/Datastructure/dynamicseg.hpp.html
title: "\u52D5\u7684\u30BB\u30B0\u6728"
---
## 概要
区間の幅の制限を無くしたセグ木。max_right, min_leftは存在しない。および、配列による初期化はできない。
これが必要になった場合、恐らく座標圧縮すれば解ける。

参考 : https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
参考 : https://kazuma8128.hatenablog.com/

## コンストラクタ
**dynamicsegtree\<S, op, e, W\> seg(min_pos, max_pos)**... [min_pos, max_pos)に収まる範囲のクエリに対応できるセグ木を構成する。Wは、区間の値を持つ型である。(long long推奨)

## 関数
- **set(int p, S x)**...a[p]にxを代入
- **prod(int l, int r)**...[l, r)の演算結果を返す


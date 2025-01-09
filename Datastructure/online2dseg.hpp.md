---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_point_add_rec_sum.test.cpp
    title: verify/Datastructure_point_add_rec_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/2dseg.md
    document_title: "\u5DE8\u5927\u306A\u30B0\u30EA\u30C3\u30C9\u3078\u306E1\u70B9\
      \u52A0\u7B97\u30FB\u77E9\u5F62\u548C"
    links: []
  bundledCode: "#line 1 \"Datastructure/online2dseg.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)(), class W> struct online2dseg {\n\n    W minh, maxh, minw, maxw;\n\
    \    online2dseg(W sy, W ty, W sx, W tx) : minh(sy), maxh(ty), minw(sx), maxw(tx)\
    \ {};\n\n    private:\n        struct Node {\n            dynamicsegtree<S, op,\
    \ e, W> st;\n            Node* l;\n            Node* r;\n            \n      \
    \      Node(W L, W R) {\n              st = dynamicsegtree<S, op, e, W>(L, R);\n\
    \              l = nullptr;\n              r = nullptr;\n            }\n     \
    \   };\n\n        using np = Node*;\n\n        Node* root = nullptr;\n\n     \
    \   np apply(np v, W h, W w, S &s, W L, W R) {\n            if(!v) v = new Node(minw,\
    \ maxw);\n            v -> st.set(w, op(v -> st.prod(w, w+1),  s));\n\n      \
    \      if(R - L == 1) return v;\n            \n            W M = (L + R) >> 1;\n\
    \            if(h < M) v -> l = apply(v -> l, h, w, s, L, M);\n            else\
    \ v -> r = apply(v -> r, h, w, s, M, R);\n            return v;\n        }\n\n\
    \        S query(np v, W sy, W ty, W sx, W tx, W L, W R) {\n            if(R <=\
    \ sy || ty <= L) return e();\n            if(!v) return e();\n            if(sy\
    \ <= L && R <= ty) return v -> st.prod(sx, tx);\n\n            W M = (L + R) >>\
    \ 1;\n            S l = query(v -> l, sy, ty, sx, tx, L, M);\n            S r\
    \ = query(v -> r, sy, ty, sx, tx, M, R);\n            return op(l, r);\n     \
    \   }\n        \n    public:\n        void apply(W y, W x, S s) {\n          \
    \  root = apply(root, y, x, s, minh, maxh);\n            return;\n        }\n\n\
    \        S prod(W sy, W ty, W sx, W tx) {\n            return query(root, sy,\
    \ ty, sx, tx, minh, maxh);\n        }\n\n        \n};\n\n\n/*\n@docs doc/2dseg.md\n\
    @brief \u5DE8\u5927\u306A\u30B0\u30EA\u30C3\u30C9\u3078\u306E1\u70B9\u52A0\u7B97\
    \u30FB\u77E9\u5F62\u548C\n*/\n"
  code: "template <class S, S (*op)(S, S), S (*e)(), class W> struct online2dseg {\n\
    \n    W minh, maxh, minw, maxw;\n    online2dseg(W sy, W ty, W sx, W tx) : minh(sy),\
    \ maxh(ty), minw(sx), maxw(tx) {};\n\n    private:\n        struct Node {\n  \
    \          dynamicsegtree<S, op, e, W> st;\n            Node* l;\n           \
    \ Node* r;\n            \n            Node(W L, W R) {\n              st = dynamicsegtree<S,\
    \ op, e, W>(L, R);\n              l = nullptr;\n              r = nullptr;\n \
    \           }\n        };\n\n        using np = Node*;\n\n        Node* root =\
    \ nullptr;\n\n        np apply(np v, W h, W w, S &s, W L, W R) {\n           \
    \ if(!v) v = new Node(minw, maxw);\n            v -> st.set(w, op(v -> st.prod(w,\
    \ w+1),  s));\n\n            if(R - L == 1) return v;\n            \n        \
    \    W M = (L + R) >> 1;\n            if(h < M) v -> l = apply(v -> l, h, w, s,\
    \ L, M);\n            else v -> r = apply(v -> r, h, w, s, M, R);\n          \
    \  return v;\n        }\n\n        S query(np v, W sy, W ty, W sx, W tx, W L,\
    \ W R) {\n            if(R <= sy || ty <= L) return e();\n            if(!v) return\
    \ e();\n            if(sy <= L && R <= ty) return v -> st.prod(sx, tx);\n\n  \
    \          W M = (L + R) >> 1;\n            S l = query(v -> l, sy, ty, sx, tx,\
    \ L, M);\n            S r = query(v -> r, sy, ty, sx, tx, M, R);\n           \
    \ return op(l, r);\n        }\n        \n    public:\n        void apply(W y,\
    \ W x, S s) {\n            root = apply(root, y, x, s, minh, maxh);\n        \
    \    return;\n        }\n\n        S prod(W sy, W ty, W sx, W tx) {\n        \
    \    return query(root, sy, ty, sx, tx, minh, maxh);\n        }\n\n        \n\
    };\n\n\n/*\n@docs doc/2dseg.md\n@brief \u5DE8\u5927\u306A\u30B0\u30EA\u30C3\u30C9\
    \u3078\u306E1\u70B9\u52A0\u7B97\u30FB\u77E9\u5F62\u548C\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/online2dseg.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Datastructure_point_add_rec_sum.test.cpp
documentation_of: Datastructure/online2dseg.hpp
layout: document
redirect_from:
- /library/Datastructure/online2dseg.hpp
- /library/Datastructure/online2dseg.hpp.html
title: "\u5DE8\u5927\u306A\u30B0\u30EA\u30C3\u30C9\u3078\u306E1\u70B9\u52A0\u7B97\u30FB\
  \u77E9\u5F62\u548C"
---
## 概要
使ってはいけない


## 関数
- **apply(W, y, W, x, S s)** ... seg[y][x] -> op(s, seg[y][x])  
    - 罠
    opが加算の時以外使わない方が無難です
- **prod(W sy, W ty, W sx, W tx)**...[sy, ty) [sx, tx)の演算結果を返す


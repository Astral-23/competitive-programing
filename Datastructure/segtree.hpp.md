---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/hld.test.cpp
    title: verify/hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/mo.test.cpp
    title: verify/mo.test.cpp
  - icon: ':x:'
    path: verify/seg_prod.test.cpp
    title: verify/seg_prod.test.cpp
  - icon: ':x:'
    path: verify/segtree.test.cpp
    title: verify/segtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: doc/segtree.md
    document_title: segtree
    links: []
  bundledCode: "#line 1 \"Datastructure/segtree.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\n    int n;\n    int sz;\n    vector<S> d;\n\n\
    \    segtree(int n) : segtree(vector<S>(n, e())) {}\n\n    segtree(const vector<S>\
    \ &v) : n((int)v.size()), sz(1) {\n        while(sz < n) sz <<= 1;\n        d.resize(2*sz,\
    \ e());\n        rep(i, 0, n) {\n            d[sz+i] = v[i];\n        }\n    \
    \    rrep(i, 1, sz) d[i] = op(d[i<<1], d[i<<1|1]);\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < n);\n        p += sz;\n        d[p]\
    \ = x;\n        while(p > 1) {\n            p >>= 1;\n            d[p] = op(d[p<<1],\
    \ d[p<<1|1]);\n        }\n    }\n\n    S get(int p) const {\n        assert(0\
    \ <= p && p < n);\n        return d[p + sz];\n    }\n\n    S prod(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        S sml = e(), smr\
    \ = e();\n        l += sz;\n        r += sz;\n\n        while (l < r) {\n    \
    \        if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template\
    \ <class F> int max_right(int l, F f) const {\n        assert(0 <= l && l <= n);\n\
    \        assert(f(e()));\n        if (l == n) return n;\n        l += sz;\n  \
    \      S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n  \
    \          if (!f(op(sm, d[l]))) {\n                while (l < sz) {\n       \
    \             l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n     \
    \                   sm = op(sm, d[l]);\n                        l++;\n       \
    \             }\n                }\n                return l - sz;\n         \
    \   }\n            sm = op(sm, d[l]);\n            l++;\n        } while ((l &\
    \ -l) != l);\n        return n;\n    }\n\n    template <class F> int min_left(int\
    \ r, F f) const {\n        assert(0 <= r && r <= n);\n        assert(f(e()));\n\
    \        if (r == 0) return 0;\n        r += sz;\n        S sm = e();\n      \
    \  do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n   \
    \         if (!f(op(d[r], sm))) {\n                while (r < sz) {\n        \
    \            r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n  \
    \                      sm = op(d[r], sm);\n                        r--;\n    \
    \                }\n                }\n                return r + 1 - sz;\n  \
    \          }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n    \n};\n/*\n@brief segtree\n@docs doc/segtree.md\n\
    */\n"
  code: "template <class S, S (*op)(S, S), S (*e)()> struct segtree {\n    int n;\n\
    \    int sz;\n    vector<S> d;\n\n    segtree(int n) : segtree(vector<S>(n, e()))\
    \ {}\n\n    segtree(const vector<S> &v) : n((int)v.size()), sz(1) {\n        while(sz\
    \ < n) sz <<= 1;\n        d.resize(2*sz, e());\n        rep(i, 0, n) {\n     \
    \       d[sz+i] = v[i];\n        }\n        rrep(i, 1, sz) d[i] = op(d[i<<1],\
    \ d[i<<1|1]);\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p\
    \ < n);\n        p += sz;\n        d[p] = x;\n        while(p > 1) {\n       \
    \     p >>= 1;\n            d[p] = op(d[p<<1], d[p<<1|1]);\n        }\n    }\n\
    \n    S get(int p) const {\n        assert(0 <= p && p < n);\n        return d[p\
    \ + sz];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        S sml = e(), smr = e();\n        l += sz;\n    \
    \    r += sz;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <class F> int max_right(int\
    \ l, F f) const {\n        assert(0 <= l && l <= n);\n        assert(f(e()));\n\
    \        if (l == n) return n;\n        l += sz;\n        S sm = e();\n      \
    \  do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l])))\
    \ {\n                while (l < sz) {\n                    l = (2 * l);\n    \
    \                if (f(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - sz;\n            }\n            sm = op(sm, d[l]);\n \
    \           l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\
    \n    template <class F> int min_left(int r, F f) const {\n        assert(0 <=\
    \ r && r <= n);\n        assert(f(e()));\n        if (r == 0) return 0;\n    \
    \    r += sz;\n        S sm = e();\n        do {\n            r--;\n         \
    \   while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n \
    \               while (r < sz) {\n                    r = (2 * r + 1);\n     \
    \               if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n    \n};\n\
    /*\n@brief segtree\n@docs doc/segtree.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/segtree.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/segtree.test.cpp
  - verify/seg_prod.test.cpp
  - verify/mo.test.cpp
  - verify/hld.test.cpp
documentation_of: Datastructure/segtree.hpp
layout: document
redirect_from:
- /library/Datastructure/segtree.hpp
- /library/Datastructure/segtree.hpp.html
title: segtree
---
## 概要
ACL の segtreeと同じ
参考 : https://github.com/atcoder/ac-library

## 省略できるもの
max_right, min_leftの実装は他の機能と独立であり、省略できます。

## 関数
- **set(int p, S x)**...a[p]にxを代入
- **prod(int l, int r)**...[l, r)の演算結果を返す
- **get(int p)**...a[p]を返す
- **all_prod()** ...op(a[0], ... ,a[n-1])を返す
- **max\_right\<F\>(int l, F f)** ... fが単調ならば、f(op(a[l], ... , a[r-1])) = true となる最大のr
<br>
特に、
<br>
(1) f(op(a[l])) = falseの場合 ... lを返す
<br>
(2) f(op(a[l], ... , a[n-1])) = falseの場合 ... nを返す
    
    - **制約**
    ・ f(e()) = true
    ・$0 \le l \le n$
    
- **min\_left\<F\>(int r, F f)** ... fが単調ならば、f(op(a[l], ... , a[**r-1**]))がtrueとなる最小のl
<br>
特に、
<br>
(1) f(op(a[r-1])) = falseの場合 ... rを返す
<br>
(2) f(op(a[0], ... , a[r-1])) = trueの場合... 0を返す
    - **制約**
    ・ f(e()) = true
    ・$0 \le r \le n$
    

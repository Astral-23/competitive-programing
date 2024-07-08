---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lazyseg_bina.test.cpp
    title: verify/lazyseg_bina.test.cpp
  - icon: ':x:'
    path: verify/lazysegtree.test.cpp
    title: verify/lazysegtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: doc/lazysegtree.md
    document_title: lazysegtree
    links: []
  bundledCode: "#line 1 \"Datastructure/lazysegtree.hpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)(), class F, S (*mp)(F, S), F (*cm)(F, F), F (*id)()>\nstruct lazysegtree\
    \ {\n    int n;\n    int sz;\n    int log;\n    vec<S> d;\n    vec<F> lz;\n  \
    \  lazysegtree(int n) : lazysegtree(vec<S>(n, e())) {}\n    lazysegtree(const\
    \ vec<S> &v) : n((int)(v.size())) {\n        log = 1;\n        while((1 << log)\
    \ < n) log++;\n        sz = 1 << log;\n        d.resize(2*sz, e());\n        lz.resize(2*sz,\
    \ id());\n        rep(i, 0, n) d[sz+i] = v[i];\n        rrep(i, 1, sz) update(i);\n\
    \    }\n\n    void update(int i) {\n        d[i] = op(d[i<<1], d[i<<1|1]);\n \
    \   }\n\n    void all_apply(int i, F f) {\n        d[i] = mp(f, d[i]);\n     \
    \   if(i < sz) lz[i] = cm(f, lz[i]);\n    }\n\n    void push(int k) {\n      \
    \  all_apply(k * 2, lz[k]);\n        all_apply(k * 2 + 1, lz[k]);\n        lz[k]\
    \ = id();\n    }\n\n    S prod(int l, int r, int k = 1, int L = 0, int R = -1)\
    \ {\n        if(R == -1) R = sz;\n        if(r <= L || R <= l) return e();\n \
    \       if(l <= L && R <= r) return d[k];\n        push(k);\n        int M = (L\
    \ + R) / 2;\n        return op(prod(l, r, k * 2, L, M), prod(l, r, k * 2 + 1,\
    \ M, R));\n    }\n\n    void apply(int l, int r, F f, int k = 1, int L = 0, int\
    \ R = -1) {\n        if(R == -1) R = sz;\n        if(r <= L || R <= l) return;\n\
    \        if(l <= L && R <= r) {\n            all_apply(k, f);\n            return;\n\
    \        }\n        push(k);\n        int M = (L + R) / 2;\n        apply(l, r,\
    \ f, k * 2, L, M); apply(l, r, f, k * 2 + 1, M, R);\n        update(k);\n    }\n\
    \    \n    //\u4EE5\u4E0B\u3001\u5FC5\u8981\u306B\u306A\u3063\u305F\u3089\u66F8\
    \u304F\uFF08\u5168\u3066\u72EC\u7ACB)\n\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= n);\n        assert(g(e()));\n    \
    \    if (l == n) return n;\n        l += sz;\n        for (int i = log; i >= 1;\
    \ i--) push(l >> i);\n        S sm = e();\n        do {\n            while (l\
    \ % 2 == 0) l >>= 1;\n            if (!g(op(sm, d[l]))) {\n                while\
    \ (l < sz) {\n                    push(l);\n                    l = (2 * l);\n\
    \                    if (g(op(sm, d[l]))) {\n                        sm = op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - sz;\n            }\n            sm = op(sm, d[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\
    \n   \n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= n);\n        assert(g(e()));\n        if (r == 0) return 0;\n    \
    \    r += sz;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n  \
    \      S sm = e();\n        do {\n            r--;\n            while (r > 1 &&\
    \ (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < sz) {\n                    push(r);\n                    r = (2 * r + 1);\n\
    \                    if (g(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n\n    void\
    \ set(int p, S x) {\n        assert(0 <= p && p < n);\n        p += sz;\n    \
    \    rrep(i, 1, log+1) push(p >> i);\n        d[p] = x;\n        rep(i, 1, log+1)\
    \ update(p >> i);\n    }\n\n    S all_prod() { return d[1]; }\n\n    S get(int\
    \ p) {\n        assert(0 <= p && p < n);\n        p += sz;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    void apply(int\
    \ p, F f) {\n        assert(0 <= p && p < n);\n        p += sz;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n    \
    \    for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    \n};\n    \n\
    /*\n@brief lazysegtree\n@docs doc/lazysegtree.md\n*/\n"
  code: "template<class S, S (*op)(S, S), S (*e)(), class F, S (*mp)(F, S), F (*cm)(F,\
    \ F), F (*id)()>\nstruct lazysegtree {\n    int n;\n    int sz;\n    int log;\n\
    \    vec<S> d;\n    vec<F> lz;\n    lazysegtree(int n) : lazysegtree(vec<S>(n,\
    \ e())) {}\n    lazysegtree(const vec<S> &v) : n((int)(v.size())) {\n        log\
    \ = 1;\n        while((1 << log) < n) log++;\n        sz = 1 << log;\n       \
    \ d.resize(2*sz, e());\n        lz.resize(2*sz, id());\n        rep(i, 0, n) d[sz+i]\
    \ = v[i];\n        rrep(i, 1, sz) update(i);\n    }\n\n    void update(int i)\
    \ {\n        d[i] = op(d[i<<1], d[i<<1|1]);\n    }\n\n    void all_apply(int i,\
    \ F f) {\n        d[i] = mp(f, d[i]);\n        if(i < sz) lz[i] = cm(f, lz[i]);\n\
    \    }\n\n    void push(int k) {\n        all_apply(k * 2, lz[k]);\n        all_apply(k\
    \ * 2 + 1, lz[k]);\n        lz[k] = id();\n    }\n\n    S prod(int l, int r, int\
    \ k = 1, int L = 0, int R = -1) {\n        if(R == -1) R = sz;\n        if(r <=\
    \ L || R <= l) return e();\n        if(l <= L && R <= r) return d[k];\n      \
    \  push(k);\n        int M = (L + R) / 2;\n        return op(prod(l, r, k * 2,\
    \ L, M), prod(l, r, k * 2 + 1, M, R));\n    }\n\n    void apply(int l, int r,\
    \ F f, int k = 1, int L = 0, int R = -1) {\n        if(R == -1) R = sz;\n    \
    \    if(r <= L || R <= l) return;\n        if(l <= L && R <= r) {\n          \
    \  all_apply(k, f);\n            return;\n        }\n        push(k);\n      \
    \  int M = (L + R) / 2;\n        apply(l, r, f, k * 2, L, M); apply(l, r, f, k\
    \ * 2 + 1, M, R);\n        update(k);\n    }\n    \n    //\u4EE5\u4E0B\u3001\u5FC5\
    \u8981\u306B\u306A\u3063\u305F\u3089\u66F8\u304F\uFF08\u5168\u3066\u72EC\u7ACB\
    )\n\n    template <class G> int max_right(int l, G g) {\n        assert(0 <= l\
    \ && l <= n);\n        assert(g(e()));\n        if (l == n) return n;\n      \
    \  l += sz;\n        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm\
    \ = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n            if\
    \ (!g(op(sm, d[l]))) {\n                while (l < sz) {\n                   \
    \ push(l);\n                    l = (2 * l);\n                    if (g(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - sz;\n            }\n            sm = op(sm, d[l]);\n            l++;\n   \
    \     } while ((l & -l) != l);\n        return n;\n    }\n\n   \n    template\
    \ <class G> int min_left(int r, G g) {\n        assert(0 <= r && r <= n);\n  \
    \      assert(g(e()));\n        if (r == 0) return 0;\n        r += sz;\n    \
    \    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!g(op(d[r], sm))) {\n                while (r < sz) {\n     \
    \               push(r);\n                    r = (2 * r + 1);\n             \
    \       if (g(op(d[r], sm))) {\n                        sm = op(d[r], sm);\n \
    \                       r--;\n                    }\n                }\n     \
    \           return r + 1 - sz;\n            }\n            sm = op(d[r], sm);\n\
    \        } while ((r & -r) != r);\n        return 0;\n    }\n\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < n);\n        p += sz;\n        rrep(i,\
    \ 1, log+1) push(p >> i);\n        d[p] = x;\n        rep(i, 1, log+1) update(p\
    \ >> i);\n    }\n\n    S all_prod() { return d[1]; }\n\n    S get(int p) {\n \
    \       assert(0 <= p && p < n);\n        p += sz;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    void apply(int\
    \ p, F f) {\n        assert(0 <= p && p < n);\n        p += sz;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n    \
    \    for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    \n};\n    \n\
    /*\n@brief lazysegtree\n@docs doc/lazysegtree.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/lazysegtree.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/lazyseg_bina.test.cpp
  - verify/lazysegtree.test.cpp
documentation_of: Datastructure/lazysegtree.hpp
layout: document
redirect_from:
- /library/Datastructure/lazysegtree.hpp
- /library/Datastructure/lazysegtree.hpp.html
title: lazysegtree
---
## 概要
ACL の lazysegtreeと同じ
参考 : https://github.com/atcoder/ac-library

## 省略できるもの
max_right, min_leftの実装は他の機能と独立であり、省略できます。

## 関数
- **set(int p, S x)**...a[p]にxを代入
- **prod(int l, int r)**...[l, r)の演算結果を返す
- **get(int p)**...a[p]を返す
- **all_prod()** ...op(a[0], ... , a[n-1])を返す
- **apply(int l, int r, F f)**... i = l...r-1 について a[i] = f(a[i])
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
    

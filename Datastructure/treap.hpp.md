---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_treap.test.cpp
    title: verify/Datastructure_treap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/treap.md
    document_title: treap
    links: []
  bundledCode: "#line 1 \"Datastructure/treap.hpp\"\nclass xorshift {\n    uint64_t\
    \ x;\n    public:\n        xorshift() {\n            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n        uint64_t random() {\n \
    \           x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n    }\n};\n\
    \n\ntemplate<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F\
    \ (*composition)(F, F), F (*id)()>\nstruct treap {\n    xorshift rnd;\n    int\
    \ sz = 0; \n    private:\n        struct node_t{\n            node_t* lch;\n \
    \           node_t* rch;\n            int pri, cnt;\n            S val, acc;\n\
    \            F lazy;\n            bool rev;\n            bool have_e;\n \n   \
    \         node_t(S v, int p) : val(v), pri(p), acc(v) , lch(nullptr), rch(nullptr),\
    \ rev(false), cnt(1) {\n                lch = rch = nullptr;\n               \
    \ rev = false;\n                have_e = false;\n                lazy = id();\n\
    \            }\n        };\n\n        using np = node_t*;\n\n        np root =\
    \ nullptr;\n\n        long long count(np t) {return !t ? 0 : t -> cnt;}\n    \
    \    \n        S acc(np t) {return !t ? e() : t -> acc; }\n\n        np pushup(np\
    \ t) {\n            if(t) {\n                t -> cnt = count(t -> lch) + count(t\
    \ -> rch) + 1;\n                t -> acc = op(op(acc(t -> lch), t -> val),  acc(t\
    \ -> rch));\n            }\n            return t;\n        }\n \n        void\
    \ pushdown(node_t *t) {\n            if(t && t -> rev) {\n                swap(t\
    \ -> lch, t -> rch);\n                if(t -> lch) t -> lch -> rev ^= 1;\n   \
    \             if(t -> rch) t -> rch -> rev ^= 1;\n                t -> rev = false;\n\
    \            }\n\n            if(t && t -> have_e) {\n                if(t ->\
    \ lch) {\n                    t -> lch-> lazy = composition(t -> lazy, t -> lch\
    \ -> lazy);\n                    t -> lch -> acc = mapping(t -> lazy, t -> lch\
    \ -> acc);\n                    t -> lch -> have_e = true;\n                }\n\
    \n                if(t -> rch) {\n                    t -> rch -> lazy = composition(t\
    \ -> lazy, t -> rch -> lazy);\n                    t -> rch -> acc = mapping(t\
    \ -> lazy, t -> rch -> acc);\n                    t -> rch -> have_e = true;\n\
    \                }\n                t -> val = mapping(t -> lazy, t -> val);\n\
    \                t -> lazy = id();\n                t -> have_e = false;\n   \
    \         }\n            pushup(t);\n        }\n \n        void merge(np& t, np\
    \ l, np r) {\n            pushdown(l), pushdown(r);\n            if(!l || !r)\
    \ t =  !l ? r : l;\n            else if(l -> pri > r -> pri) {\n             \
    \   merge(l -> rch, l -> rch, r);\n                t = l;\n            } else\
    \ {\n               merge(r -> lch, l,r -> lch);\n               t = r;\n    \
    \        }\n            pushup(t);\n        }\n\n        void split(np t, int\
    \ k, np& tl, np& tr) {// [0, k) [k, n)\n            if(!t) {\n               \
    \ tl = nullptr, tr = nullptr;\n                return;\n            }\n      \
    \      pushdown(t);\n \n            if(k <= count(t -> lch)) {\n             \
    \   split(t -> lch, k, tl, t -> lch);\n                tr = t;\n            }else\
    \ {\n                split(t -> rch, k - count(t -> lch) - 1, t -> rch, tr);\n\
    \                tl = t;\n            }\n            pushup(t);\n        }\n\n\
    \        \n        void dump__(np t, vector<S>& res) {\n            if(!t) return;\n\
    \            pushdown(t);\n            dump__(t -> lch, res);\n            res.push_back(t\
    \ -> val);\n            dump__(t -> rch, res);\n        }\n\n\n    public:\n \
    \       void insert(int p, S val) {\n            assert(0 <= p && p <= size());\n\
    \            np nw = new node_t(val, rnd.random());\n            np tl; np tr;\n\
    \            split(root, p, tl, tr);\n            merge(tl, tl, nw);\n       \
    \     merge(root, tl, tr);\n            sz++;\n        }\n\n        void push_back(S\
    \ val) {insert(size(), val);}\n \n        void erase(int p) {\n            assert(0\
    \ <= p && p < size());\n            np tl; np tm; np tr;\n            split(root,\
    \ p+1, tl, tm);\n            split(tl, p, tl, tr);\n            merge(root, tl,\
    \ tm);\n            sz--;\n        }\n\n        void pop_back() {\n          \
    \  assert(size()>0);\n            erase(size()-1);\n        }\n\n\n        S prod(int\
    \ l, int r) {\n            if(l >= r) return e();\n            assert(0 <= l &&\
    \ r <= size());\n            np tl; np tm; np tr;\n            split(root, l,\
    \ tl, tm);\n            split(tm, r-l, tm, tr);\n            S res = acc(tm);\n\
    \            merge(tm, tm, tr);\n            merge(root, tl, tm);\n          \
    \  return res;\n        }\n\n        S all_prod() {\n            assert(size()\
    \ > 0);\n            pushdown(root);\n            pushup(root);\n            return\
    \ root -> acc;\n        }\n\n        S get(int p) {\n            assert(0 <= p\
    \ && p < size());\n            return prod(p, p+1);\n        }\n\n        void\
    \ apply(int p, F f) {apply(p, p+1, f);}\n\n        void apply(int l, int r, F\
    \ f) {\n            if(l >= r) return;\n            assert(0 <= l && r <= size());\n\
    \            np tl; np tm; np tr;\n            split(root, l, tl, tm);\n     \
    \       split(tm, r - l, tm, tr);\n            tm -> have_e = true;\n        \
    \    tm -> lazy = composition(tm -> lazy, f);\n            tm -> acc = mapping(f,\
    \ tm -> acc);\n            merge(tm, tm, tr);\n            merge(root, tl, tm);\n\
    \        }\n\n\n        void reverse(int l, int r) {//[l, r)\u3092reverse\n  \
    \          if(l >= r) return;\n            assert(0 <= l && r <= size());\n  \
    \          np tl; np tm; np tr;\n            split(root, l, tl, tm);\n       \
    \     split(tm, r - l, tm, tr);\n            tm -> rev ^= 1;\n            merge(tm,\
    \ tm, tr);\n            merge(root, tl, tm);\n        }\n \n        void rotate(int\
    \ l, int m, int r) {//[l, r) \u3092 m\u304C\u5148\u982D\u306B\u6765\u308B\u69D8\
    \u306Breverse\n            if(l >= r) return;\n            assert(l <= m && m\
    \ < r);\n            assert(0 <= l && r <= size());\n            reverse(l, r);\n\
    \            reverse(l, l + r - m);\n            reverse(l + r - m, r);\n    \
    \    }\n      \n        vector<S> dump() {\n            vector<S> res;\n     \
    \       dump__(root, res);\n            return res;\n        }\n\n        int\
    \ size() {\n            return sz;\n        }\n \n};\n/*\n@brief treap\n@docs\
    \ doc/treap.md\n*/\n"
  code: "class xorshift {\n    uint64_t x;\n    public:\n        xorshift() {\n  \
    \          mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n        uint64_t random() {\n \
    \           x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n    }\n};\n\
    \n\ntemplate<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F\
    \ (*composition)(F, F), F (*id)()>\nstruct treap {\n    xorshift rnd;\n    int\
    \ sz = 0; \n    private:\n        struct node_t{\n            node_t* lch;\n \
    \           node_t* rch;\n            int pri, cnt;\n            S val, acc;\n\
    \            F lazy;\n            bool rev;\n            bool have_e;\n \n   \
    \         node_t(S v, int p) : val(v), pri(p), acc(v) , lch(nullptr), rch(nullptr),\
    \ rev(false), cnt(1) {\n                lch = rch = nullptr;\n               \
    \ rev = false;\n                have_e = false;\n                lazy = id();\n\
    \            }\n        };\n\n        using np = node_t*;\n\n        np root =\
    \ nullptr;\n\n        long long count(np t) {return !t ? 0 : t -> cnt;}\n    \
    \    \n        S acc(np t) {return !t ? e() : t -> acc; }\n\n        np pushup(np\
    \ t) {\n            if(t) {\n                t -> cnt = count(t -> lch) + count(t\
    \ -> rch) + 1;\n                t -> acc = op(op(acc(t -> lch), t -> val),  acc(t\
    \ -> rch));\n            }\n            return t;\n        }\n \n        void\
    \ pushdown(node_t *t) {\n            if(t && t -> rev) {\n                swap(t\
    \ -> lch, t -> rch);\n                if(t -> lch) t -> lch -> rev ^= 1;\n   \
    \             if(t -> rch) t -> rch -> rev ^= 1;\n                t -> rev = false;\n\
    \            }\n\n            if(t && t -> have_e) {\n                if(t ->\
    \ lch) {\n                    t -> lch-> lazy = composition(t -> lazy, t -> lch\
    \ -> lazy);\n                    t -> lch -> acc = mapping(t -> lazy, t -> lch\
    \ -> acc);\n                    t -> lch -> have_e = true;\n                }\n\
    \n                if(t -> rch) {\n                    t -> rch -> lazy = composition(t\
    \ -> lazy, t -> rch -> lazy);\n                    t -> rch -> acc = mapping(t\
    \ -> lazy, t -> rch -> acc);\n                    t -> rch -> have_e = true;\n\
    \                }\n                t -> val = mapping(t -> lazy, t -> val);\n\
    \                t -> lazy = id();\n                t -> have_e = false;\n   \
    \         }\n            pushup(t);\n        }\n \n        void merge(np& t, np\
    \ l, np r) {\n            pushdown(l), pushdown(r);\n            if(!l || !r)\
    \ t =  !l ? r : l;\n            else if(l -> pri > r -> pri) {\n             \
    \   merge(l -> rch, l -> rch, r);\n                t = l;\n            } else\
    \ {\n               merge(r -> lch, l,r -> lch);\n               t = r;\n    \
    \        }\n            pushup(t);\n        }\n\n        void split(np t, int\
    \ k, np& tl, np& tr) {// [0, k) [k, n)\n            if(!t) {\n               \
    \ tl = nullptr, tr = nullptr;\n                return;\n            }\n      \
    \      pushdown(t);\n \n            if(k <= count(t -> lch)) {\n             \
    \   split(t -> lch, k, tl, t -> lch);\n                tr = t;\n            }else\
    \ {\n                split(t -> rch, k - count(t -> lch) - 1, t -> rch, tr);\n\
    \                tl = t;\n            }\n            pushup(t);\n        }\n\n\
    \        \n        void dump__(np t, vector<S>& res) {\n            if(!t) return;\n\
    \            pushdown(t);\n            dump__(t -> lch, res);\n            res.push_back(t\
    \ -> val);\n            dump__(t -> rch, res);\n        }\n\n\n    public:\n \
    \       void insert(int p, S val) {\n            assert(0 <= p && p <= size());\n\
    \            np nw = new node_t(val, rnd.random());\n            np tl; np tr;\n\
    \            split(root, p, tl, tr);\n            merge(tl, tl, nw);\n       \
    \     merge(root, tl, tr);\n            sz++;\n        }\n\n        void push_back(S\
    \ val) {insert(size(), val);}\n \n        void erase(int p) {\n            assert(0\
    \ <= p && p < size());\n            np tl; np tm; np tr;\n            split(root,\
    \ p+1, tl, tm);\n            split(tl, p, tl, tr);\n            merge(root, tl,\
    \ tm);\n            sz--;\n        }\n\n        void pop_back() {\n          \
    \  assert(size()>0);\n            erase(size()-1);\n        }\n\n\n        S prod(int\
    \ l, int r) {\n            if(l >= r) return e();\n            assert(0 <= l &&\
    \ r <= size());\n            np tl; np tm; np tr;\n            split(root, l,\
    \ tl, tm);\n            split(tm, r-l, tm, tr);\n            S res = acc(tm);\n\
    \            merge(tm, tm, tr);\n            merge(root, tl, tm);\n          \
    \  return res;\n        }\n\n        S all_prod() {\n            assert(size()\
    \ > 0);\n            pushdown(root);\n            pushup(root);\n            return\
    \ root -> acc;\n        }\n\n        S get(int p) {\n            assert(0 <= p\
    \ && p < size());\n            return prod(p, p+1);\n        }\n\n        void\
    \ apply(int p, F f) {apply(p, p+1, f);}\n\n        void apply(int l, int r, F\
    \ f) {\n            if(l >= r) return;\n            assert(0 <= l && r <= size());\n\
    \            np tl; np tm; np tr;\n            split(root, l, tl, tm);\n     \
    \       split(tm, r - l, tm, tr);\n            tm -> have_e = true;\n        \
    \    tm -> lazy = composition(tm -> lazy, f);\n            tm -> acc = mapping(f,\
    \ tm -> acc);\n            merge(tm, tm, tr);\n            merge(root, tl, tm);\n\
    \        }\n\n\n        void reverse(int l, int r) {//[l, r)\u3092reverse\n  \
    \          if(l >= r) return;\n            assert(0 <= l && r <= size());\n  \
    \          np tl; np tm; np tr;\n            split(root, l, tl, tm);\n       \
    \     split(tm, r - l, tm, tr);\n            tm -> rev ^= 1;\n            merge(tm,\
    \ tm, tr);\n            merge(root, tl, tm);\n        }\n \n        void rotate(int\
    \ l, int m, int r) {//[l, r) \u3092 m\u304C\u5148\u982D\u306B\u6765\u308B\u69D8\
    \u306Breverse\n            if(l >= r) return;\n            assert(l <= m && m\
    \ < r);\n            assert(0 <= l && r <= size());\n            reverse(l, r);\n\
    \            reverse(l, l + r - m);\n            reverse(l + r - m, r);\n    \
    \    }\n      \n        vector<S> dump() {\n            vector<S> res;\n     \
    \       dump__(root, res);\n            return res;\n        }\n\n        int\
    \ size() {\n            return sz;\n        }\n \n};\n/*\n@brief treap\n@docs\
    \ doc/treap.md\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/treap.hpp
  requiredBy: []
  timestamp: '2024-08-06 18:45:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Datastructure_treap.test.cpp
documentation_of: Datastructure/treap.hpp
layout: document
redirect_from:
- /library/Datastructure/treap.hpp
- /library/Datastructure/treap.hpp.html
title: treap
---
## 概要
擬似配列と呼ばれるもの
<br>
用途: reverseやrotateが可能になった遅延セグ木。ただし、max_right及びmin_leftはない。
<br>
使用感: 動的な配列

参考 : https://xuzijian629.hatenablog.com/entry/2019/10/25/234938
参考 : https://www.slideshare.net/slideshow/2-12188757/12188757

## コンストラクタ
**treap\<S, op, e, F, mapping, composition, id\>** tr;
- **計算量**
    $O(1)$

## 関数
以降、insertされて残っている要素数をnと置く。特に注釈の無い限りにおいて、計算量は$O(\log n)$である。
- **insert(int p, S x)**...p番目に値xを挿入 
    - **制約**
    $0 \le p \le n$

- **push_back(S x)**...末尾に値xを挿入。insert(n, x)と等価

- **erase(int p, S x)** ... p番目を削除
    - **制約**
    $0 \le p < n$

- **pop_back()** ... n-1番目を削除。erase(n-1)と等価
    - **制約**
    $0 < n$

- **prod(int l, int r)**...op(a[l], ... , a[r-1])を返す
 
- **all_prod()** ...op(a[0], ... , a[n-1])を返す
    - **計算量**
    $O(1)$

- **get(int p)**...a[p]を返す
    - **制約**
    $0 \le p < n$

- **apply(int p, F f)** ... a[p] = f(a[p])

- **apply(int l, int r, F f)**... i = l...r-1 について a[i] = f(a[i])

- **reverse(int l, int r)** ... {a[l], a[l+1], ... , a[r-1]}を {a[r-1], a[r-2], ... , a[l]}の順に並び替える
    
    - **制約**
        - $0 \le l$
        - $r \le n$

- **rotate(int l, int m, int r)** ... {a[l], ..., a[m], ..., a[r-1]}を {a[m], ... , a[r-1], a[l], ..., a[m-1]}の順に並び替える
    - **備考**
    配列の区間移動の目的にも使える
    
    - **制約**
        - $l \le m < r$
        - $0 \le l$
        - $r \le n$

- **size()**...今ある要素の個数を返す
    - **計算量**
    $O(1)$
    
- **dump()**... 配列{a[0], a[1] , ..., a[n-1]}を返す
    - **計算量**
    $O(n)$

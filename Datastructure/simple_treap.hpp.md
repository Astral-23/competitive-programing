---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: example/simple_treap.example.cpp
    title: example/simple_treap.example.cpp
  - icon: ':warning:'
    path: "\u7802\u5834/simple_treap.henkou.cpp"
    title: "\u7802\u5834/simple_treap.henkou.cpp"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/simpletreap.test.cpp
    title: verify/simpletreap.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: doc/simpletreap.md
    document_title: "\u5024\u306E\u96C6\u7D04\u3092\u3057\u306A\u3044treap"
    links: []
  bundledCode: "#line 1 \"Datastructure/simple_treap.hpp\"\n\nclass xorshift {\n \
    \   uint64_t x;\n    public:\n        xorshift() {\n            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n        uint64_t random() {\n \
    \           x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n    }\n};\n\
    \n\ntemplate<class S>\nstruct treap {\n    xorshift rnd;\n    int sz = 0;\n  \
    \  private:\n        struct node_t{\n            node_t* lch;\n            node_t*\
    \ rch;\n            int pri, cnt;\n            S val;\n            bool rev;\n\
    \ \n            node_t(S v, int p) : pri(p), cnt(1), val(v) {\n              \
    \  lch = rch = nullptr;\n                rev = false;\n            }\n       \
    \ };\n\n        using np = node_t*;\n\n        np root = nullptr;\n\n        int\
    \ count(node_t* t) {return !t ? 0 : t -> cnt;}\n\n        node_t* pushup(node_t*\
    \ t) {\n           if(t) t -> cnt = count(t -> lch) + count(t -> rch) + 1;\n \
    \           return t;\n        }\n\n        void pushdown(node_t *t) {\n     \
    \       if(t && t -> rev) {\n                swap(t -> lch, t -> rch);\n     \
    \           if(t -> lch) t -> lch -> rev ^= 1;\n                if(t -> rch) t\
    \ -> rch -> rev ^= 1;\n                t -> rev = false;\n            }\n    \
    \        pushup(t);\n        }\n \n        void merge(np& t, np l, np r) {\n \
    \           pushdown(l), pushdown(r);\n            if(!l || !r) t =  !l ? r :\
    \ l;\n            else if(l -> pri > r -> pri) {\n                merge(l -> rch,\
    \ l -> rch, r);\n                t = l;\n            } else {\n              \
    \ merge(r -> lch, l,r -> lch);\n               t = r;\n            }\n       \
    \     pushup(t);\n        }\n\n        void split(np t, int k, np& tl, np& tr)\
    \ {// [0, k) [k, n)\n            if(!t) {\n                tl = nullptr, tr =\
    \ nullptr;\n                return;\n            }\n            pushdown(t);\n\
    \ \n            if(k <= count(t -> lch)) {\n                split(t -> lch, k,\
    \ tl, t -> lch);\n                tr = t;\n            }else {\n             \
    \   split(t -> rch, k - count(t -> lch) - 1, t -> rch, tr);\n                tl\
    \ = t;\n            }\n            pushup(t);\n        }\n\n        np pthptr(np\
    \ t, int p) {\n            pushdown(t);\n            int c = count(t->lch), b\
    \ = (p > c);\n            if(p==c)return t;\n            if(b) return pthptr(t\
    \ -> rch, p - (c+1));\n            else return pthptr(t -> lch, p);\n        }\n\
    \n        \n        void dump__(np t, vector<S>& res) {\n            if(!t) return;\n\
    \            pushdown(t);\n            dump__(t -> lch, res);\n            res.push_back(t\
    \ -> val);\n            dump__(t -> rch, res);\n        }\n\n\n    public:\n\n\
    \        treap() {}\n        treap(int n, S val = S()) {resize(n, val);}\n\n \
    \       const S& operator[](const int &p) const {\n            assert(0 <= p &&\
    \ p < sz);\n            return pthptr(root, p) -> val;\n        }\n\n        S&\
    \ operator[](const int &p) {\n            assert(0 <= p && p < sz);\n        \
    \    return pthptr(root, p) -> val;\n        }\n\n    \n        void insert(int\
    \ p, S val) {\n            assert(0 <= p && p <= sz);\n            np nw = new\
    \ node_t(val, rnd.random());\n            np tl; np tr;\n            split(root,\
    \ p, tl, tr);\n            merge(tl, tl, nw);\n            merge(root, tl, tr);\n\
    \            sz++;\n        }\n \n        void erase(int p) {\n            assert(0\
    \ <= p && p < sz);\n            np tl; np tm; np tr;\n            split(root,\
    \ p+1, tl, tm);\n            split(tl, p, tl, tr);\n            merge(root, tl,\
    \ tm);\n            sz--;\n        }\n\n        void push_back(S val) {insert(sz,\
    \ val);}\n\n        void pop_back() {\n            assert(sz>0);\n           \
    \ erase(sz-1);\n        }\n\n        void reverse(int l, int r) {//[l, r)\u3092\
    reverse\n            if(l >= r) return;\n            assert(0 <= l && r <= sz);\n\
    \            np tl; np tm; np tr;\n            split(root, l, tl, tm);\n     \
    \       split(tm, r - l, tm, tr);\n            tm -> rev ^= 1;\n            merge(tm,\
    \ tm, tr);\n            merge(root, tl, tm);\n        }\n \n        void rotate(int\
    \ l, int m, int r) {//[l, r) \u3092 m\u304C\u5148\u982D\u306B\u6765\u308B\u69D8\
    \u306Breverse\n            if(l >= r) return;\n            assert(l <= m && m\
    \ < r);\n            assert(0 <= l && r <= sz);\n            reverse(l, r);\n\
    \            reverse(l, l + r - m);\n            reverse(l + r - m, r);\n    \
    \    }\n      \n        vector<S> dump() {\n            vector<S> res;\n     \
    \       dump__(root, res);\n            return res;\n        }\n\n        int\
    \ size() {\n            return sz;\n        }\n\n        void resize(int n, S\
    \ val = S()) {\n            while(n > sz) push_back(val);\n            while(n\
    \ < sz) pop_back();\n        }\n \n};\n/*\n@brief \u5024\u306E\u96C6\u7D04\u3092\
    \u3057\u306A\u3044treap\n@docs doc/simpletreap.md\n*/\n"
  code: "\nclass xorshift {\n    uint64_t x;\n    public:\n        xorshift() {\n\
    \            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n        uint64_t random() {\n \
    \           x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n    }\n};\n\
    \n\ntemplate<class S>\nstruct treap {\n    xorshift rnd;\n    int sz = 0;\n  \
    \  private:\n        struct node_t{\n            node_t* lch;\n            node_t*\
    \ rch;\n            int pri, cnt;\n            S val;\n            bool rev;\n\
    \ \n            node_t(S v, int p) : pri(p), cnt(1), val(v) {\n              \
    \  lch = rch = nullptr;\n                rev = false;\n            }\n       \
    \ };\n\n        using np = node_t*;\n\n        np root = nullptr;\n\n        int\
    \ count(node_t* t) {return !t ? 0 : t -> cnt;}\n\n        node_t* pushup(node_t*\
    \ t) {\n           if(t) t -> cnt = count(t -> lch) + count(t -> rch) + 1;\n \
    \           return t;\n        }\n\n        void pushdown(node_t *t) {\n     \
    \       if(t && t -> rev) {\n                swap(t -> lch, t -> rch);\n     \
    \           if(t -> lch) t -> lch -> rev ^= 1;\n                if(t -> rch) t\
    \ -> rch -> rev ^= 1;\n                t -> rev = false;\n            }\n    \
    \        pushup(t);\n        }\n \n        void merge(np& t, np l, np r) {\n \
    \           pushdown(l), pushdown(r);\n            if(!l || !r) t =  !l ? r :\
    \ l;\n            else if(l -> pri > r -> pri) {\n                merge(l -> rch,\
    \ l -> rch, r);\n                t = l;\n            } else {\n              \
    \ merge(r -> lch, l,r -> lch);\n               t = r;\n            }\n       \
    \     pushup(t);\n        }\n\n        void split(np t, int k, np& tl, np& tr)\
    \ {// [0, k) [k, n)\n            if(!t) {\n                tl = nullptr, tr =\
    \ nullptr;\n                return;\n            }\n            pushdown(t);\n\
    \ \n            if(k <= count(t -> lch)) {\n                split(t -> lch, k,\
    \ tl, t -> lch);\n                tr = t;\n            }else {\n             \
    \   split(t -> rch, k - count(t -> lch) - 1, t -> rch, tr);\n                tl\
    \ = t;\n            }\n            pushup(t);\n        }\n\n        np pthptr(np\
    \ t, int p) {\n            pushdown(t);\n            int c = count(t->lch), b\
    \ = (p > c);\n            if(p==c)return t;\n            if(b) return pthptr(t\
    \ -> rch, p - (c+1));\n            else return pthptr(t -> lch, p);\n        }\n\
    \n        \n        void dump__(np t, vector<S>& res) {\n            if(!t) return;\n\
    \            pushdown(t);\n            dump__(t -> lch, res);\n            res.push_back(t\
    \ -> val);\n            dump__(t -> rch, res);\n        }\n\n\n    public:\n\n\
    \        treap() {}\n        treap(int n, S val = S()) {resize(n, val);}\n\n \
    \       const S& operator[](const int &p) const {\n            assert(0 <= p &&\
    \ p < sz);\n            return pthptr(root, p) -> val;\n        }\n\n        S&\
    \ operator[](const int &p) {\n            assert(0 <= p && p < sz);\n        \
    \    return pthptr(root, p) -> val;\n        }\n\n    \n        void insert(int\
    \ p, S val) {\n            assert(0 <= p && p <= sz);\n            np nw = new\
    \ node_t(val, rnd.random());\n            np tl; np tr;\n            split(root,\
    \ p, tl, tr);\n            merge(tl, tl, nw);\n            merge(root, tl, tr);\n\
    \            sz++;\n        }\n \n        void erase(int p) {\n            assert(0\
    \ <= p && p < sz);\n            np tl; np tm; np tr;\n            split(root,\
    \ p+1, tl, tm);\n            split(tl, p, tl, tr);\n            merge(root, tl,\
    \ tm);\n            sz--;\n        }\n\n        void push_back(S val) {insert(sz,\
    \ val);}\n\n        void pop_back() {\n            assert(sz>0);\n           \
    \ erase(sz-1);\n        }\n\n        void reverse(int l, int r) {//[l, r)\u3092\
    reverse\n            if(l >= r) return;\n            assert(0 <= l && r <= sz);\n\
    \            np tl; np tm; np tr;\n            split(root, l, tl, tm);\n     \
    \       split(tm, r - l, tm, tr);\n            tm -> rev ^= 1;\n            merge(tm,\
    \ tm, tr);\n            merge(root, tl, tm);\n        }\n \n        void rotate(int\
    \ l, int m, int r) {//[l, r) \u3092 m\u304C\u5148\u982D\u306B\u6765\u308B\u69D8\
    \u306Breverse\n            if(l >= r) return;\n            assert(l <= m && m\
    \ < r);\n            assert(0 <= l && r <= sz);\n            reverse(l, r);\n\
    \            reverse(l, l + r - m);\n            reverse(l + r - m, r);\n    \
    \    }\n      \n        vector<S> dump() {\n            vector<S> res;\n     \
    \       dump__(root, res);\n            return res;\n        }\n\n        int\
    \ size() {\n            return sz;\n        }\n\n        void resize(int n, S\
    \ val = S()) {\n            while(n > sz) push_back(val);\n            while(n\
    \ < sz) pop_back();\n        }\n \n};\n/*\n@brief \u5024\u306E\u96C6\u7D04\u3092\
    \u3057\u306A\u3044treap\n@docs doc/simpletreap.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/simple_treap.hpp
  requiredBy:
  - example/simple_treap.example.cpp
  - "\u7802\u5834/simple_treap.henkou.cpp"
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/simpletreap.test.cpp
documentation_of: Datastructure/simple_treap.hpp
layout: document
redirect_from:
- /library/Datastructure/simple_treap.hpp
- /library/Datastructure/simple_treap.hpp.html
title: "\u5024\u306E\u96C6\u7D04\u3092\u3057\u306A\u3044treap"
---
## 概要
擬似配列と呼ばれるもの。値集約を無くし、実装と定数倍を軽くした。かつ、インターフェースを配列に近づけた。
<br>
使用感: 高速なreverseやrotateが可能になった配列。及び、範囲外参照にassertがついている。

参考 : https://xuzijian629.hatenablog.com/entry/2019/10/25/234938
参考 : https://www.slideshare.net/slideshow/2-12188757/12188757

## treapに流量できる関数
merge, split, dump,insert,push_back,erase,pop_back,reverse,rotate,dump,size
関数の名前が同じだが異なる...get

先にtreapを書いてあればそっちを使って良い。
## コンストラクタ
**treap\<S\> tr**
 **計算量**
    $O(1)$

**treap\<S\> tr(siz, default_value = S())**
サイズ = siz, 初期値 = default_valueで初期化。
**計算量** $O(siz \log siz)$

## 関数
以降、insertされて残っている要素数をnと置く。特に注釈の無い限りにおいて、計算量は $O(\log{n})$ である。
- **insert(int p, S x)**...p番目に値xを挿入。  {...,[p-1], [p], ... } → {...,[p-1], [new], [p], ... }
    - **制約**
 $0 \le p \le n$


- **push_back(S x)**...末尾に値xを挿入。insert(n, x)と等価

- **erase(int p, S x)** ... p番目を削除
    - **制約**
  $0 \le p < n$

- **pop_back()** ... n-1番目を削除。erase(n-1)と等価
    - **制約**
    $0 < n$

- **\[\]によるアクセス**...配列における\[\]によるアクセスと同様。
    - **制約**
    $0 \le p < n$

- **reverse(int l, int r)** ... {a[l], a[l+1], ... , a[r-1]}を {a[r-1], a[r-2], ... , a[l]}の順に並び替える
    - **制約**
        - $0 \le l$
        - $r \le n$

- **rotate(int l, int m, int r)** ... {a[l], ..., a[m], ..., a[r-1]}を {a[m], ... , a[r-1], a[l], ..., a[m-1]}の順に並び替える
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

- **resize(int n, S val = S())** ... 要素数を変更する。 もし n > szなら 値valを n - sz個挿入。 n < szなら sz - n回pop_back()。 n = szなら何もしない。
    - **計算量**
    $O(|n - sz| \log |n - sz|)$


## 使用例
```
#include "../Utility/template.hpp"
#include "../Datastructure/simple_treap.hpp"


int main() {
    int n = 10;
    treap<int> tr(n);

    rep(i, 0, n) tr[i] = i;
    rep(i, 0, n) cout << tr[i] << " ";
    cout << endl;
    //0 1 2 3 4 5 6 7 8 9 

    tr.reverse(1, 8);
    rep(i, 0, n) cout << tr[i] << " ";
    cout << endl;
    //0 7 6 5 4 3 2 1 8 9 

    tr.reverse(1, 8);
    // 0 1 2 3 4 5 6 7 8 9

    tr.rotate(3, 5, 8);
    rep(i, 0, n) cout << tr[i] << " ";
    cout << endl;
    //0 1 2 5 6 7 3 4 8 9 

    //cout << tr[n] << endl; assert落ち。
}
```

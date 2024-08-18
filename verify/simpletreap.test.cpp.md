---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/simple_treap.hpp
    title: "\u5024\u306E\u96C6\u7D04\u3092\u3057\u306A\u3044treap"
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/4/ITP2_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/4/ITP2_4_A
  bundledCode: "#line 1 \"verify/simpletreap.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/4/ITP2_4_A\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/simple_treap.hpp\"\
    \n\nclass xorshift {\n    uint64_t x;\n    public:\n        xorshift() {\n   \
    \         mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \u3057\u306A\u3044treap\n@docs doc/simpletreap.md\n*/\n#line 4 \"verify/simpletreap.test.cpp\"\
    \n\n\nint main() {\n    int N;\n    cin >> N;\n    treap<int> tr;\n    rep(i,\
    \ 0, N) {\n        int a;\n        cin >> a;\n        tr.push_back(a);\n    }\n\
    \n    int Q;\n    cin >> Q;\n    while(Q--) {\n        int b, e;\n        cin\
    \ >> b >> e;\n        tr.reverse(b, e);\n    }\n\n    auto res = tr.dump();\n\
    \    \n    rep(i,0,N) {\n        cout << res[i];\n        if(i != N-1) cout <<\
    \ \" \";\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/4/ITP2_4_A\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/simple_treap.hpp\"\
    \n\n\nint main() {\n    int N;\n    cin >> N;\n    treap<int> tr;\n    rep(i,\
    \ 0, N) {\n        int a;\n        cin >> a;\n        tr.push_back(a);\n    }\n\
    \n    int Q;\n    cin >> Q;\n    while(Q--) {\n        int b, e;\n        cin\
    \ >> b >> e;\n        tr.reverse(b, e);\n    }\n\n    auto res = tr.dump();\n\
    \    \n    rep(i,0,N) {\n        cout << res[i];\n        if(i != N-1) cout <<\
    \ \" \";\n    }\n    cout << endl;\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/simple_treap.hpp
  isVerificationFile: true
  path: verify/simpletreap.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/simpletreap.test.cpp
layout: document
redirect_from:
- /verify/verify/simpletreap.test.cpp
- /verify/verify/simpletreap.test.cpp.html
title: verify/simpletreap.test.cpp
---
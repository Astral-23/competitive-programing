---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/treap.hpp
    title: treap
  - icon: ':heavy_check_mark:'
    path: Utility/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"verify/Datastructure_treap.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\n#line\
    \ 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n\
    #define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x)\
    \ begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec = vector<T>;\n\
    template <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x\
    \ = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1 &x, T2 y)\
    \ {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n    io_setup()\
    \ {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n  \
    \      cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\n\n//\
    \ \u52D5\u7684mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\
    \u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate <uint32_t mod> struct\
    \ modint {\n    using mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n\
    \    TT modint(T a = 0) : x((ll(a) % mod + mod)) {\n        if (x >= mod) x -=\
    \ mod;\n    }\n\n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n\
    \        if (a.x >= mod) a.x -= mod;\n        return a;\n    }\n    friend mm\
    \ operator-(mm a, mm b) {\n        a.x -= b.x;\n        if (a.x >= mod) a.x +=\
    \ mod;\n        return a;\n    }\n\n    mm operator-() const { return mod - x;\
    \ }\n\n    //+\u3068-\u3060\u3051\u3067\u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\
    \u4E0B\u306F\u7701\u7565\u3057\u3066\u826F\u3044\u3067\u3059\u3002\n\n    friend\
    \ mm operator*(mm a, mm b) { return (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm\
    \ a, mm b) { return a * b.inv(); }\n    friend mm &operator+=(mm &a, mm b) { return\
    \ a = a + b; }\n    friend mm &operator-=(mm &a, mm b) { return a = a - b; }\n\
    \    friend mm &operator*=(mm &a, mm b) { return a = a * b; }\n    friend mm &operator/=(mm\
    \ &a, mm b) { return a = a * b.inv(); }\n\n    mm inv() const {\n        assert(x\
    \ != 0);\n        return pow(mod - 2);\n    }\n    mm pow(ll y) const {\n    \
    \    mm res = 1;\n        mm v = *this;\n        while (y) {\n            if (y\
    \ & 1) res *= v;\n            v *= v;\n            y /= 2;\n        }\n      \
    \  return res;\n    }\n\n    friend istream &operator>>(istream &is, mm &a) {\n\
    \        ll t;\n        cin >> t;\n        a = mm(t);\n        return is;\n  \
    \  }\n\n    friend ostream &operator<<(ostream &os, mm a) { return os << a.x;\
    \ }\n\n    bool operator==(mm a) { return x == a.x; }\n    bool operator!=(mm\
    \ a) { return x != a.x; }\n\n    bool operator<(const mm &a) const { return x\
    \ < a.x; }\n};\nusing modint998244353 = modint<998244353>;\nusing modint1000000007\
    \ = modint<1'000'000'007>;\n/*\n@brief modint\n*/\n#line 1 \"Datastructure/treap.hpp\"\
    \nclass xorshift {\n    uint64_t x;\n    public:\n        xorshift() {\n     \
    \       mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \ doc/treap.md\n*/\n#line 5 \"verify/Datastructure_treap.test.cpp\"\nusing mint\
    \ = modint<998244353>;\n\nstruct S {\n     mint s; int sz;\n};\n\nS op(S l, S\
    \ r) {\n    return S{l.s + r.s, l.sz + r.sz};\n}\n\nS e() {\n    return S{mint(0),\
    \ 0};\n}\n\nstruct F {\n    mint a, b;\n};\n\nS mapping(F f, S s) {\n    S res;\n\
    \    res.s = f.a * s.s + f.b * s.sz;\n    res.sz = s.sz;\n    return res;\n}\n\
    \nF composition(F l, F r) {\n    return F{l.a * r.a,  l.a * r.b + l.b};\n}\n\n\
    F id() {\n    return F{1, 0};\n}\n\n\nint main() {\n    treap<S, op, e, F, mapping,\
    \ composition, id> tr;\n    ll N, Q;\n    cin >> N >> Q;\n    for(int i = 0; i\
    \ <= N-1; i++) {\n        ll t;\n        cin >> t;\n        mint a = t;\n    \
    \    tr.push_back(S{a,1});\n    }\n\n    while(Q--) {\n        assert(tr.size()\
    \ == N);\n        int type;\n        cin >> type;\n        if(type == 0) {\n \
    \           ll i, x;\n            cin >> i >> x;\n            tr.insert(i, S{x,\
    \ 1});\n            N++;\n        }\n        else if(type==1) {\n            int\
    \ i;\n            cin >> i;\n            tr.erase(i);\n            N--;\n    \
    \    }\n        else if(type==2) {\n            ll l, r;\n            cin >> l\
    \ >> r;\n            tr.reverse(l,r);\n        }\n        else if(type==3) {\n\
    \            ll l, r;\n            mint b, c;\n            cin >> l >> r >> b\
    \ >> c;\n            tr.apply(l, r, F{b, c});\n        }\n        else {\n   \
    \         ll l, r;\n            cin >> l >> r;\n            if(l==0 && r == tr.size())\
    \ {\n                cout << tr.all_prod().s.x << \" \";\n                continue;\n\
    \            }\n            cout << tr.prod(l, r).s.x << \" \";\n        }\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\n#include\
    \ \"../Datastructure/treap.hpp\"\nusing mint = modint<998244353>;\n\nstruct S\
    \ {\n     mint s; int sz;\n};\n\nS op(S l, S r) {\n    return S{l.s + r.s, l.sz\
    \ + r.sz};\n}\n\nS e() {\n    return S{mint(0), 0};\n}\n\nstruct F {\n    mint\
    \ a, b;\n};\n\nS mapping(F f, S s) {\n    S res;\n    res.s = f.a * s.s + f.b\
    \ * s.sz;\n    res.sz = s.sz;\n    return res;\n}\n\nF composition(F l, F r) {\n\
    \    return F{l.a * r.a,  l.a * r.b + l.b};\n}\n\nF id() {\n    return F{1, 0};\n\
    }\n\n\nint main() {\n    treap<S, op, e, F, mapping, composition, id> tr;\n  \
    \  ll N, Q;\n    cin >> N >> Q;\n    for(int i = 0; i <= N-1; i++) {\n       \
    \ ll t;\n        cin >> t;\n        mint a = t;\n        tr.push_back(S{a,1});\n\
    \    }\n\n    while(Q--) {\n        assert(tr.size() == N);\n        int type;\n\
    \        cin >> type;\n        if(type == 0) {\n            ll i, x;\n       \
    \     cin >> i >> x;\n            tr.insert(i, S{x, 1});\n            N++;\n \
    \       }\n        else if(type==1) {\n            int i;\n            cin >>\
    \ i;\n            tr.erase(i);\n            N--;\n        }\n        else if(type==2)\
    \ {\n            ll l, r;\n            cin >> l >> r;\n            tr.reverse(l,r);\n\
    \        }\n        else if(type==3) {\n            ll l, r;\n            mint\
    \ b, c;\n            cin >> l >> r >> b >> c;\n            tr.apply(l, r, F{b,\
    \ c});\n        }\n        else {\n            ll l, r;\n            cin >> l\
    \ >> r;\n            if(l==0 && r == tr.size()) {\n                cout << tr.all_prod().s.x\
    \ << \" \";\n                continue;\n            }\n            cout << tr.prod(l,\
    \ r).s.x << \" \";\n        }\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Datastructure/treap.hpp
  isVerificationFile: true
  path: verify/Datastructure_treap.test.cpp
  requiredBy: []
  timestamp: '2025-01-10 00:00:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Datastructure_treap.test.cpp
layout: document
redirect_from:
- /verify/verify/Datastructure_treap.test.cpp
- /verify/verify/Datastructure_treap.test.cpp.html
title: verify/Datastructure_treap.test.cpp
---

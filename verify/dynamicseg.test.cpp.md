---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/dynamicseg.hpp
    title: "\u52D5\u7684\u30BB\u30B0\u6728"
  - icon: ':question:'
    path: Utility/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/dynamicseg.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\n\n//\u52D5\u7684mod :\
    \ template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\
    \u6570mod\u3092\u5BA3\u8A00\ntemplate<uint32_t mod>\nstruct modint{\n    using\
    \ mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n    TT modint(T a=0)\
    \ : x((ll(a) % mod + mod) % mod){}\n\n    friend mm operator+(mm a, mm b) {\n\
    \        a.x += b.x;\n        if(a.x >= mod) a.x -= mod;\n        return a;\n\
    \    }\n   friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n        if(a.x\
    \ >= mod) a.x += mod;\n        return a;\n    }\n\n    //+\u3068-\u3060\u3051\u3067\
    \u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\u7565\u3057\u3066\
    \u826F\u3044\u3067\u3059\u3002\n\n    friend mm operator*(mm a, mm b) { return\
    \ (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm a, mm b) { return a * b.inv();\
    \ }\n    friend mm& operator+=(mm& a, mm b) { return a = a + b; }\n    friend\
    \ mm& operator-=(mm& a, mm b) { return a = a - b; }\n    friend mm& operator*=(mm&\
    \ a, mm b) { return a = a * b; }\n    friend mm& operator/=(mm& a, mm b) { return\
    \ a = a * b.inv(); }\n\n    mm inv() const {return pow(mod-2);}\n    mm pow(const\
    \ ll& y) const {\n        if(!y) return 1;\n        mm res = pow(y >> 1);\n  \
    \      res *= res;\n        if(y & 1) res *= *this;\n        return res;\n   \
    \ }\n\n    friend istream& operator>>(istream &is, mm &a) { \n        ll t;\n\
    \        cin >> t;\n        a = mm(t);\n        return is;\n    }\n\n    friend\
    \ ostream& operator<<(ostream &os,  mm a) {\n        return os << a.x;\n    }\n\
    \n    bool operator==(mm a) {return x == a.x;}\n    bool operator!=(mm a) {return\
    \ x != a.x;}\n\n    //bool operator<(const mm& a) const {return x < a.x;}\n};\n\
    \nusing modint998244353 = modint<998244353>;\nusing modint1000000007 = modint<1'000'000'007>;\n\
    \n/*\n@brief modint\n*/\n#line 1 \"Datastructure/dynamicseg.hpp\"\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)(), class W> struct dynamicsegtree {\n    W  min_pos;\n\
    \    W  max_pos;\n    dynamicsegtree(){} \n    dynamicsegtree(W l, W r) :  min_pos(l),\
    \ max_pos(r) {};\n\n    private:\n        struct Node {\n            W p;\n  \
    \          S x;\n            S prod;\n            Node* l;\n            Node*\
    \ r;\n        \n            Node(W pos, S v) : p(pos), x(v), prod(v) {\n     \
    \           l = nullptr;\n                r = nullptr;\n            }\n      \
    \  };\n        using np = Node*;\n        \n        np root = nullptr;\n\n   \
    \     S val(np v) {\n            return v != nullptr ? v -> prod : e(); \n   \
    \     }\n\n        np apply(np v, W p, S &s, W L, W R) {\n            if(!v) {\n\
    \                v = new Node(p, s);\n                return v;\n            }\n\
    \            if(v-> p == p) {\n                v -> x = s;\n                v\
    \ -> prod = op(val(v -> l), op(v -> x, val(v -> r)));\n                return\
    \ v;\n            }\n            \n            W M = (L + R) >> 1;\n\n       \
    \     if(p < M) {\n                if(v -> p < p) swap(p, v -> p), swap(s, v ->\
    \ x);\n                v -> l = apply(v -> l, p, s,  L, M);\n            }\n \
    \           else {\n                if(v -> p > p) swap(p, v -> p), swap(s, v\
    \ -> x);\n                v -> r = apply(v -> r, p, s, M, R);\n            }\n\
    \            v -> prod = op(val(v -> l), op(v -> x, val(v -> r)));\n         \
    \   return v; \n        }\n\n        S query(np v, W l, W r, W L, W R) {\n   \
    \         if(r <= L || R <= l) return e();\n            if(!v) return e();\n \
    \           if(l <= L && R <= r) return v -> prod;\n\n            W M = (L + R)\
    \ >> 1;\n            S res = query(v -> l, l, r, L, M);\n            if(l <= v\
    \ -> p && v -> p < r) res = op(res, v -> x);\n            return op(res, query(v\
    \ -> r, l, r, M, R));\n        }\n\n    public:\n        void set(W pos, S s)\
    \ {\n           root = apply(root, pos, s, min_pos, max_pos);\n        }\n\n \
    \       S  prod(W l, W r) {\n            return query(root, l, r, min_pos, max_pos);\n\
    \        }\n\n};\n\n/*\n    @brief \u52D5\u7684\u30BB\u30B0\u6728\n    @docs doc/dynamicseg.md\n\
    \        \n*/\n#line 5 \"verify/dynamicseg.test.cpp\"\n//#include \"../Datastructure/segtree.hpp\"\
    \n\nusing mint = modint998244353;\n\n\nstruct S{\n    mint a, b;\n    S(){}\n\
    \    S(mint d, mint t) : a(d), b(t){}\n};\n\nS op(S l, S r) {\n\tS res;\n    res.a\
    \ = l.a * r.a;\n    res.b = r.a * l.b + r.b;\n    return res;\n}\n\nS e() {\n\t\
    return S(1, 0);\n}\n\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n    vec<ll>\
    \ A(N), B(N);\n    rep(i, 0, N) cin >> A[i] >> B[i];\n\n    dynamicsegtree<S,\
    \ op, e, int> seg(-1000000000, 1000000000);\n    //segtree<S, op, e> seg(N);\n\
    \    rep(i, 0, N) seg.set(i, S(A[i], B[i]));\n\n    while(Q--) {\n        int\
    \ t;\n        cin >> t;\n        if(t==0) {\n            int p, c, d;\n      \
    \      cin >> p >> c >> d;\n            seg.set(p, S(c, d));\n        }\n    \
    \    else {\n            int l, r, x;\n            cin >> l >> r >> x;\n     \
    \       auto [a, b] = seg.prod(l ,r);\n            cout << (x * a + b).x << '\\\
    n';\n        }\n    }\n   \n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\n#include\
    \ \"../Datastructure/dynamicseg.hpp\"\n//#include \"../Datastructure/segtree.hpp\"\
    \n\nusing mint = modint998244353;\n\n\nstruct S{\n    mint a, b;\n    S(){}\n\
    \    S(mint d, mint t) : a(d), b(t){}\n};\n\nS op(S l, S r) {\n\tS res;\n    res.a\
    \ = l.a * r.a;\n    res.b = r.a * l.b + r.b;\n    return res;\n}\n\nS e() {\n\t\
    return S(1, 0);\n}\n\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n    vec<ll>\
    \ A(N), B(N);\n    rep(i, 0, N) cin >> A[i] >> B[i];\n\n    dynamicsegtree<S,\
    \ op, e, int> seg(-1000000000, 1000000000);\n    //segtree<S, op, e> seg(N);\n\
    \    rep(i, 0, N) seg.set(i, S(A[i], B[i]));\n\n    while(Q--) {\n        int\
    \ t;\n        cin >> t;\n        if(t==0) {\n            int p, c, d;\n      \
    \      cin >> p >> c >> d;\n            seg.set(p, S(c, d));\n        }\n    \
    \    else {\n            int l, r, x;\n            cin >> l >> r >> x;\n     \
    \       auto [a, b] = seg.prod(l ,r);\n            cout << (x * a + b).x << '\\\
    n';\n        }\n    }\n   \n\n}"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Datastructure/dynamicseg.hpp
  isVerificationFile: true
  path: verify/dynamicseg.test.cpp
  requiredBy: []
  timestamp: '2024-07-29 19:50:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dynamicseg.test.cpp
layout: document
redirect_from:
- /verify/verify/dynamicseg.test.cpp
- /verify/verify/dynamicseg.test.cpp.html
title: verify/dynamicseg.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/dynamicseg.hpp
    title: "\u52D5\u7684\u30BB\u30B0\u6728"
  - icon: ':heavy_check_mark:'
    path: Datastructure/online2dseg.hpp
    title: "\u5DE8\u5927\u306A\u30B0\u30EA\u30C3\u30C9\u3078\u306E1\u70B9\u52A0\u7B97\
      \u30FB\u77E9\u5F62\u548C"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"verify/point_add_rec_sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n*/\n#line 1 \"Datastructure/dynamicseg.hpp\"\ntemplate <class S, S (*op)(S,\
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
    \        \n*/\n#line 1 \"Datastructure/online2dseg.hpp\"\ntemplate <class S, S\
    \ (*op)(S, S), S (*e)(), class W> struct online2dseg {\n\n    W minh, maxh, minw,\
    \ maxw;\n    online2dseg(W sy, W ty, W sx, W tx) : minh(sy), maxh(ty), minw(sx),\
    \ maxw(tx) {};\n\n    private:\n        struct Node {\n            dynamicsegtree<S,\
    \ op, e, W> st;\n            Node* l;\n            Node* r;\n            \n  \
    \          Node(W L, W R) {\n              st = dynamicsegtree<S, op, e, W>(L,\
    \ R);\n              l = nullptr;\n              r = nullptr;\n            }\n\
    \        };\n\n        using np = Node*;\n\n        Node* root = nullptr;\n\n\
    \        np apply(np v, W h, W w, S &s, W L, W R) {\n            if(!v) v = new\
    \ Node(minw, maxw);\n            v -> st.set(w, op(v -> st.prod(w, w+1),  s));\n\
    \n            if(R - L == 1) return v;\n            \n            W M = (L + R)\
    \ >> 1;\n            if(h < M) v -> l = apply(v -> l, h, w, s, L, M);\n      \
    \      else v -> r = apply(v -> r, h, w, s, M, R);\n            return v;\n  \
    \      }\n\n        S query(np v, W sy, W ty, W sx, W tx, W L, W R) {\n      \
    \      if(R <= sy || ty <= L) return e();\n            if(!v) return e();\n  \
    \          if(sy <= L && R <= ty) return v -> st.prod(sx, tx);\n\n           \
    \ W M = (L + R) >> 1;\n            S l = query(v -> l, sy, ty, sx, tx, L, M);\n\
    \            S r = query(v -> r, sy, ty, sx, tx, M, R);\n            return op(l,\
    \ r);\n        }\n        \n    public:\n        void apply(W y, W x, S s) {\n\
    \            root = apply(root, y, x, s, minh, maxh);\n            return;\n \
    \       }\n\n        S prod(W sy, W ty, W sx, W tx) {\n            return query(root,\
    \ sy, ty, sx, tx, minh, maxh);\n        }\n\n        \n};\n\n\n/*\n@docs doc/2dseg.md\n\
    @brief \u5DE8\u5927\u306A\u30B0\u30EA\u30C3\u30C9\u3078\u306E1\u70B9\u52A0\u7B97\
    \u30FB\u77E9\u5F62\u548C\n*/\n#line 5 \"verify/point_add_rec_sum.test.cpp\"\n\n\
    using S = ll;\nS op(S l, S r) {\n    return l + r;\n}\n\nS e() {\n    return 0LL;\n\
    }\n\nint main() {\n    ll N, Q;\n    cin >> N >> Q;\n    online2dseg<S, op, e,\
    \ int> seg(0, 1000000001, 0, 1000000001);\n    map<int, map<int, ll>> val;\n\n\
    \    rep(i, 0, N) {\n        ll x, y, w;\n        cin >> x >> y >> w;\n      \
    \  seg.apply(y, x, w);\n    }\n\n    while(Q--) {\n        int t;\n        cin\
    \ >> t;\n        if(t==0) {\n            ll x, y, w;\n            cin >> x >>\
    \ y >> w;\n            seg.apply(y, x, w);\n        }\n        else {\n      \
    \      ll l, d, r, u;\n            cin >> l >> d >> r >> u;\n            cout\
    \ << seg.prod(d, u, l, r) << '\\n';\n        }\n    }\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/dynamicseg.hpp\"\
    \n#include \"../Datastructure/online2dseg.hpp\"\n\nusing S = ll;\nS op(S l, S\
    \ r) {\n    return l + r;\n}\n\nS e() {\n    return 0LL;\n}\n\nint main() {\n\
    \    ll N, Q;\n    cin >> N >> Q;\n    online2dseg<S, op, e, int> seg(0, 1000000001,\
    \ 0, 1000000001);\n    map<int, map<int, ll>> val;\n\n    rep(i, 0, N) {\n   \
    \     ll x, y, w;\n        cin >> x >> y >> w;\n        seg.apply(y, x, w);\n\
    \    }\n\n    while(Q--) {\n        int t;\n        cin >> t;\n        if(t==0)\
    \ {\n            ll x, y, w;\n            cin >> x >> y >> w;\n            seg.apply(y,\
    \ x, w);\n        }\n        else {\n            ll l, d, r, u;\n            cin\
    \ >> l >> d >> r >> u;\n            cout << seg.prod(d, u, l, r) << '\\n';\n \
    \       }\n    }\n\n}\n"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/dynamicseg.hpp
  - Datastructure/online2dseg.hpp
  isVerificationFile: true
  path: verify/point_add_rec_sum.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/point_add_rec_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/point_add_rec_sum.test.cpp
- /verify/verify/point_add_rec_sum.test.cpp.html
title: verify/point_add_rec_sum.test.cpp
---

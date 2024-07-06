---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/2dsegtree.hpp
    title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja
  bundledCode: "#line 1 \"verify/2dsegtree_add.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n\n#define TT template<typename\
    \ T>\nTT using vec = vector<T>;\ntemplate<class T1, class T2> bool chmin(T1 &x,\
    \ T2 y) { return x > y ? (x = y, true) : false; }\ntemplate<class T1, class T2>\
    \ bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }\n\nstruct\
    \ io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n       \
    \ std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n    }\n\
    } io_setup;\n\n/*\n@brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"\
    Datastructure/2dsegtree.hpp\"\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ segtree2d {\n    int id(int y, int x) {return y * 2 * W + x;} //= y\u756A\u76EE\
    \u306E\u30BB\u30B0\u6728\u306E\u3001\u30CE\u30FC\u30C9x\u306B\u5BFE\u5FDC\u3059\
    \u308B\u6DFB\u5B57\n    int H, W;\n    vec<S> dat;\n    bool f;\n\n    segtree2d(int\
    \ h, int w) {\n        f = true;\n        H = W = 1;\n        while(H < h) H <<=\
    \ 1;\n        while(W < w) W <<= 1;\n        dat.resize(4 * H * W, e());\n   \
    \ }\n\n    void preset(int y, int x, S v) {f = false,  dat[id(y + H, x + W)] =\
    \ v; }\n\n    void build() {\n        f = true;\n        rep(h, H, 2 * H) {\n\
    \            rrep(w, 1, W) {\n                dat[id(h, w)] = op(dat[id(h, 2 *\
    \ w)], dat[id(h, 2 * w + 1)]);\n            }\n        }\n        \n        rrep(h,\
    \ 0, H) {\n            rrep(w, 1, 2 * W) {\n                dat[id(h, w)] = op(dat[id(h\
    \ * 2, w)], dat[id(h * 2 + 1, w)]);\n            } \n        }\n    }\n\n    void\
    \ set(int y, int x, S v) {\n        assert(f);\n\n        y += H, x += W;\n  \
    \      dat[id(y, x)] = v;\n        rrep(w, 1, W) {\n            dat[id(y, w)]\
    \ = op(dat[id(y, 2 * w)], dat[id(y, 2 * w + 1)]);\n        }\n\n        while(y\
    \ > 1) {\n            y >>= 1;\n            for(int j = x; j >= 1; j >>= 1) {\n\
    \                dat[id(y, j)] = op(dat[id(y * 2, j)] , dat[id(y * 2 + 1, j)]);\n\
    \            }\n        }\n    }\n\n    S inner(int h, int l, int r) {\n     \
    \   S sml = e(), smr = e();\n        l += W, r += W;\n        while(l < r) {\n\
    \            if(l & 1) sml = op(sml, dat[id(h, l++)]);\n            if(r & 1)\
    \ smr = op(dat[id(h, --r)], smr);\n            l >>= 1, r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n\n    S prod(int sy, int ty, int sx, int\
    \ tx) {\n        assert(f);\n\n        S sml = e(), smr = e();\n        sy +=\
    \ H, ty += H;\n        while(sy < ty) {\n            if(sy & 1) sml = op(sml,\
    \ inner(sy++, sx, tx));\n            if(ty & 1) smr = op(inner(--ty, sx, tx),\
    \ smr);\n            sy >>= 1, ty >>= 1;\n        }\n        return op(sml, smr);\n\
    \    }\n\n    S get(int y, int x) {\n        return dat[id(y + H, x + W)];\n \
    \   }\n};\n/*\n@brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n@docs\
    \ doc/2dseg_small.md\n*/\n#line 4 \"verify/2dsegtree_add.test.cpp\"\n\n\n\nusing\
    \ S = ll;\nS op(ll l, ll r) {\n    return l + r;\n}\n\nS e() {\n    return 0LL;\n\
    }\n\nint main() {\n    int N;\n    cin >> N;\n    int H = 1000, W = 1000;\n  \
    \  segtree2d<S, op, e> seg(H+2, W+2);\n\n    rep(i, 0, N) {\n        int sx, sy,\
    \ tx, ty;\n        cin >> sx >> sy >> tx >> ty;\n        tx--, ty--;\n       \
    \ seg.set(ty + 1, tx + 1, seg.get(ty + 1, tx + 1) + 1);\n        seg.set(sy, sx,\
    \ seg.get(sy, sx) + 1);\n        seg.set(ty + 1, sx, seg.get(ty + 1, sx) - 1);\n\
    \        seg.set(sy, tx + 1, seg.get(sy, tx + 1) - 1);\n    }\n\n    ll ans =\
    \ 0;\n    rep(i, 0, H) rep(j, 0, W) chmax(ans, seg.prod(0, i+1, 0, j+1));\n  \
    \ \n    cout << ans << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/2dsegtree.hpp\"\
    \n\n\n\nusing S = ll;\nS op(ll l, ll r) {\n    return l + r;\n}\n\nS e() {\n \
    \   return 0LL;\n}\n\nint main() {\n    int N;\n    cin >> N;\n    int H = 1000,\
    \ W = 1000;\n    segtree2d<S, op, e> seg(H+2, W+2);\n\n    rep(i, 0, N) {\n  \
    \      int sx, sy, tx, ty;\n        cin >> sx >> sy >> tx >> ty;\n        tx--,\
    \ ty--;\n        seg.set(ty + 1, tx + 1, seg.get(ty + 1, tx + 1) + 1);\n     \
    \   seg.set(sy, sx, seg.get(sy, sx) + 1);\n        seg.set(ty + 1, sx, seg.get(ty\
    \ + 1, sx) - 1);\n        seg.set(sy, tx + 1, seg.get(sy, tx + 1) - 1);\n    }\n\
    \n    ll ans = 0;\n    rep(i, 0, H) rep(j, 0, W) chmax(ans, seg.prod(0, i+1, 0,\
    \ j+1));\n   \n    cout << ans << endl;\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/2dsegtree.hpp
  isVerificationFile: true
  path: verify/2dsegtree_add.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/2dsegtree_add.test.cpp
layout: document
redirect_from:
- /verify/verify/2dsegtree_add.test.cpp
- /verify/verify/2dsegtree_add.test.cpp.html
title: verify/2dsegtree_add.test.cpp
---

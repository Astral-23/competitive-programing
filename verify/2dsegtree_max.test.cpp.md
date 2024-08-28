---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/2dsegtree.hpp
    title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/1068
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/1068
  bundledCode: "#line 1 \"verify/2dsegtree_max.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/1068\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 3 \"verify/2dsegtree_max.test.cpp\"\
    \n\n#line 1 \"Datastructure/2dsegtree.hpp\"\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()> struct segtree2d {\n    int id(int y, int x) {return y * 2 * W + x;}\
    \ //= y\u756A\u76EE\u306E\u30BB\u30B0\u6728\u306E\u3001\u30CE\u30FC\u30C9x\u306B\
    \u5BFE\u5FDC\u3059\u308B\u6DFB\u5B57\n    int H, W;\n    vec<S> dat;\n    bool\
    \ f;\n\n    segtree2d(int h, int w) {\n        f = true;\n        H = W = 1;\n\
    \        while(H < h) H <<= 1;\n        while(W < w) W <<= 1;\n        dat.resize(4\
    \ * H * W, e());\n    }\n\n    void preset(int y, int x, S v) {f = false,  dat[id(y\
    \ + H, x + W)] = v; }\n\n    void build() {\n        f = true;\n        rep(h,\
    \ H, 2 * H) {\n            rrep(w, 1, W) {\n                dat[id(h, w)] = op(dat[id(h,\
    \ 2 * w)], dat[id(h, 2 * w + 1)]);\n            }\n        }\n        \n     \
    \   rrep(h, 0, H) {\n            rrep(w, 1, 2 * W) {\n                dat[id(h,\
    \ w)] = op(dat[id(h * 2, w)], dat[id(h * 2 + 1, w)]);\n            } \n      \
    \  }\n    }\n\n    void set(int y, int x, S v) {\n        assert(f);\n\n     \
    \   y += H, x += W;\n        dat[id(y, x)] = v;\n        rrep(w, 1, W) {\n   \
    \         dat[id(y, w)] = op(dat[id(y, 2 * w)], dat[id(y, 2 * w + 1)]);\n    \
    \    }\n\n        while(y > 1) {\n            y >>= 1;\n            for(int j\
    \ = x; j >= 1; j >>= 1) {\n                dat[id(y, j)] = op(dat[id(y * 2, j)]\
    \ , dat[id(y * 2 + 1, j)]);\n            }\n        }\n    }\n\n    S inner(int\
    \ h, int l, int r) {\n        S sml = e(), smr = e();\n        l += W, r += W;\n\
    \        while(l < r) {\n            if(l & 1) sml = op(sml, dat[id(h, l++)]);\n\
    \            if(r & 1) smr = op(dat[id(h, --r)], smr);\n            l >>= 1, r\
    \ >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S prod(int sy,\
    \ int ty, int sx, int tx) {\n        assert(f);\n\n        S sml = e(), smr =\
    \ e();\n        sy += H, ty += H;\n        while(sy < ty) {\n            if(sy\
    \ & 1) sml = op(sml, inner(sy++, sx, tx));\n            if(ty & 1) smr = op(inner(--ty,\
    \ sx, tx), smr);\n            sy >>= 1, ty >>= 1;\n        }\n        return op(sml,\
    \ smr);\n    }\n\n    S get(int y, int x) {\n        return dat[id(y + H, x +\
    \ W)];\n    }\n};\n/*\n@brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n@docs doc/2dseg_small.md\n*/\n#line 5 \"verify/2dsegtree_max.test.cpp\"\n\n\
    using S = int;\nS op(S l, S r) {\n    return min(l, r);\n}\n\nS e() {\n    return\
    \ INT_MAX;\n}\n\nint main() {\n    int r, c, q;\n    while(cin >> r >> c >> q)\
    \ {\n        if(r==0) break;\n\n        vec<vec<int>> grid(r, vec<int>(c));\n\
    \        rep(i, 0, r) rep(j, 0, c) cin >> grid[i][j];\n    \n        segtree2d<S,\
    \ op, e> seg(r, c);\n        rep(i, 0, r) rep(j, 0, c) seg.preset(i, j, grid[i][j]);\n\
    \        seg.build();\n        while(q--) {\n            int sy, sx, ty, tx;\n\
    \            cin >> sy >> sx >> ty >> tx;\n            cout << seg.prod(sy, ty+1,\
    \ sx, tx+1) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/1068\"\n#include\
    \ \"../Utility/template.hpp\"\n\n#include \"../Datastructure/2dsegtree.hpp\"\n\
    \nusing S = int;\nS op(S l, S r) {\n    return min(l, r);\n}\n\nS e() {\n    return\
    \ INT_MAX;\n}\n\nint main() {\n    int r, c, q;\n    while(cin >> r >> c >> q)\
    \ {\n        if(r==0) break;\n\n        vec<vec<int>> grid(r, vec<int>(c));\n\
    \        rep(i, 0, r) rep(j, 0, c) cin >> grid[i][j];\n    \n        segtree2d<S,\
    \ op, e> seg(r, c);\n        rep(i, 0, r) rep(j, 0, c) seg.preset(i, j, grid[i][j]);\n\
    \        seg.build();\n        while(q--) {\n            int sy, sx, ty, tx;\n\
    \            cin >> sy >> sx >> ty >> tx;\n            cout << seg.prod(sy, ty+1,\
    \ sx, tx+1) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/2dsegtree.hpp
  isVerificationFile: true
  path: verify/2dsegtree_max.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/2dsegtree_max.test.cpp
layout: document
redirect_from:
- /verify/verify/2dsegtree_max.test.cpp
- /verify/verify/2dsegtree_max.test.cpp.html
title: verify/2dsegtree_max.test.cpp
---

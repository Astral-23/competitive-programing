---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/2dsegtree_add.test.cpp
    title: verify/2dsegtree_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/2dsegtree_max.test.cpp
    title: verify/2dsegtree_max.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/2dseg_small.md
    document_title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"Datastructure/2dsegtree.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree2d {\n    int id(int y, int x) {return y * 2 * W\
    \ + x;} //= y\u756A\u76EE\u306E\u30BB\u30B0\u6728\u306E\u3001\u30CE\u30FC\u30C9\
    x\u306B\u5BFE\u5FDC\u3059\u308B\u6DFB\u5B57\n    int H, W;\n    vec<S> dat;\n\
    \    bool f;\n\n    segtree2d(int h, int w) {\n        f = true;\n        H =\
    \ W = 1;\n        while(H < h) H <<= 1;\n        while(W < w) W <<= 1;\n     \
    \   dat.resize(4 * H * W, e());\n    }\n\n    void preset(int y, int x, S v) {f\
    \ = false,  dat[id(y + H, x + W)] = v; }\n\n    void build() {\n        f = true;\n\
    \        rep(h, H, 2 * H) {\n            rrep(w, 1, W) {\n                dat[id(h,\
    \ w)] = op(dat[id(h, 2 * w)], dat[id(h, 2 * w + 1)]);\n            }\n       \
    \ }\n        \n        rrep(h, 0, H) {\n            rrep(w, 1, 2 * W) {\n    \
    \            dat[id(h, w)] = op(dat[id(h * 2, w)], dat[id(h * 2 + 1, w)]);\n \
    \           } \n        }\n    }\n\n    void set(int y, int x, S v) {\n      \
    \  assert(f);\n\n        y += H, x += W;\n        dat[id(y, x)] = v;\n       \
    \ rrep(w, 1, W) {\n            dat[id(y, w)] = op(dat[id(y, 2 * w)], dat[id(y,\
    \ 2 * w + 1)]);\n        }\n\n        while(y > 1) {\n            y >>= 1;\n \
    \           for(int j = x; j >= 1; j >>= 1) {\n                dat[id(y, j)] =\
    \ op(dat[id(y * 2, j)] , dat[id(y * 2 + 1, j)]);\n            }\n        }\n \
    \   }\n\n    S inner(int h, int l, int r) {\n        S sml = e(), smr = e();\n\
    \        l += W, r += W;\n        while(l < r) {\n            if(l & 1) sml =\
    \ op(sml, dat[id(h, l++)]);\n            if(r & 1) smr = op(dat[id(h, --r)], smr);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\
    \n    S prod(int sy, int ty, int sx, int tx) {\n        assert(f);\n\n       \
    \ S sml = e(), smr = e();\n        sy += H, ty += H;\n        while(sy < ty) {\n\
    \            if(sy & 1) sml = op(sml, inner(sy++, sx, tx));\n            if(ty\
    \ & 1) smr = op(inner(--ty, sx, tx), smr);\n            sy >>= 1, ty >>= 1;\n\
    \        }\n        return op(sml, smr);\n    }\n\n    S get(int y, int x) {\n\
    \        return dat[id(y + H, x + W)];\n    }\n};\n/*\n@brief 2\u6B21\u5143\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n@docs doc/2dseg_small.md\n*/\n"
  code: "template <class S, S (*op)(S, S), S (*e)()> struct segtree2d {\n    int id(int\
    \ y, int x) {return y * 2 * W + x;} //= y\u756A\u76EE\u306E\u30BB\u30B0\u6728\u306E\
    \u3001\u30CE\u30FC\u30C9x\u306B\u5BFE\u5FDC\u3059\u308B\u6DFB\u5B57\n    int H,\
    \ W;\n    vec<S> dat;\n    bool f;\n\n    segtree2d(int h, int w) {\n        f\
    \ = true;\n        H = W = 1;\n        while(H < h) H <<= 1;\n        while(W\
    \ < w) W <<= 1;\n        dat.resize(4 * H * W, e());\n    }\n\n    void preset(int\
    \ y, int x, S v) {f = false,  dat[id(y + H, x + W)] = v; }\n\n    void build()\
    \ {\n        f = true;\n        rep(h, H, 2 * H) {\n            rrep(w, 1, W)\
    \ {\n                dat[id(h, w)] = op(dat[id(h, 2 * w)], dat[id(h, 2 * w + 1)]);\n\
    \            }\n        }\n        \n        rrep(h, 0, H) {\n            rrep(w,\
    \ 1, 2 * W) {\n                dat[id(h, w)] = op(dat[id(h * 2, w)], dat[id(h\
    \ * 2 + 1, w)]);\n            } \n        }\n    }\n\n    void set(int y, int\
    \ x, S v) {\n        assert(f);\n\n        y += H, x += W;\n        dat[id(y,\
    \ x)] = v;\n        rrep(w, 1, W) {\n            dat[id(y, w)] = op(dat[id(y,\
    \ 2 * w)], dat[id(y, 2 * w + 1)]);\n        }\n\n        while(y > 1) {\n    \
    \        y >>= 1;\n            for(int j = x; j >= 1; j >>= 1) {\n           \
    \     dat[id(y, j)] = op(dat[id(y * 2, j)] , dat[id(y * 2 + 1, j)]);\n       \
    \     }\n        }\n    }\n\n    S inner(int h, int l, int r) {\n        S sml\
    \ = e(), smr = e();\n        l += W, r += W;\n        while(l < r) {\n       \
    \     if(l & 1) sml = op(sml, dat[id(h, l++)]);\n            if(r & 1) smr = op(dat[id(h,\
    \ --r)], smr);\n            l >>= 1, r >>= 1;\n        }\n        return op(sml,\
    \ smr);\n    }\n\n    S prod(int sy, int ty, int sx, int tx) {\n        assert(f);\n\
    \n        S sml = e(), smr = e();\n        sy += H, ty += H;\n        while(sy\
    \ < ty) {\n            if(sy & 1) sml = op(sml, inner(sy++, sx, tx));\n      \
    \      if(ty & 1) smr = op(inner(--ty, sx, tx), smr);\n            sy >>= 1, ty\
    \ >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S get(int y, int\
    \ x) {\n        return dat[id(y + H, x + W)];\n    }\n};\n/*\n@brief 2\u6B21\u5143\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n@docs doc/2dseg_small.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/2dsegtree.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/2dsegtree_max.test.cpp
  - verify/2dsegtree_add.test.cpp
documentation_of: Datastructure/2dsegtree.hpp
layout: document
redirect_from:
- /library/Datastructure/2dsegtree.hpp
- /library/Datastructure/2dsegtree.hpp.html
title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
## 概要
2dセグ木

## コンストラクタ
`segtree2d<S, op, e>(int h, int w)` ...  [0, h) * [0, w)のグリッドを作る。**半開区間**
- 計算量 $O(HW)$

## 関数
- `void preset(int y, int x, S v)` ... A[y][x] = v
    - 計算量 $O(1)$
- `void build()` ... 2dセグ木を構築する。presetをしなかった場合は必要ない。
    - 計算量 $O(HW)$
- `void set(int y, int x, S v)` ... A[y][x] = v
    - 計算量 $O(\log{H} \log{W})$
    - 制約 presetをした場合、setを呼ぶ前にbuildを呼ぶ。そうでない場合、assertでbool変数 fが反応する。

- `S prod(int sy, int ty, int sx, int tx)` ... [sy, sx) * [ty, tx)の矩形領域の和を返す。**半開区間**
    - 計算量 $O(\log{H} \log{W})$
    - 制約 presetをした場合、setを呼ぶ前にbuildを呼ぶ。そうでない場合、assertでbool変数 fが反応する。

## pro tips
- 加算の時
2dBITで良い。

- imos法 累積和の取り方について
imos法について、加算場所は一意には定まらない。よって、マイナスの座標を含まないように、右上の法に加算すると都合が良い。

## 実装について
2次元配列を1次元配列に直すような実装(参考 : https://nyaannyaan.github.io/library/data-structure-2d/2d-segment-tree.hpp.html)  

1次元に直さない場合、 H = 10 ^ 6, W = 1のような極端なケースでのMLEを対策する必要が出る場合がある。参考: vector自体のメモリ使用量

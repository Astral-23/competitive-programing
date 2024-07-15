## 概要
2dセグ木

## コンストラクタ
`segtree2d<S, op, e> seg (int h, int w)` ...  [0, h) * [0, w)のグリッドを作る。**半開区間**
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

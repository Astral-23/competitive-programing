## 概要
2次元累積和

## +演算を他の演算に変えたくなった時
逆元があれば良い。
add, prod(y, x), prod(sy, sx, ty, tx) の + , - , += , -= を全て変更する。

## コンストラクタ
`template<typename T> static2dsum(int h, int w)` ... T : 値の型。 [0, h) * [0, w)の配列を作る. 初期値は0。 
- 計算量 $O(HW)$

`templatetypename T> static2dsum(static2dsum(vec<vec<T>> dat)`... ２次元配列datをコピーする
- 計算量 $O(HW)$
## 関数
基本、計算量は $O(1)$  

・1点加算/区間取得
- `void add(int y, int x, T v)` ... A[y][x] += v

- `void build()` ... 累積和を計算する。以降add不可能。また、buildを呼ぶ前はget.prod不可。(どちらも、assertが反応する) 
    - 計算量 $O(HW)$


- `T prod(int sy, int ty, int sx, int tx)` ... [sy, ty) * [sx, tx)の矩形領域の和を返す。**半開区間**


## 概要
1次元累積和

## +演算を他の演算に変えたくなった時
逆元があれば良い。
add, prod(y, x), prod(sy, sx, ty, tx) の + , - , += , -= を全て変更する。

## コンストラクタ
`template<typename T> static1dsum(int n)` ... T : 値の型。 [0, n) の配列を作る. 初期値は0
- 計算量 $O(n)$

`template<typename T> static1dsum(vec<T> dat)`... datをコピーする。
- 計算量 $O(n)$

## 関数
基本、計算量は $O(1)$  

・1点加算/区間取得
- `void add(int i, T v)` ... A[i] += v

- `void build()` ... 累積和を計算する。以降add不可能。また、buildを呼ぶ前はget.prod不可。(どちらも、assertが反応する) 
    - 計算量 $O(n)$

- `T prod(int l, int r)` ... [l, r)の範囲領域の和を返す。**半開区間**


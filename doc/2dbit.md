## 概要
2dBit
参考 : https://hos.ac/slides/20140319_bit.pdf 

## +演算を他の演算に変えたくなった時
逆元があれば良い。
add, prod(y, x), prod(sy, sx, ty, tx) の + , - , += , -= を全て変更する。

## コンストラクタ 
`bit2d<T> bit (int h, int w)` ... T : 値の型。 [0, h) * [0, w)の配列を作る. 初期値は0。 
- 計算量 $O(HW)$

## 関数
全て、計算量は $O(\log{h} \log{w})$  

・1点加算/区間取得
- `void add(int y, int x, T v)` ... A[y][x] += v
  
- `ll get(int y, int x)` ... A[y][x]を返す。
  
- `ll prod(int sy, int ty, int sx, int tx)` ... [sy, ty) * [sx, tx)の矩形領域の和を返す。**半開区間**

・区間加算/1点取得(**上の関数と併用しないこと**)
- `void imos_add(int y, int x, T v)` ... A[y][x] += v

- `void imos_add(int sy, int ty, int sx, int tx, T v)` ... [sy, ty) * [sx, tx) の区間に一様に += v。**半開区間**
  
- `ll imos_get(int y, int x, T v)` ... A[y][x]を返す。


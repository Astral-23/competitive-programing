## 概要
2dBit
参考 : https://hos.ac/slides/20140319_bit.pdf 

## +演算を他の演算に変えたくなった時
逆元があれば良い。
add, prod(y, x), prod(sy, sx, ty, tx) の + , - , += , -= を全て変更する。
**計算量$O(HW)$**
## コンストラクタ
**bit2d\<T\> bit (int h, int w)** ... T : 値の型。 [0, h) * [0, w)の配列を作る. 初期値は0。 計算量 $O(HW)$

## 関数
全て、計算量は $O(\log{h} \log{w})$
・1点加算/区間取得
- **add(int y, int x, T v)** ... A[y][x] += v
- **get(int y, int x)** ... A[y][x]を返す。
- **prod(int sy, int ty, int sx, int tx)** ... [sy, ty) * [sx, tx)の矩形領域の和を返す。**半開区間**

・区間加算/1点取得(**上の関数と併用しないこと**)
- **imos_add(int y, int x, T v)** ... A[y][x] += v
- **imos_add(int sy, int ty, int sx, int tx, T v)** ... [sy, ty) * [sx, tx) の区間に一様に += v。**半開区間**
- **imos_get(int y, int x, T v)** ... A[y][x]を返す。


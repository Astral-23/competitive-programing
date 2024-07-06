## 概要
ACL の segtreeと同じ
参考 : https://github.com/atcoder/ac-library

## 省略できるもの
max_right, min_leftの実装は他の機能と独立であり、省略できます。

## 関数
- **set(int p, S x)**...a[p]にxを代入
- **prod(int l, int r)**...[l, r)の演算結果を返す
- **get(int p)**...a[p]を返す
- **all_prod()** ...op(a[0], ... ,a[n-1])を返す
- **max\_right\<F\>(int l, F f)** ... fが単調ならば、f(op(a[l], ... , a[r-1])) = true となる最大のr
<br>
特に、
<br>
(1) f(op(a[l])) = falseの場合 ... lを返す
<br>
(2) f(op(a[l], ... , a[n-1])) = falseの場合 ... nを返す
    
    - **制約**
    ・ f(e()) = true
    ・$0 \le l \le n$
    
- **min\_left\<F\>(int r, F f)** ... fが単調ならば、f(op(a[l], ... , a[**r-1**]))がtrueとなる最小のl
<br>
特に、
<br>
(1) f(op(a[r-1])) = falseの場合 ... rを返す
<br>
(2) f(op(a[0], ... , a[r-1])) = trueの場合... 0を返す
    - **制約**
    ・ f(e()) = true
    ・$0 \le r \le n$
    

## 概要
擬似配列と呼ばれるもの
<br>
用途: reverseやrotateが可能になった遅延セグ木。ただし、max_right及びmin_leftはない。
<br>
使用感: 動的な配列

参考 : https://xuzijian629.hatenablog.com/entry/2019/10/25/234938
参考 : https://www.slideshare.net/slideshow/2-12188757/12188757

## コンストラクタ
**treap\<S, op, e, F, mapping, composition, id\>** tr;
- **計算量**
    $O(1)$

## 関数
以降、insertされて残っている要素数をnと置く。特に注釈の無い限りにおいて、計算量は$O(\log n)$である。
- **insert(int p, S x)**...p番目に値xを挿入 
    - **制約**
    $0 \le p \le n$

- **push_back(S x)**...末尾に値xを挿入。insert(n, x)と等価

- **erase(int p, S x)** ... p番目を削除
    - **制約**
    $0 \le p < n$

- **pop_back()** ... n-1番目を削除。erase(n-1)と等価
    - **制約**
    $0 < n$

- **prod(int l, int r)**...op(a[l], ... , a[r-1])を返す
 
- **all_prod()** ...op(a[0], ... , a[n-1])を返す
    - **計算量**
    $O(1)$

- **get(int p)**...a[p]を返す
    - **制約**
    $0 \le p < n$

- **apply(int p, F f)** ... a[p] = f(a[p])

- **apply(int l, int r, F f)**... i = l...r-1 について a[i] = f(a[i])

- **reverse(int l, int r)** ... {a[l], a[l+1], ... , a[r-1]}を {a[r-1], a[r-2], ... , a[l]}の順に並び替える
    
    - **制約**
        - $0 \le l$
        - $r \le n$

- **rotate(int l, int m, int r)** ... {a[l], ..., a[m], ..., a[r-1]}を {a[m], ... , a[r-1], a[l], ..., a[m-1]}の順に並び替える
    - **備考**
    配列の区間移動の目的にも使える
    
    - **制約**
        - $l \le m < r$
        - $0 \le l$
        - $r \le n$

- **size()**...今ある要素の個数を返す
    - **計算量**
    $O(1)$
    
- **dump()**... 配列{a[0], a[1] , ..., a[n-1]}を返す
    - **計算量**
    $O(n)$

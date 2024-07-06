## 概要
擬似配列と呼ばれるもの。値集約を無くし、実装と定数倍を軽くした。かつ、インターフェースを配列に近づけた。
<br>
使用感: 高速なreverseやrotateが可能になった配列。及び、範囲外参照にassertがついている。

参考 : https://xuzijian629.hatenablog.com/entry/2019/10/25/234938
参考 : https://www.slideshare.net/slideshow/2-12188757/12188757

## treapに流量できる関数
merge, split, dump,insert,push_back,erase,pop_back,reverse,rotate,dump,size
関数の名前が同じだが異なる...get

先にtreapを書いてあればそっちを使って良い。
## コンストラクタ
**treap\<S\> tr**
 **計算量**
    $O(1)$

**treap\<S\> tr(siz, default_value = S())**
サイズ = siz, 初期値 = default_valueで初期化。
**計算量** $O(siz \log siz)$

## 関数
以降、insertされて残っている要素数をnと置く。特に注釈の無い限りにおいて、計算量は $O(\log{n})$ である。
- **insert(int p, S x)**...p番目に値xを挿入。  {...,[p-1], [p], ... } → {...,[p-1], [new], [p], ... }
    - **制約**
 $0 \le p \le n$


- **push_back(S x)**...末尾に値xを挿入。insert(n, x)と等価

- **erase(int p, S x)** ... p番目を削除
    - **制約**
  $0 \le p < n$

- **pop_back()** ... n-1番目を削除。erase(n-1)と等価
    - **制約**
    $0 < n$

- **\[\]によるアクセス**...配列における\[\]によるアクセスと同様。
    - **制約**
    $0 \le p < n$

- **reverse(int l, int r)** ... {a[l], a[l+1], ... , a[r-1]}を {a[r-1], a[r-2], ... , a[l]}の順に並び替える
    - **制約**
        - $0 \le l$
        - $r \le n$

- **rotate(int l, int m, int r)** ... {a[l], ..., a[m], ..., a[r-1]}を {a[m], ... , a[r-1], a[l], ..., a[m-1]}の順に並び替える
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

- **resize(int n, S val = S())** ... 要素数を変更する。 もし n > szなら 値valを n - sz個挿入。 n < szなら sz - n回pop_back()。 n = szなら何もしない。
    - **計算量**
    $O(|n - sz| \log |n - sz|)$


## 使用例
```
#include "../Utility/template.hpp"
#include "../Datastructure/simple_treap.hpp"


int main() {
    int n = 10;
    treap<int> tr(n);

    rep(i, 0, n) tr[i] = i;
    rep(i, 0, n) cout << tr[i] << " ";
    cout << endl;
    //0 1 2 3 4 5 6 7 8 9 

    tr.reverse(1, 8);
    rep(i, 0, n) cout << tr[i] << " ";
    cout << endl;
    //0 7 6 5 4 3 2 1 8 9 

    tr.reverse(1, 8);
    // 0 1 2 3 4 5 6 7 8 9

    tr.rotate(3, 5, 8);
    rep(i, 0, n) cout << tr[i] << " ";
    cout << endl;
    //0 1 2 5 6 7 3 4 8 9 

    //cout << tr[n] << endl; assert落ち。
}
```

## 概要
ACLのdsuに、いつくかの関数を追加した（実装はACLから取っていない）
参考 : https://github.com/atcoder/ac-library

## 省略できるもの
edgecnt, componentcnt, groupsは必要が無いなら省略して良いです。
## コンストラクタ
dsu d(n)
- **計算量**
    $O(n)$

## 関数

- **merge(int u, int v)**...辺(u, v)を追加する。u, vが非連結だった場合true,そうでなければfalseを返す。
    - **制約**
    $0 \le u, v < n$

- **same(int u, int v)**...頂点u, vが連結かどうかを返す。
    - **制約**
    $0 \le u, v < n$

- **leader(int u)**...頂点uの属する連結成分の代表元を返す
    - **制約**
    $0 \le u < n$

- **size(int u)**...頂点uの属する連結成分のサイズを返す
    - **計算量**
    $O(1)$

- **groups()**...グラフを連結成分ごとに分け、その情報を返す
    - **計算量**
    $O(n)$
    - **備考**
    groupsで帰ってきた配列のサイズ = 連結成分の個数
 
- **edgecnt(int u)** ... 頂点uの属する連結成分が持つ辺の本数を返す
    - **計算量**
    $O(\alpha (n))$

- **componentcnt()** ... {0, ... , n-1}について、連結成分の個数を返す
    - **計算量**
    $O(1)$

## verify
edgecnt ... https://atcoder.jp/contests/chokudai_S002/submissions/53940535
